/********************************************************************************/
/* File Name         : 1780.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         : 분할 정복, 재귀                         KK KK    BB  BB
 */
/* Time Complexity   : O(N^2 log_3 N)                          KKKKK    BBBBB */
/* Space Complexity  : O(log_3 N) (Stack Depth)                KK KK    BB  BB
 */
/* Note              : 현재 영역이 모두 같은 숫자인지 확인하고,    KK  KK BBBBB
 */
/* 그렇지 않을 경우 9등분하여 탐색한다.                       */
/********************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int N;
int paper[2188][2188];
int result[3];  // -1, 0, 1 결과 저장

void solve(int cr, int cc, int base) {
  // 1. 현재 영역이 모두 같은 숫자인지 확인
  bool same = true;
  int first_val = paper[cr][cc];

  for (int i = cr; i < cr + base; i++) {
    for (int j = cc; j < cc + base; j++) {
      if (paper[i][j] != first_val) {
        same = false;
        break;
      }
    }
    if (!same) break;
  }

  // 2. 같다면 해당 숫자 카운트 후 종료(원소가 하나일 때도 여기에 포함)
  if (same) {
    result[first_val + 1]++;
    return;
  }

  // 3. 다르다면 9등분하여 재귀 호출
  int new_base = base / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(cr + i * new_base, cc + j * new_base, new_base);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  solve(0, 0, N);

  for (int i = 0; i < 3; i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
