/********************************************************************************/
/* File Name         : 14889.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         : 브루트포스, 백트래킹                    KK KK    BB  BB
 */
/* Time Complexity   : O(2^N) or O(N/2 * nCr)                  KKKKK    BBBBB */
/* Space Complexity  : O(N)                                    KK KK    BB  BB
 */
/* Note              : N명 중 N/2명을 뽑는 모든 조합을 확인하며,   KK  KK BBBBB
 */
/* 두 팀의 능력치 차이의 최솟값을 갱신한다.                    */
/********************************************************************************/
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N;
int S[21][21];
bool visited[21];
int min_diff = INT_MAX;

void dfs(int idx, int cnt) {
  // 1. 목표 인원(N/2)을 다 뽑았을 때
  if (cnt == N / 2) {
    vector<int> start_team, link_team;
    for (int i = 0; i < N; i++) {
      if (visited[i])
        start_team.push_back(i);
      else
        link_team.push_back(i);
    }
    // 2. 능력치 계산 후 차이 구하기
    int start_score = 0;
    int link_score = 0;

    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        if (i != j) {
          start_score += S[start_team[i]][start_team[j]];
          link_score += S[link_team[i]][link_team[j]];
        }
      }
    }

    // 3. 능력치 총 합이 최소가 되는 조합 찾기
    min_diff = min(min_diff, abs(start_score - link_score));

    return;
  }

  // 3. 조합 뽑기 (***i는 idx부터 시작***)
  for (int i = idx; i < N; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i + 1, cnt + 1);  // 다음 사람 선택
      visited[i] = false;   // 백트래킹
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int s;
      cin >> s;
      S[i][j] = s;
    }
  }

  dfs(0, 0);

  cout << min_diff << "\n";
}
