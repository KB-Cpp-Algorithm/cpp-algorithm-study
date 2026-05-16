/******************************************************************************/
/* File Name        : 785.cpp                                                 */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : 이분 그래프                            KK  KK    BB  BB    */
/* Time Complexity  : O(V + E)                            KKKKK     BBBBB     */
/* Space Complexity : O(V)                                KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/
class Solution {
public:
    // 노드 탐색하며 이웃에게 1이면 -1 부여, -1이면 1 부텨
    bool dfs(vector<vector<int>>& graph, int cur, vector<int>& visited) {       
        for(int next : graph[cur]) {
            // 아직 방문 전 노드라면 현재와 반대 번호 부여
            if(visited[next] == 0) {
                if(visited[cur] == 1) visited[next] = -1;
                else if(visited[cur] == -1) visited[next] = 1;
                // 실패 시 바로 false return
                if(!dfs(graph, next, visited)) return false;
            // 이미 방문한 노드인데 현재 노드와 번호가 같은 경우 false return    
            } else if(visited[next] == visited[cur]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // visited 겸 번호 부여, 방문 전 = 0, 방문 후 = 1 or -1
        vector<int> visited(graph.size(), 0);

        for(int i = 0; i<graph.size(); i++) {
            // 방문 전 노드 발견 시 시작
            if(visited[i] == 0) {
                visited[i] = 1;
                if(!dfs(graph, i, visited)) return false;
            }
            
        }
       
        return true;

    }
};
