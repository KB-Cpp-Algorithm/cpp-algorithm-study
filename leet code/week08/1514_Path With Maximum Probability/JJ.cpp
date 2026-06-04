/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 다익스트라                              KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 음수 간선 있을 시, 다익스트라 불가      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int node;
    double prob;
}Data;

//prob가 큰 값이 우선순위 큐 top에 오도록 하는 비교 구조체
struct cmpData{
    //함수 호출 연산자 () 오버로딩
    bool operator()(const Data& a, const Data& b){
        return a.prob < b.prob;
    }
};

class Solution {
public:
    vector<vector<Data>> adj; //인접리스트
    vector<double> Dijk; //시작에서 각 노드까지의 최대 확률(거리)
    priority_queue<Data, vector<Data>, cmpData> pq; //다음 탐색할 노드를 고르기 위한 우선순위 큐


    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        // 인접리스트
        vector<vector<Data>> adj(n);

        // 시작 노드에서 각 노드까지 도달할 수 있는 최대 확률
        vector<double> Dijk(n, 0.0);

        // 다음 탐색할 노드를 고르기 위한 우선순위 큐
        priority_queue<Data, vector<Data>, cmpData> pq;

        // 1. 인접 리스트 생성
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double p = succProb[i];

            adj[a].push_back({b, p});
            adj[b].push_back({a, p});
        }

        // 2. 큐 초기화
        pq.push({start_node, 1});
        Dijk[start_node] = 1;

    
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> edges = {{0,1}, {1,2}, {0,2}};
    vector<vector<int>> edges2 = {{0,1}, {1,2}, {0,2}};
    vector<vector<int>> edges3 = {{0,1}};

    vector<double> succProb = {0.5, 0.5, 0.2};
    vector<double> succProb2 = {0.5, 0.5, 0.3};
    vector<double> succProb3 = {0.5};

    cout << sol.maxProbability(3, edges, succProb, 0, 2) << ' ' << sol.maxProbability(3, edges2, succProb2, 0, 2) << ' ' << sol.maxProbability(3, edges3, succProb3, 0, 2) << '\n';
}