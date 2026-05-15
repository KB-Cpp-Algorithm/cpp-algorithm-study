/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 이분그래프 및 BFS                       KK KK    BB  BB  */
/* Time Complexity   : O(V+E)                                  KKKKK    BBBBB   */
/* Space Complexity  : O(V+E)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        //-1: 방문하지 않음 0,1 : 색
        vector<int> color(size, -1);

        //인접 리스트 생성
        vector<vector<int>> adj(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        //BFS탐색. 시작노드: 0 및 색도 0으로 색칠
        //비연결 그래프가 있을 수 있으므로 모든 노드에 대해 검사 수행
        for(int start = 0; start < size; start++){

            //이전에 BFS를 수행하며 방문한 노드면 스킵
            if(color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while(!q.empty()){
                int curr = q.front();
                q.pop();

                //인접리스트 탐색하며 인접 노드 큐에 넣기
                for(auto next : adj[curr]){
                    //아직 방문 안했으면
                    if(color[next] == -1){
                        //큐에 푸쉬
                        q.push(next);
                        //현재 노드와 반대되는 색으로 다음 노드 칠하기
                        if(color[curr] == 0)
                            color[next] = 1;
                        else
                            color[next] = 0;
                    }
                    //color[curr]은 -1일 수 없음
                    //즉, 아래의 조건을 만족했다는 것은 이미 방문했다는 의미
                    else if(color[curr] == color[next]){    
                        return false;
                    } 
                }
            }
        }
        //탐색 끝나서 탈출 했으면 인접한 노드끼리 색이 다른 이분그래프
        return true; 
    }
};

int main(void)
{
  Solution sol;
  
  vector<vector<int>> graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
  vector<vector<int>> graph2 = {{1,3}, {0,2}, {1,3}, {0,2}};

  cout << sol.isBipartite(graph) << '\n';
  cout << sol.isBipartite(graph2) << '\n';
}