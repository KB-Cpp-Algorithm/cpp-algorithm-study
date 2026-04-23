/********************************************************************************/
/* File Name         : 1074.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         : 분할 정복, 재귀                         KK KK    BB  BB
 */
/* Time Complexity   : O(log N)                                KKKKK    BBBBB */
/* Space Complexity  : O(log N) (Stack Depth)                  KK KK    BB  BB
 */
/* Note              : 사분면의 범위를 체크하여 불필요한 탐색을 줄이는 것이 핵심
 * KK  KK BBBBB   */
/* */
/********************************************************************************/

#include <cmath>
#include <iostream>
using namespace std;

int N, r, c;
int ans = 0;

/**
 * Divide and Conquer
 * n: 현재 정사각형 한변 길이
 * cr: 현재 사분면 시작 행
 * cc: 현재 사분면 시작 좌표
 */
void cal(int n, int cr, int cc) {
  // 1. 탈출 조건: 좌표 찾으면 출력 후 종료
  if (cr == r && cc == c) {
    cout << ans << endl;
    return;
  }

  // 현재 정사각형 한변 길이의 절반
  int half = n / 2;

  // 2. 현재 시작점에서 (r,c)가 어느 사분면에 있는가?
  if (r < cr + half && c < cc + half) {
    cal(half, cr, cc);
  } else if (r < cr + half && c >= cc + half) {
    ans += half * half;
    cal(half, cr, cc + half);
  } else if (r >= cr + half && c < cc + half) {
    ans += 2 * half * half;
    cal(half, cr + half, cc);
  } else if (r >= cr + half && c >= cc + half) {
    ans += 3 * half * half;
    cal(half, cr + half, cc + half);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> r >> c;

  cal(pow(2, N), 0, 0);
}
