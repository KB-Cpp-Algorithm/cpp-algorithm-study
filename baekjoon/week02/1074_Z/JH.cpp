/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : D F S                                   KK KK    BB  BB  */
/* Time Complexity   : N                                       KKKKK    BBBBB   */
/* Space Complexity  : N                                       KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int N, R, C, answer;

// 기준이 되는 행 번호, 열 번호, 길이
// dfs는 기준점을 변경
void dfs(const int& currentR, const int& currentC, const int& size) {
    // 목표 지점에 도착 했을 경우
    if (size == 1) return;
    // 절반 길이(기준이 되는 지점)
    int halfSize = size / 2;
    // 하나의 섹션 당 1x1 개수
    int cnt = halfSize * halfSize;

    // 2사분면
    if (R < currentR + halfSize && C < currentC + halfSize) {
        dfs(currentR, currentC, halfSize);
    }
    // 1사분면
    else if (R < currentR + halfSize && C >= currentC + halfSize) {
        // (2사분면) 1x1 총 개수
        answer += cnt;
        dfs(currentR, currentC + halfSize, halfSize);
    }
    // 3사분면
    else if (R >= halfSize + currentR && C < currentC + halfSize) {
        // (1사분면 + 2사분면) 1x1 총 개수
        answer += cnt * 2;
        dfs(currentR + halfSize, currentC, halfSize);
    }
    // 4사분면
    else {
        // (1사분면 + 2사분면 + 3사분면) 1x1 총 개수
        answer += cnt * 3;
        dfs(currentR + halfSize, currentC + halfSize, halfSize);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C;

    // (0, 0) 기준으로 길이는 pow(2, N)
    dfs(0, 0, pow(2, N));

    cout << answer << '\n';

    return 0;
}