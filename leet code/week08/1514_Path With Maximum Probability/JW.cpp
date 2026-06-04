/******************************************************************************/
/* File Name        : 1514.cpp                                                */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : Dijkstra                            KK  KK    BB  BB    */
/* Time Complexity  : O((V + E) log V)                    KKKKK     BBBBB     */
/* Space Complexity : O(V + E)                            KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    vector<double> dijkstra(int n, vector<vector<pair<int, double>>>& graph, int start) {
        // start node에서 모든 노드에 도달 가능한 최대 확률 저장
        vector<double> prob(n, 0.0); 

        // { 확률, 노드 }
        priority_queue<pair<double, int>> pq;

        // 시작 노드는 자신까지 도달 확률 100%
        prob[start] = 1;
        pq.push({1, start});
        
        while (!pq.empty()) {
            double curProb = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            // 현재 경로보다 최적 경로 존재 시 continue
            if (curProb < prob[curNode])
                continue;
    
            // 현재 노드와 연결된 모든 노드 탐색
            for (auto [nextNode, pro] : graph[curNode]) {
                // 확률 계산
                double nextProb = curProb * pro;

                // 더 높은 확률 발견 시 갱신
                if (nextProb > prob[nextNode]) {
                    prob[nextNode] = nextProb;

                    pq.push({nextProb, nextNode});
                }
            }
        }
        return prob;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);

        // 그래프 생성
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> prob = dijkstra(n, graph, start_node);

        return prob[end_node];
    }
};
