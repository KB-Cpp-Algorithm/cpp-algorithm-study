/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 벨만포드                                KK KK    BB  BB  */
/* Time Complexity   : O(kE)                                   KKKKK    BBBBB   */
/* Space Complexity  : O(n)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //src -> i까지의 최소 비용 저장하는 벡터
        vector<int> dist(n, INF);
        dist[src] = 0; //시작 지점

        //최대 k번 경유 가능(k+1개의 간선 사용할 수 있음)
        for(int i = 0; i < k + 1; i++){
            //dist를 바로 수정하면 한 번에 여러 간선을 타는 문제가 생김 (k 조건 깨질 수 있음)
            //temp 벡터 이용
            vector<int> temp = dist;

            //모든 항공편 확인하면서 비용 갱신
            for(int j = 0; j < flights.size(); j++){
                int from = flights[j][0]; //출발
                int to = flights[j][1]; //도착
                int price = flights[j][2];

                //from 값이 INF면 (도달 x) 갱신 불가
                if(dist[from] == INF)
                    continue;

                //기존 비용보다 더 싸면 갱신
                if(temp[to] > dist[from] + price)
                    temp[to] = dist[from] + price;
            }
            //갱신 결과를 dist에 반영
            dist = temp;
        }
        
        //dst에 도달 불가 -> -1 리턴
        if(dist[dst] == INF)
            return -1;

        return dist[dst];
    }
};

int main(void)
{
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};
    vector<vector<int>> flights2 = {{0,1,100}, {1,2,100}, {0,2,500}};
    vector<vector<int>> flights3 = {{0,1,100}, {1,2,100}, {0,2,500}};

    Solution sol;

    cout << sol.findCheapestPrice(4, flights, 0, 3, 1) <<
        ' ' << sol.findCheapestPrice(3, flights2, 0, 2, 1) << ' ' <<
        sol.findCheapestPrice(3, flights3, 0, 2, 0) << '\n';

}