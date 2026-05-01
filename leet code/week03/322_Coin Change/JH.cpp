/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : D P                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : GPT 도움 받은 풀이 방법                 KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // DP 배열 초기화
        vector<int> dp(amount + 1, amount + 1);
        // 0원을 만들 때 필요한 동전은 0개
        dp[0] = 0;
        // 1원부터 목표 금액까지 반복
        for (int i = 1; i <= amount; ++i) {
            // 각 동전별을 꺼내 확인
            for (int coin : coins) {
                // 현재 동전을 사용할 수 있을 경우
                if (i - coin >= 0) {
                    // 현재 금액에서 동전 하나를 뺀 상태의 최적해 + 1
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // 결과 반환
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};