/********************************************************************************/
/* File Name         : C-StrawMillionaire.cpp                                   */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : BFS                                     KK KK    BB  BB  */
/* Time Complexity   : O(N+M)                                  KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> v;
vector<bool> visited;
int num = 1; //처음 초기값


//BFS 함수 정의
void bfs(int start){
    queue<int> q;


    q.push(start); //시작 노드를 queue에 삽입
    visited[start] = true; //첫 노드를 방문 처리

    while(!q.empty()){ //큐가 소진될 때까지 반복
        //queue에서 꺼내기
        int x = q.front();
        q.pop();
        
        //해당 노드와 인접한 이웃노드 방문
        for(int i=0; i<v[x].size(); i++){
            int y = v[x][i];
            if(!visited[y]){
                num ++;
                q.push(y);
                visited[y] = true;
            }
        }
    }


}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m; //n: 아이템의 종류, m: 친구의 수
    
    v.resize(n+1);
    visited.assign(n+1, false);

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    bfs(1);

    cout << num;
}