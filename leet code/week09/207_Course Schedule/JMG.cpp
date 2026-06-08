/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : topological sort                        KK KK    BB  BB  */
/* Time Complexity   : O(numCourses + m)                       KKKKK    BBBBB   */
/* Space Complexity  : O(numCourses)                           KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;


// numCourses개의 코스(노드) 존재
// prerequisites[i] = [ai, bi]가 있으면 ai를 수강하려면 bi가 선행되어야 함.
// 사이클 존재하는지 여부 반환 문제!
class Solution {
public:

    vector<int> topologicalSort(int node_num, vector<vector<int>>& graph, vector<int>& indegree) {
        queue<int> q;
        vector<int> result;

        // 진입차수 없는 노드들 q에 넣기
        for(int i = 0; i < node_num; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();

            result.push_back(now);
            for(int next : graph[now]) {
                indegree[next]--;

                // next에 진입차수가 0이면 q에 추가
                if(indegree[next] == 0) {
                    q.push(next);
                }

            }
        }
        return result;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 간선 개수
        int m = prerequisites.size();
        
        vector<vector<int>> graph(numCourses+1);
        vector<int> indegree(numCourses+1,0);

        for(int i = 0; i < m; i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            
            // 역방향
            graph[b].push_back(a);
            // 노드 별 진입차수 카운팅
            indegree[a]++;
        }
        // 위상정렬 순으로 처리된 노드들
        vector<int> result = topologicalSort(numCourses,graph,indegree);

        // result 사이즈가 노드 개수보다 적으면 사이클 존재해서 false 반환
        if(result.size() < numCourses) return false;
        else return true;


    }
};









// ############### 위상정렬 공부 ###############
// 위상정렬 : DAG(Directed Acyclic Graph)에서 노드들을 선후 관계에 맞게 나열하는 방법
// 사이클이 존재하는 경우 위상정렬 불가능
// 하단 템플릿 코드
/*
    N : 정점(노드) 개수
    graph : 인접 리스트

    예)
    1 -> 2
    1 -> 3

    graph[1] = {2, 3}
    graph[2] = {}
    graph[3] = {}

    indegree[i] :
    i번 노드로 들어오는 간선의 개수

    예)
    1 -> 2
    1 -> 3
    2 -> 4
    3 -> 4

    indegree[1] = 0
    indegree[2] = 1
    indegree[3] = 1
    indegree[4] = 2
*/
vector<int> topologicalSort(
    int N,
    vector<vector<int>>& graph,
    vector<int>& indegree
) {
    queue<int> q;

    /*
        위상정렬 결과 저장

        예)
        1 2 3 4
    */
    vector<int> result;

    /*
        시작 노드 찾기

        indegree == 0
        = 나보다 먼저 와야 하는 노드가 없음
        = 지금 바로 처리 가능
    */
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    /*
        BFS처럼 진행
    */
    while (!q.empty()) {

        int now = q.front();
        q.pop();

        /*
            현재 노드 순서 확정
        */
        result.push_back(now);

        /*
            now와 연결된 다음 노드들 확인
        */
        for (int next : graph[now]) {

            /*
                now 제거 효과

                now -> next 간선을 제거했다고 생각

                따라서 next의 진입차수 감소
            */
            indegree[next]--;

            /*
                진입차수가 0이 되면

                이제 next보다 먼저 와야 하는
                노드가 없다는 뜻

                처리 가능
            */
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return result;
}

int main() {

    /*
        N : 노드 개수
        M : 간선 개수
    */
    int N, M;
    cin >> N >> M;

    /*
        graph[i]

        i번 노드에서 갈 수 있는 노드들 저장

        N+1인 이유:
        보통 문제에서 노드를 1번부터 사용
    */
    vector<vector<int>> graph(N + 1);

    /*
        indegree[i]

        i번 노드로 들어오는 간선 수
    */
    vector<int> indegree(N + 1, 0);

    /*
        간선 입력

        a b 입력 시

        a -> b
    */
    for (int i = 0; i < M; i++) {

        int a, b;
        cin >> a >> b;

        /*
            인접리스트 생성

            a에서 b로 이동 가능
        */
        graph[a].push_back(b);

        /*
            b로 들어오는 간선 하나 증가
        */
        indegree[b]++;
    }

    vector<int> result =
        topologicalSort(N, graph, indegree);

    /*
        사이클 검사

        정상적인 DAG라면
        모든 노드를 방문 가능

        결과 개수가 N보다 작으면
        사이클 존재
    */
    if (result.size() != N) {
        cout << "Cycle Exists\n";
        return 0;
    }

    /*
        위상정렬 결과 출력
    */
    for (int node : result) {
        cout << node << ' ';
    }

    return 0;
}