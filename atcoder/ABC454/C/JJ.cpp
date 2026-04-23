/********************************************************************************/
/* File Name         : C.cpp                                                    */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : BFS                                     KK KK    BB  BB  */
/* Time Complexity   : O(N+M)                                  KKKKK    BBBBB   */
/* Space Complexity  : O(N+M)                                  KK KK    BB  BB  */
/* Note              : 가질 수 있는 모든 경우의 수 구하기      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
아이템 종류 : N개
친구 : M명
-> BFS 사용 시, O(N + M)

Takahashi has only item 1. 시작점을 알려줌 -> 그래프 노드 방문 여부 확인 문제
*/
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, answer = 1; //N : 아이템 종류, M : 친구 수
    cin >> N >> M;

    vector<bool> visited(N + 1, false); //BFS를 위한 기록 벡터
    vector<vector<int>> adjacent(N + 1); //인접 리스트
    
    for(int i = 0; i < M; i++){ //인접 리스트 값 할당
        int A_i, B_i;
        cin >> A_i >> B_i;
        adjacent[A_i].push_back(B_i);
    }

    //BFS 시작 (1번 노드 시작) 동작 과정은 그림으로 설명 예정
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < adjacent[node].size(); i++){
            int next = adjacent[node][i];
            if(visited[next])
                continue;
            visited[next] = true;
            q.push(next);
            answer++;
        }
    }

    cout << answer << '\n';
}


/*
    for(int i = 1; i < N+1; i++){
        for(int j = 0; j < adjacent[i].size(); j++){
            cout << adjacent[i][j] << ' ';
        }
        cout << '\n';
    }

*/