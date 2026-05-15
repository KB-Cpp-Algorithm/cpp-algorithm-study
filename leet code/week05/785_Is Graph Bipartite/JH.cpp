/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : BFS, DFS, Graph                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    // 행 크기
    int N = graph.size();

    // N개의 노드
    // -1: 방문하지 않음, 0 또는 1: 그룹
    vector<int> node(N, -1);

    for (int i = 0; i < N; i++) {
        // 이미 방문한 노드일 경우
        if (node[i] != -1) continue;

        queue<int> q;
        q.push(i);
        // 처음 시작 노드는 0번 그룹에 배치
        node[i] = 0;

        while (!q.empty()) {
            // 현재 노드
            int currentNode = q.front();
            q.pop();

            // num번 노드와 연결된 노드 목록 조회
            for (const int& anotherNode : graph[currentNode]) {
                // 아직 그룹이 없을 경우
                if (node[anotherNode] == -1) {
                    q.push(anotherNode);
                    // 현재 노드와 반대 그룹에 배치
                    node[anotherNode] = node[currentNode] ^ 1;
                }
                // 같은 그룹일 경우
                else if (node[anotherNode] == node[currentNode]) {
                    // 만족하지 않음
                    return false;
                }
            }
        }
    }
    return true;
}