/******************************************************************************/
/* File Name        : 221.cpp                                                 */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : DP                                  KK  KK    BB  BB    */
/* Time Complexity  : O(M * N)                            KKKKK     BBBBB     */
/* Space Complexity : O(M * N)                            KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max_side = 0;

        // DP 테이블
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

        // 행렬을 순회하며 1번부터 채우기
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // dp에서 (i, j) == matrix의 (i-1, j-1)
                if (matrix[i - 1][j - 1] == '1') {
                    // 정사각형이 확장되기 위해서는 왼, 왼 대각선, 위가 모두 정사각형의 일부가 되어야 하므로 셋 중 최소 길이에 +1
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                } else dp[i][j] = 0;

                // 최댓값 갱신
                max_side = max(dp[i][j], max_side);
            }
        }

        // 면적 return
        return max_side * max_side;
    }
};
