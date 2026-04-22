/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : DP                                      KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
// time limit : 0.5sec
#include <iostream>
#include <algorithm>
using namespace std;
/*
빨강 골랐으면 이전에는 빨강 외 값 선택되야 함
dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0]
dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1]
dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2]
*/

// i번째 집까지 색을 골랐을 때, i번째 집 색에 따라 최소 비용 저장
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int color[1001][3];
    int dp[1001][3];
    int min_cost;
    for (int i = 0; i < N; i++)
    {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }

    //첫번째 집 비용 계산
    dp[0][0] = color[0][0];
    dp[0][1] = color[0][1];
    dp[0][2] = color[0][2];

    for (int i = 1; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + color[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + color[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + color[i][2];
    }
    min_cost = min(dp[N][0], min(dp[N][1], dp[N][2]));
    cout << min_cost;

    return 0;
}
