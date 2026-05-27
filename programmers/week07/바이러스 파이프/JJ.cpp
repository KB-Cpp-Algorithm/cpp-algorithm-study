/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : DFS + BFS                               KK KK    BB  BB  */
/* Time Complexity   : O(3^K * (N + E))                        KKKKK    BBBBB   */
/* Space Complexity  : O(N + E + K * N)                        KK KK    BB  BB  */
/* Note              : 케이스당 늘어나는 3경우 모두 탐색       KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int answer = 0, K;
vector<vector<int>> adjA, adjB, adjC; //인접리스트
vector<bool> infected; //visited 배열 역할

//연결된 모든 노드를 감염. 탐색은 BFS로 진행
void spread(int pipenum, vector<bool>& infected)
{
    //파이프 선택
    vector<vector<int>> adj;
    if(pipenum == 1)
        adj = adjA;
    else if(pipenum == 2)
        adj = adjB;
    else
        adj = adjC;
    
    
    //어떤 파이프를 열었을 때, 연결된 모든 노드 감염시켜야 하므로 BFS 이용
    queue<int> q;

    //시작 지점 큐에 넣어서 감염된 모든 노드에 대해 DFS 탐색
    for(int i = 1; i < infected.size(); i++){
        if(infected[i])
            q.push(i);
    }

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        //인접리스트 방문
        for(int i = 0; i < adj[curr].size(); i++){
            //이미 방문한 노드면 스킵
            if(infected[adj[curr][i]])
                continue;

            //방문하지 않았으면 방문 처리 후 큐에 푸쉬
            infected[adj[curr][i]] = true;
            q.push(adj[curr][i]);
        }
    }
}

//재귀를 이용한 DFS 탐색. 하나의 케이스가 3개의 케이스로 분기되는데 이를 모두 탐색하며 계산함.
void dfs(vector<bool> infected, int depth)
{
    //k번 째 시행이면 끝
    if(depth == K){
        int cnt = 0;

        //감염된 노드 개수 세기
        for(int i = 1; i < infected.size(); i++){
            if(infected[i])
                cnt++;
        }

        //최대값 갱신
        answer = max(answer, cnt);
        return;
    }

    //현재 상황에서 A,B,C 파이프 열었을 때의 세 가지 경우 전부 탐색
    for(int pipenum = 1; pipenum <= 3; pipenum++){
        vector<bool> nextInfected = infected;
        //DFS를 이용하여 이번 턴 인접한 모든 노드 감염
        spread(pipenum, nextInfected);
        //가지치기로 뻗어나가야 하므로 재귀 탐색
        dfs(nextInfected, depth + 1);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    //전역변수 초기화
    answer = 0;
    adjA.clear(); adjB.clear(); adjC.clear(); infected.clear();
    K = k;
    infected.resize(n+1, false);
    adjA.resize(n+1); adjB.resize(n+1); adjC.resize(n+1);
    
    //인접리스트 생성 (A,B,C 각 파이프에 대한 인접리스트 생성)
    for(int i = 0; i < edges.size(); i++){
        
        if(edges[i][2] == 1){ //A파이프 연결
            adjA[edges[i][0]].push_back(edges[i][1]);
            adjA[edges[i][1]].push_back(edges[i][0]);
        }

        else if(edges[i][2] == 2){ //B파이프 연결
            adjB[edges[i][0]].push_back(edges[i][1]);
            adjB[edges[i][1]].push_back(edges[i][0]);
        }

        else{ //C파이프 연결
            adjC[edges[i][0]].push_back(edges[i][1]);
            adjC[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    //시작 노드 감염 되었으므로 방문 처리
    infected[infection] = true;
    dfs(infected, 0);

    return answer;
}


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> edges = {{1,2,1} , {1,3,1} , {1,4,3} , {1,5,2} , {5,6,1} , {5,7,1} , {2,8,3} , {2,9,2} , {9,10,1}};
    vector<vector<int>> edges2 = {{1,2,3} , {1,4,3} , {4,5,1} , {5,6,1} , {3,6,2} , {3,7,2}};

    cout << solution(10, 1, edges, 2) << ' ' << solution(7, 6, edges2, 3) << '\n';
}
