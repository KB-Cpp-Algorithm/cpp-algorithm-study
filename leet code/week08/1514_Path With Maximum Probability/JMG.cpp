/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : dfs..                                   KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 시간 초과 11/21                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>
// 다익이 아니라 dfs로 풀이해서
class Solution {
public:
    double answer = 0.0;
    int end_node;

    vector<vector<pair<int,double>>> graph;
    vector<bool> visited;

    void dfs(int now, double curProb) {
        // 목적지 도착
        if(now == end_node) {
            answer = max(answer, curProb);
            return;
        }

        for(auto nextInfo : graph[now]) {
            int next = nextInfo.first;
            double p = nextInfo.second;

            // 이미 방문한 노드는 스킵
            if(visited[next]) continue;

            visited[next] = true;
            dfs(next, curProb * p);
            visited[next] = false;
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        answer = 0.0;
        this->end_node = end_node;

        // 인접리스트 만들기 + 확률 저장
        graph.resize(n);
        visited.resize(n, false);

        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double c = succProb[i];

            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }

        // 시작 노드 방문 처리
        visited[start_node] = true;

        // 시작 확률은 1.0
        dfs(start_node, 1.0);

        return answer;
    }
};