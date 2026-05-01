/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : D P                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   private:
    int getMoney(vector<int>& houses) {
        int m = houses.size();
        if (m == 0) return 0;
        if (m == 1) return houses[0];

        // dp[i]: i번째 집까지 탐색했을 때 얻을 수 있는 최대 돈
        vector<int> dp(m);

        // 초기 세팅
        // 0번 집까지 탐색 시 얻을 수 있는 최대 돈 -> 0번 집
        dp[0] = houses[0];
        // 1번 집까지 탐색 시 얻을 수 있는 최대 돈 -> 0번 집 or 1번 집
        dp[1] = max(houses[0], houses[1]);

        // i번 집을 고려한다고 가정할 경우 2-case
        // 1. 직전 집까지 털었을 때 최대 금액
        // 2. 전전 집 + 현재 집을 털었을 때 금액
        for (int i = 2; i < m; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]);
        }

        return dp[m - 1];
    }

   public:
    int rob(vector<int>& nums) {
        // 전체 집의 개수
        int n = nums.size();
        // 집이 1개일 경우, 해당 집 털기
        if (n == 1) return nums[0];
        // 집이 2개일 경우, 돈을 최대로 가질 수 있는 집 털기 
        if (n == 2) return max(nums[0], nums[1]);

        // 처음 집을 턴다고 가정할 경우, 인접한 마지막 집은 털기 제외 
        vector<int> houseFirst(nums.begin(), nums.end() - 1);
        // 마지막 집을 턴다고 가정할 경우, 인접한 처음 집은 털기 제외
        vector<int> houseLast(nums.begin() + 1, nums.end());
        // 처음 집을 털었을 때 획득할 수 있는 돈
        int moneyFirst = getMoney(houseFirst);
        // 마지막 집을 털었을 때 획득할 수 있는 돈
        int moneyLast = getMoney(houseLast);
        // 최대 돈 반환
        return max(moneyFirst, moneyLast);
    }
};