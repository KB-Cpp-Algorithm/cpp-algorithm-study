/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Bellman-Ford                            KK KK    BB  BB  */
/* Time Complexity   : O(K * E)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 고민하다 GPT의 도움!                    KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
    최단 거리를 구하는 것과 더불어 음수 가중치가 아닌 양수 가중치라서 다익스트라로 생각했다.
    하지만, 다익스트라가 아닌 벨만포드로 접근해야 하는 문제였다.
    다익스트라는 최단 거리만 추적하고, 몇 개의 간선을 거쳤는지는 관심이 없기 때문이다.

    해당 문제는 비용이 효율적이지 않아도, K번 이내로 갈 수 있을 경우만 후보가 될 수 있다.
    즉, 효율적으로 갈 수 있어도 K번 이내로 갈 수 없으면 정답이 될 수 없다.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // 무한대 상수
        const int INF = INT_MAX;
        // 최단 거리
        vector<int> dist(n, INF);

        // 출발지 설정
        dist[src] = 0;

        // 최대 K번 경유할 수 있기 때문에, 간선은 최대 K + 1번
        // ex) 출발 -> n1 -> n2 -> n3 -> n4 -> 도착. 따라서 경유 4번, 이동 간선
        // 5번
        for (int i = 1; i <= k + 1; i++) {
            // 반복을 1회 진행할 때마다, 반드시 간선 연결은 1회 진행되어야 함.
            // 만약 dist를 갱신할 경우, 한번에 잇따라 연결되는 문제가 발생할 수
            // 있음. 따라서 임시 상태에 저장할 경우, 현재까지 연결된 간선에서 딱
            // 하나의 간선만 연결이 가능해짐.
            vector<int> tempDist = dist;

            for (const auto& flight : flights) {
                // 출발지, 도착지, 비용
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                // from에서 출발할 수 없는 경우
                if (dist[from] == INF)
                    continue;

                // 최소 비용으로 갱신하지만, 저장은 tempDist만
                tempDist[to] = min(tempDist[to], dist[from] + price);
            }
            dist = tempDist;
        }

        return (dist[dst] != INF) ? dist[dst] : -1;
    }
};