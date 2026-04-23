/********************************************************************************/
/* File Name         : 1931.cc */
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

#define MAX 1500005
using namespace std;

int N;
int T[MAX], P[MAX], dp[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> P[i];
  }

  // 1일부터 퇴사 다음 날(N+1)까지
  for (int i = 1; i <= N; i++) {
    // 1. 오늘 상담을 안 하는 경우
    //  오늘까지 번 돈(dp[i])을 그대로 내일(dp[i+1])로 전달
    dp[i + 1] = max(dp[i + 1], dp[i]);

    // 2. 오늘 상담을 하는 경우
    int next_day = i + T[i];  // 상담이 끝나는 날

    if (next_day <= N + 1) {  // 퇴사 전까지 끝낼 수 있다면
      // 상담이 끝나는 날(dp[next_day])에 받을 돈을 업데이트
      dp[next_day] = max(dp[next_day], dp[i] + P[i]);
    }
  }

  // N+1에 모인 돈이 최대 수익
  cout << dp[N + 1] << "\n";

  return 0;
}
