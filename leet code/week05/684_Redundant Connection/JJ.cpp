/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : jjeong2                                 KK  KK   BBBBB   */
/* Algorithm         : union-find                              KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> depth;

    //x의 루트 노드 찾기
    int findParent(int x)
    {
        //자기가 루트라면 그대로 리턴
        if(parent[x] == x)
            return x;

        //경로 압축. x의 부모를 바로 위가 아닌 루트 노드로 설정
        return parent[x] = findParent(parent[x]);
    }

    //두 트리 합치기
    bool unionTree(int a, int b)
    {
        int rootA = findParent(a);
        int rootB = findParent(b);

        //이미 같은 부모를 가지고 있으면 사이클 발생
        if(rootA == rootB)
            return false;
        
        //깊이가 작은 트리를 큰 트리 밑에 붙이기
        if(depth[rootA] < depth[rootB])
            parent[rootA] = rootB;
        else if(depth[rootA] > depth[rootB])
            parent[rootB] = rootA;
        else{
            parent[rootB] = rootA;
            depth[rootA]++;
        }
        
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n + 1);
        depth.resize(n+1, 0);

        for(int i = 1; i <= n; i++)
            parent[i] = i;

        for(int i = 0; i < n; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            if(unionTree(a,b) == false)
                return edges[i];
        }
        return {};
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vector<vector<int>> edges2 = {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};

    vector<int> result = sol.findRedundantConnection(edges);
    vector<int> result2 = sol.findRedundantConnection(edges2);

    for(auto i : result)
        cout << i << ' ';
    cout << '\n';
    for(auto i : result2)
        cout << i << ' ';
}