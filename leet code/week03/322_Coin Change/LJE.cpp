/********************************************************************************************/
/* File Name        : LJE.cpp                                                               */
/* By               : Jieun                                              KK  KK  BBBBB      */
/* Algorithm        : DP (Bottom-Up, Unbounded Knapsack)                 KK KK   BB  BB     */
/* Time Complexity  : O(amount * N)                                      KKKKK   BBBBB      */
/* Space Complexity : O(amount)                                          KK KK   BB  BB     */
/* Note             : dp[i] = 합이 i일 때 최소 동전 수, 불가능시 -1 반환  KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // dp[i] = 지금까지 선택한 동전의 합이 i일 때, 가능한 최소 동전의 수
        vector<int> dp(amount+1, MAX);

        if(amount == 0) return 0;

        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){

                if(i >= coins[j]){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }

        if(dp[amount] == MAX) return -1;
        return dp[amount];
    }
};
