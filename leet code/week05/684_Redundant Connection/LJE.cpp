/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : Union-Find                              KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // find: 특정 원소가 속한 집합의 루트 노드 찾음
    int find(int x, vector<int>& p){
        // 값이 음수면 자신이 루트 노드임 (절댓값은 트리의 높이,랭크를 의미)
        if(p[x] < 0){
            return x;
        }
        // 경로 압축 최적화: 루트를 찾고 동시에 
        // 부모를 루트로 직접 연결하여 이후 탐색 속도를 O(1)에 가깝게 만듦
        return p[x] = find(p[x], p);
    }

    // union 연산: 두 원소가 속한 집합을 하나로 합침
    bool uni(int u, int v, vector<int>& p){
        u = find(u, p);
        v = find(v, p);

        // 루트가 같다면 이미 같은 집합에 속해 있음 -> 연결 시 사이클 발생
        if(u == v){
            return false;
        }

        // union by rank 최적화: 항상 높이가 낮은 트리를 높은 트리 밑에 붙임
        // p[u], p[v]는 음수이므로, 더 작은 값이 더 깊은 트리를 의미함
        if(p[u] > p[v]){ 
            swap(u, v); // u가 더 깊은 트리가 되도록 설정
        }
        
        // 두 트리의 높이가 같다면 합쳐진 후 높이가 1 증가함
        if(p[u] == p[v]){
            p[u]--; 
        }

        // v의 부모를 u로 설정하여 합치기
        p[v] = u;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int v_cnt = edges.size();

        // 부모 배열 -1은 각 노드가 높이 1인 트리의 루트임을 의미
        vector<int> p(v_cnt + 1, -1);

        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1]; 

            // 두 노드를 union 시도
            bool is_tree = uni(u, v, p);

            // 이미 같은 트리에 있다면 간선이 사이클을 만드는 간선임
            if(!is_tree){
                return {u, v};
            }
        }
        return {};
    }
};
