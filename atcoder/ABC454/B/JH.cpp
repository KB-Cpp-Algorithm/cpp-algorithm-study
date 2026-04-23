/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : map                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int N, M;
string Q1 = "Yes", Q2 = "Yes";
unordered_map<int, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // N명의 사람 및 M개의 옷 입력
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int clothesNum;
        // 옷의 번호 입력
        cin >> clothesNum;
        // 해당 옷의 수량 증가
        m[clothesNum]++;
    }

    // 옷의 종류보다 사람이 많은 경우
    if (m.size() < N) {
        Q1 = "No";
    }

    for (int i = 1; i <= M; i++) {
        // 해당 번호의 옷을 입은 사람이 없을 경우
        if (m[i] == 0) {
            Q2 = "No";
            break;
        }
    }

    cout << Q1 << '\n' << Q2 << '\n';

    return 0;
}