/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : bfs                                     KK KK    BB  BB  */
/* Time Complexity   : O(N⁴) //V = N*N, E = 4 * N*N            KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 방향 처리 주의                          KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sea;
vector<vector<bool>> visited;
//방문하는 칸의 행번호, 열번호 저장
vector<pair<int,int>> result;

int N;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

struct Whale{
    int r;
    int c;
    int dir;
};

bool inBound(int r, int c){
    return (r >= 0 && r < N) && (c >= 0 && c < N);
}

//BFS끝나고 다시 역추적 하기 싫어서 만든 구조체
//거리와 방향 모두 구조체에 저장하여 역추적 안 해도 마지막 방향을 알 수 있게 함
struct Cell { 
        int dist;
        int dir; 
};

Whale solve2(int r, int c, int d){
    
    vector<vector<Cell>> info(N, vector<Cell>(N, {-1, -1}));
    queue<pair<int,int>> q;

    info[r][c] = {0, -1};
    q.push({r, c});

    // 좌(3), 하(2), 우(1), 상(0) 순서로 탐색
    // 2단계에서도 방향 탐색의 우선순위를 정해줘야 정답임!!!!
    int prio[4] = {3,2,1,0};

    while(!q.empty()){
        auto [cr, cc] = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int dir = prio[i];  // 좌->하->우->상
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];
            if(inBound(nr, nc) && info[nr][nc].dist < 0 && sea[nr][nc] == 0){
                info[nr][nc].dist = info[cr][cc].dist + 1;
                info[nr][nc].dir  = dir;
                q.push({nr, nc});
            }
        }
    }

    // BFS 끝난 후 최적 후보 선택
    int min_dist = INT_MAX;
    Whale best = {-1, -1, -1};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            //실제로 방문한 적 없음, dist가 양수(암초거나, 갈 수 없거나)
            if(!visited[i][j]&& info[i][j].dist > 0){
                int dist = info[i][j].dist;

                if(dist < min_dist ||
                  (dist == min_dist && i < best.r) ||
                  (dist == min_dist && i == best.r && j < best.c)){
                    best = {i, j, info[i][j].dir};
                    min_dist = dist;
                }
            }
        }
    }

    return best;
}

void solve(int r, int c, int d) {

    //1. 단계
    visited[r][c] = true;
    result.push_back({r, c});

    while (true) {
        // 1단계: 우선순위대로 미방문 인접 바다 탐색
        // 우선순위: 현재(d), 좌회전(d-1), 우회전(d+1), 180도(d+2)
        int try_dirs[4] = {
            d,
            (d + 3) % 4,
            (d + 1) % 4,
            (d + 2) % 4
        };

        bool moved = false;
        for(int i = 0; i < 4; i++){
            int nd = try_dirs[i];
            int nr = r + dr[nd];
            int nc = c + dc[nd];

            if(inBound(nr, nc) && sea[nr][nc] == 0 && !visited[nr][nc]){
                d = nd;
                r = nr;
                c = nc;
                visited[r][c] = true;
                result.push_back({r,c});
                moved = true;
                break;
            }
        }

        if(moved) continue;

        //2단계 시작- bfs돌려서 현재 상황에서 갈 수 있는(암초가 아니고, 첫번째 visited에서 방문한 적이 없는 칸인
        //최소 거리의 칸
        Whale next = solve2(r, c, d);,
        if(next.r == -1) break;
        r = next.r;
        c = next.c;
        d = next.dir;
        visited[r][c] = true;
        result.push_back({r, c});
    }
}

int main() {
    int r, c, d;
    cin >> N >> r >> c >> d;

    //1-based -> 0-based
    r--;
    c--;

    //방향 보정
    if(d == 1){
        d = 0;
    }else if(d == 2){
        d = 2;
    }else if(d == 3){
        d = 3;
    }else if(d == 4){
        d = 1;
    }

    sea.assign(N, vector<int>(N));
    visited.assign(N, vector<bool>(N,false));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            sea[i][j] = x;
        }
    }

    solve(r,c,d);

    for(auto r: result){
        //출력할 때는 1-based index로 다시 보정해줘야한다
      cout << r.first+1 << " " << r.second+1 << "\n";
    }

    return 0;
}
