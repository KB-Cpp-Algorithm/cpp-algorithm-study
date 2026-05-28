/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : D F S                                   KK KK    BB  BB  */
/* Time Complexity   : O(N^2 * N^2)                            KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 시간 초과!!!!!!!!!!!!!!!!!!!!!!!!!!!      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int max_cnt = 0;

struct Edge {
    int to;
    int pipe_type;
};

// dfs 매개변수:
// k: 최대 변경 가능 횟수, adj: 인접 리스트
// cnt: 현재까지 파이프를 바꾼 횟수, cur_pipe: 현재 활성화된 파이프 종류 (0, 1, 2)
// path: 현재까지 방문한 노드들의 리스트
// visited: 현재 경로에서의 방문 여부 체크 배열
void dfs(int root, int& k, vector<vector<Edge>>& adj, int cnt, int cur_pipe, vector<Edge>& path, vector<bool>& visited) {
    max_cnt = max(max_cnt, (int)path.size());
    
    for(int i = 0; i < adj[root].size(); i++){
        if(!visited[adj[root][i].to]){
            path.push_back(adj[root][i]);
        }
    }

    // 현재까지 방문한 모든 노드들을 순회하며, 그 노드들과 연결된 다음 갈 곳을 찾음.
    for (int i = 0; i < path.size(); i++) {
        int next_node = path[i].to;
        int edge_pipe = path[i].pipe_type;


            // 1. 상태 진행 (방문 처리 및 리스트 추가)
            visited[next_node] = true;
            vector<Edge> new_path = path;
            new_path.erase(new_path.begin() + i);

            // 2. 파이프 일치 여부에 따라 분기하여 DFS 호출
            if (edge_pipe == cur_pipe) {
                dfs(next_node, k, adj, cnt, cur_pipe, new_path, visited);
            } else {
                if(cnt < k){
                    dfs(next_node, k, adj, cnt + 1, edge_pipe, new_path, visited);
                }
            }

            // 3. 백트래킹 (다음 후보 탐색을 위해 원상복구)
            visited[next_node] = false;
        
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    max_cnt = 0;
    
    // 인접 리스트 생성
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int type = edges[i][2] - 1; // 0, 1, 2로 매핑
        
        adj[u].push_back({v, type});
        adj[v].push_back({u, type});
    }

    // 방문 리스트와 방문 체크 배열 초기화
    vector<Edge> path;
    vector<bool> visited(n + 1, false);

    // 시작점 설정
    visited[infection] = true;

    // 초기 파이프 종류(0, 1, 2)별로 각각 시뮬레이션 시작
    dfs(infection, k, adj, 1, 0, path, visited);
    dfs(infection, k, adj, 1, 1, path, visited);
    dfs(infection, k, adj, 1, 2, path, visited);

    return max_cnt;
}
