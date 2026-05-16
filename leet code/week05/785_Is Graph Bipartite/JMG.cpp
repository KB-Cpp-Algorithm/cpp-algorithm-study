/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : bfs                                     KK KK    BB  BB  */
/* Time Complexity   : O()                                     KKKKK    BBBBB   */
/* Space Complexity  : O(V)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


// graph는 이분 그래프 - 연결된 간선이 A - B 그룹 사이에만 있을 때
// 이분 그래프면 true, 아님 false
// now번 노드(a)하고 연결된 next 노드는 b그룹
// flag하면서 탐색 - bfs 사용 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // 0 - 미정, 1 - a, -1 -b 그룹
        vector<int> group(n,0);

        for(int i = 0; i < n; i++) {
            if(group[i] != 0) continue;
            // 선언 새로 계속하기
            queue<int> q;

            group[i] = 1;
            q.push(i);

            while(!q.empty()) {
                int now = q.front();
                q.pop();

                for(int next : graph[now]) {
                    // 미정이면
                    if(group[next] == 0) {
                        group[next] = - group[now];
                        q.push(next);
                    }
                    // 런타임 상위 91퍼..
                    // 리팩토링 : if -> else if
                    // -> 이미 다르게 라벨링된 애들끼리도 계속 검사하는 상황이였음 
                    else if(group[next] == group[now]) return false;
                }
            }
        }
        return true;

    }
};