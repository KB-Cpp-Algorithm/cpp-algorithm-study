/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
정수 배열 coins, 정수 amount 존재
amount 만드는 최소한의 동전 조합 동전 개수 구하기
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       //dp[i][j] : i번째 coin까지 써서 j원을 만드는 동전 최소 개수
       //vector<vector<int>> dp(n+1, vector<int>(amount+1,INT_MAX)); <- runtime error
       int never = amount + 1;
       // 모든 값을 never로 초기화
       vector<vector<int>> dp(n+1, vector<int>(amount+1,never));
       // 0원 만드는 경우들 초기화
       for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
       }

        for (int i = 1; i <= n; i++) {
            int coin = coins[i - 1];

            for (int j = 1; j <= amount; j++) {
                // 1. 현재 coin을 사용하지 않는 경우
                dp[i][j] = dp[i - 1][j];

                // 2. 현재 coin을 사용할 수 있는 경우
                if (j >= coin) {
                    // 같은 coin을 여러 번 사용할 수 있으니까 dp[i][j - coin] 사용
                    dp[i][j] = min(dp[i][j], dp[i][j - coin] + 1);
                }
            }
        }     
          

        if (dp[n][amount] == never) {
            return -1;
        }

        return dp[n][amount];
    }           
};