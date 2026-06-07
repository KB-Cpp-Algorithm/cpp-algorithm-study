/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Topological Sort                        KK KK    BB  BB  */
/* Time Complexity   : O(V + E)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
    위상 정렬(Topological Sort)
    - DAG: Directed Acyclic Graph
    - 즉, 방향 비순환 그래프가 전재 조건
    - DFS 또는 BFS처럼 경로를 찾는 알고리즘이 아님.
    - 모든 정점을 "선행 조건에 맞게 한 줄로 배치"하는 것이 목적.
    - ex) 선수 과목, 작업 순서, 건물 짓기 순서, 문제 풀이 순서
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool answer = true;
        // 수강한 과목
        int finishedCourses = 0;
        // 수강 예정 큐
        queue<int> q;
        // 인접 리스트
        vector<int> graph[numCourses];
        // 진입 차수
        vector<int> indegree(numCourses, 0);

        // 조건: All the pairs prerequisites[i] are unique.
        // prev를 먼저 수강해야 curr를 수강할 수 있음
        for (const vector<int>& prerequisite : prerequisites) {
            // 그래프의 방향 prev -> curr
            int curr = prerequisite[0];
            int prev = prerequisite[1];
            // 인접 리스트에 저장
            graph[prev].push_back(curr);
            // to의 진입 차수 증가
            indegree[curr]++;
        }

        // 진출 차수가 0인 노드 큐에 삽입
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // 수강 완료한 과목 수 증가
            finishedCourses++;

            // 현재 과목과 연결된 다음 과목 순회
            for (const int& next : graph[curr]) {
                indegree[next]--;
                // 진출 차수가 0일 경우
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 과목 전체를 수강하지 못 했을 경우
        if (finishedCourses < numCourses) {
            answer = false;
        }

        // 정답 출력
        return answer;
    }
};