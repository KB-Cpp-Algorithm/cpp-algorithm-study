/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : dijkstra                                KK KK    BB  BB  */
/* Time Complexity   : O((V+E)logV)                            KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 확률값 세팅 주의                            KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include<iostream>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        //인접 리스트
        //성공확률, 노드번호
        vector<pair<double,int>> adj[10000];
        
        //1. adj 설정
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({prob, v});
            adj[v].push_back({prob, u});
        }

        //2. 우선순위 큐 설정
        priority_queue<pair<double,int>> pq;

        //회대 확률 리스트
        vector<double> p(10000, 0);

        //3. 시작점 설정
        p[start_node] = 1.0;
        pq.push({1, start_node});

        //4. 다익스트라
        while(!pq.empty()){
            
            auto cur = pq.top();
            pq.pop();

            //최대확률 리스트와 값이 다르면 continue
            if(cur.first!= p[cur.second]) continue;

            //같으면 인접 리스트를 돌면서 p와 pq에 반영
            for(auto nxt : adj[cur.second]){
                // 현재 노드(cur)에서 다음 노드(nxt)로 갈 때의 확률이 최대확률 리스트에 저장된 확률보다 작거나 같으면 건너뜀
                if(p[nxt.second] >= p[cur.second] * nxt.first) continue;
                p[nxt.second] = p[cur.second] * nxt.first;
                pq.push({p[nxt.second], nxt.second});
            }
        }
        return p[end_node];
    }
};