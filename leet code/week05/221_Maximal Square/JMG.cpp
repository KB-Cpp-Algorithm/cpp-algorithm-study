/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 구간합                                  KK KK    BB  BB  */
/* Time Complexity   : O( m x n x (m or n) )                   KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 시간복잡도 상위 95%...ㅎ                KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int answer = 0;
        // 누적합 2차원 배열
        vector<vector<int>> t_sum( m+1 , vector<int>(n+1,0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // char -> int 형 변환
                // 좌,상단 빈 배열 유지
                t_sum[i][j] = (matrix[i-1][j-1] - '0')
                + t_sum[i-1][j] + t_sum[i][j-1]
                - t_sum[i-1][j-1];
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') continue;
                // 1 발견
                for(int k = 1; i+k <= m && j + k <= n; k++) {
                    // 구간합
                    int temp_area = 
                    t_sum[i+k][j+k] - t_sum[i+k][j] - t_sum[i][j+k] + t_sum[i][j];

                    if(temp_area == k*k) {
                        answer = max(answer, temp_area);
                    }
                    else break;
                }
            }
        }
        return answer;
    }
};