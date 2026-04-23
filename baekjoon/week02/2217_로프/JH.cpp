/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : 그리디                                  KK KK    BB  BB  */
/* Time Complexity   : N * l o g N                             KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 1시간 이내 구현                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int N, answer = INT_MIN;
vector<int> ropes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 전체 로프 수
    cin >> N;

    // 로프 벡터 리사이즈
    ropes.resize(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> ropes[i];
    }

    // 로프를 내림차순으로 정렬
    sort(ropes.begin(), ropes.end(), greater<int>());

    // 버틸 수 있는 중량이 가장 작은 로프를 기준으로 할 경우,
    // 나머지 로프들도 당연히 해당 무게를 버틸 수 있음
    // 따라서 (가장 작은 로프의 무게 * 현재까지 로프의 개수)가 최대 중량
    for (int i = 0; i < N; i++) {
        answer = max(answer, ropes[i] * (i + 1));
    }

    // 정답 출력
    cout << answer << '\n';

    return 0;
}