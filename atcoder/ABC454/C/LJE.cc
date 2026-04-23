/********************************************************************************/
/* File Name         : C.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         : BFS                                     KK KK    BB  BB
 */
/* Time Complexity   : O(V + E)                                KKKKK    BBBBB */
/* Space Complexity  : O(V + E)                                KK KK    BB  BB
 */
/* Note              : 인접 리스트와 큐를 이용한 bfs.            KK  KK   BBBBB
 */
/* 시작 노드로부터 도달 가능한 모든 정점의 수를 카운트      */
/********************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int M;

vector<int> adj[300001];
bool visited[300001];
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  // 1. 인접 리스트 초기화
  for (int i = 0; i < M; i++) {
    int a;
    int b;

    cin >> a >> b;

    adj[a].push_back(b);
  }

  // 2. 시작점 설정
  q.push(1);
  int cnt = 1;
  visited[1] = true;

  // 3. queue가 빌 때까지 반복 탐색
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    // 갈 수 있는 모든 방향 탐색
    for (int next : adj[cur]) {
      // 방문하지 않았다면
      if (visited[next] == false) {
        q.push(next);
        cnt++;
        visited[next] = true;
      }
    }
  }

  // 4. 결과 출력하기
  cout << cnt << "\n";
}
