/********************************************************************************/
/* File Name         : 1149.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         :                                         KK KK    BB  BB
 */
/* Time Complexity   :                                         KKKKK    BBBBB */
/* Space Complexity  :                                         KK KK    BB  BB
 */
/* Note              :                                         KK  KK   BBBBB */
/*                                                                              */
/********************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> rgb;
int dp[1001][3];  // 2차원 DP 테이블

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int r, g, b;
    cin >> r >> g >> b;
    rgb.push_back({r, g, b});
  }

  // 1. Base Case: 첫 번째 집은 그냥 그 집의 색칠 비용 자체가 최소비용
  dp[0][0] = rgb[0][0];
  dp[0][1] = rgb[0][1];
  dp[0][2] = rgb[0][2];

  // 2. DP 테이블 채우기 (2번째 집부터 N번째 집까지)
  for (int i = 1; i < N; i++) {
    // i번째를 빨강으로 칠할 때: 이전 집은 초록 or 파랑 중 최소값 선택
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];

    // i번째를 초록으로 칠할 때: 이전 집은 빨강 or 파랑 중 최소값 선택
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];

    // i번째를 파랑으로 칠할 때: 이전 집은 빨강 or 초록 중 최소값 선택
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
  }

  // 3. 마지막(N-1번째) 집의 세 가지 경우 중 가장 작은 값이 정답
  int ans = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
  cout << ans << "\n";

  return 0;
}
