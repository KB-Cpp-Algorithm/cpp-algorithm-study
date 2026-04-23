/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : BFS, Adjacency List                     KK KK    BB  BB  */
/* Time Complexity   : O(N + M)                                KKKKK    BBBBB   */
/* Space Complexity  : O(N + M)                                KK KK    BB  BB  */
/* Note              : 단방향 인접리스트                       KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int N, M, answer;
vector<int> adj[300005];
vector<bool> visited(300005);
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 아이템의 수 및 친구의 수 입력
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        // 인접리스트에 저장
        // from 아이템은 to 아이템을 저장)
        adj[from].push_back(to);
    }

    // 1번 아이템부터 시작
    q.push(1);
    visited[1] = true;
    answer = 1;

    // BFS 탐색
    while (!q.empty()) {
        int item = q.front();
        q.pop();

        for (const auto& itemNum : adj[item]) {
            // 이미 방문했을 경우
            if (visited[itemNum]) continue;
            // 다음 탐색 아이템 저장
            q.push(itemNum);
            visited[itemNum] = true;
            // 카운트 증가
            answer++;
        }
    }

    // 정답 출력
    cout << answer << '\n';

    return 0;
}