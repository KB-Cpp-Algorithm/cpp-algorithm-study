/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun.                                  KK  KK   BBBBB   */
/* Algorithm         : bellman ford                            KK KK    BB  BB  */
/* Time Complexity   : O(V * E)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 다익스트라로 도전해봤는데 실패..                KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
/*
다익스트라 - 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드 선택 (O((V+E)logV))
벨만포드 - 매번 모든 간선을 전부 확인(O(V*E))

- 벨만포드 알고리즘은 음의 간선이 포함된 상황에서도 사용 가능하고, 음수 간선의 순환을 감지할 수 있음
- 음수 간선이 없다고 해서 무조건 다익스트라가 아니라, 이 문제와 같이 특정한 조건에 따라 밸만포드 알고리즘을 사용
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //1. 최소 거리 벡터
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        //**주의할 부분1**
        //k번 경유하는 거니까 출발지는 포함 x
        //따라서 k+1번 반복해야함
        for(int i = 0; i <= k; i++){
            
            //**주의할 부분2**
            //한번순회할 때 하나의 간선만 연결되어야 하기 때문에 임시 배열 사용
            vector<int> tmp = dist;
            for(const auto& flight: flights){
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if(dist[from] != INT_MAX && tmp[to] > dist[from] + price){
                    tmp[to] = dist[from] + price;
                }
            }

            //업데이트
            dist = tmp;
        }

        //예외처리
        return dist[dst] == INT_MAX? -1: dist[dst];
    }
};
