/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        //정점의 모든 비용을 최댓값(INF)로 설정
        vector<int> prices(n, INF);

        prices[src] = 0;

        for(int i=0; i<=k; i++){
            //현재를 결과를 임시 저장
            vector<int> tempPrices = prices;

            for(const auto& flight: flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                //시작점에서 u까지 가는 경로가 존재하고
                //기존 비용보다 적다면 갱신!
                if(prices[u] != INF && prices[u] + price < tempPrices[v]){
                    tempPrices[v] = prices[u] + price;
                }
            }

            prices = tempPrices;
        }

        if(prices[dst] == INF) return -1;

        return prices[dst];
    }
};
