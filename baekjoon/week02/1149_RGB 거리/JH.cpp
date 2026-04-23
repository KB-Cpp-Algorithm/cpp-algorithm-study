/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : DP                                      KK KK    BB  BB  */
/* Time Complexity   : N                                       KKKKK    BBBBB   */
/* Space Complexity  : N                                       KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
/*
    - N 번째 집까지 칠하는 비용은 N - 1 번째 집까지 칠하는 비용에 따라 정해진다.
    - DP -> 점화식 설정
*/
#include <bits/stdc++.h>

using namespace std;

int N, R, G, B;
int arr[1005][3], DP[1005][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 집의 수 입력
    cin >> N;

    for (int i = 1; i <= N; i++) {
        // 빨강, 초록, 파랑 칠하는 비용 입력
        cin >> R >> G >> B;
        // i번 집을 해당 색상으로 칠하는 비용을 저장
        arr[i][0] = R, arr[i][1] = G, arr[i][2] = B;
    }

    // 첫 번째 집을 빨강으로 칠할 때 누적 비용 저장
    DP[1][0] = arr[1][0];
    // 첫 번째 집을 초록으로 칠할 때 누적 비용 저장
    DP[1][1] = arr[1][1];
    // 첫 번째 집을 파랑으로 칠할 때 누적 비용 저장
    DP[1][2] = arr[1][2];

    // 두 번째 집부터 시작
    for (int i = 2; i <= N; i++) {
        // 빨강을 칠하고 싶을 때, 초록과 파랑의 누적된 비용 중 최소를 선택
        DP[i][0] = arr[i][0] + min(DP[i - 1][1], DP[i - 1][2]);
        // 초록을 칠하고 싶을 때, 빨강과 파랑의 누적된 비용 중 최소를 선택
        DP[i][1] = arr[i][1] + min(DP[i - 1][0], DP[i - 1][2]);
        // 파랑을 칠하고 싶을 때, 빨강과 초록의 누적된 비용 중 최소를 선택
        DP[i][2] = arr[i][2] + min(DP[i - 1][0], DP[i - 1][1]);
    }

    // N 번째 집까지 모두 칠했을 때, 칠하는 비용이 가장 적은 것 출력
    cout << min(DP[N][0], min(DP[N][1], DP[N][2])) << '\n';

    return 0;
}