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












// ###########다익스트라 알고리즘 공부###########
// 정석 구현 템플릿


// INF: 아직 도달하지 못한 노드의 거리를 매우 큰 값으로 표시
const int INF = INT_MAX;

/*
    dijkstra 함수

    n     : 노드 개수
    start : 시작 노드
    graph : 인접 리스트

    graph[now] 안에는
    {next, cost} 형태로 저장됨

    예)
    1 -> 2 비용 3
    1 -> 3 비용 5

    graph[1] = {{2, 3}, {3, 5}}
*/
vector<int> dijkstra(
    int n,
    int start,
    vector<vector<pair<int, int>>>& graph
) {
    /*
        dist[i]:
        start 노드에서 i번 노드까지의 현재까지 알려진 최단거리
    */
    vector<int> dist(n + 1, INF);

    /*
        priority_queue 기본은 큰 값이 먼저 나오는 max heap

        다익스트라는 "거리 짧은 노드"부터 꺼내야 하므로
        greater<pair<int, int>> 사용해서 min heap으로 만듦

        pq에 저장되는 형태:
        {현재까지 거리, 현재 노드}
    */
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    /*
        시작 노드 초기화

        start에서 start까지 거리는 0
    */
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        /*
            현재 가장 거리가 짧은 후보 꺼내기
        */
        int current_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        /*
            이미 더 짧은 거리로 갱신된 적이 있다면 무시

            예)
            pq에는 {10, 3}이 들어있었는데
            나중에 dist[3]이 5로 갱신된 경우

            {10, 3}은 낡은 정보이므로 버림
        */
        if (current_dist > dist[now]) {
            continue;
        }

        /*
            now에서 갈 수 있는 모든 노드 확인
        */
        for (pair<int, int> edge : graph[now]) {
            int next = edge.first;
            int cost = edge.second;

            /*
                start -> now 거리 + now -> next 비용

                즉, now를 거쳐서 next로 가는 거리
            */
            int next_dist = current_dist + cost;

            /*
                기존에 알고 있던 next까지의 거리보다
                now를 거쳐 가는 게 더 짧다면 갱신
            */
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }

    return dist;
}

int main() {
    /*
        N : 노드 개수
        M : 간선 개수
        start : 시작 노드
    */
    int N, M, start;
    cin >> N >> M >> start;

    /*
        graph[i]:
        i번 노드에서 갈 수 있는 노드들 저장

        pair<int, int> 의미:
        {도착 노드, 비용}
    */
    vector<vector<pair<int, int>>> graph(N + 1);

    /*
        간선 입력

        a b c:
        a번 노드에서 b번 노드로 가는 비용이 c
    */
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        /*
            방향 그래프 기준

            a -> b, 비용 c
        */
        graph[a].push_back({b, c});

        /*
            만약 무방향 그래프라면 아래도 추가

            graph[b].push_back({a, c});
        */
    }

    vector<int> dist = dijkstra(N, start, graph);

    /*
        결과 출력
    */
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}