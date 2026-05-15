/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Dynamic Programming                     KK KK    BB  BB  */
/* Time Complexity   : O(N * M)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : Bottom-Up                               KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int length = 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // 현재 좌표가 1일 경우
                if (matrix[i][j] == '1') {
                    // 사이드
                    if (i == 0 || j == 0) {
                        // 사이즈 1의 정사각형을 만들 수 있음
                        dp[i][j] = 1;
                    } else {
                        // 좌상단, 좌, 상
                        // 3개의 기준 좌표가 만들 수 있는 정사각형 크기 중 최소
                        // 너비를 가지는 사각형
                        dp[i][j] = min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1])) +
                                   1;
                    }
                }
                // 너비 최댓값 갱신
                length = max(length, dp[i][j]);
            }
        }

        // 넓이 계산
        return length * length;
    }
};