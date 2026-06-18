/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 시뮬레이션                              KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

/*
1. 주변 4칸 중 우선순위대로 이동
    1. 직진
    2. 반시계 90 회전 후 직진
    3. 시계 90 회전 후 직진
    4. 180 회전 후 직진
2. 주변 4칸 중 이동할 곳이 없으면 BFS로 가장 가까운 not visited한 칸 찾기
    1. 거리 짧은 칸
    2. 행 작은 칸
    3. 열 작은 칸
*/


int N,R,C,D;
int m[53][53];
bool visited[53][53];
//상하좌우 순: 0 = 상, 1 = 하, 2 = 좌, 3 = 우
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

struct Node{
    int r;
    int c;
    int dist;
    int dir;
};


bool check();
void simulate();
Node BFS(int R, int C);
void resetTestMap();
void runCheckTest(string name, int startR, int startC, int startD);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C >> D;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> m[i][j];
        }
    }


    /*
    N = 5;

    //방향 번호: 0 = 상, 1 = 하, 2 = 좌, 3 = 우
    runCheckTest("직진 가능", 3, 3, 0);
    runCheckTest("직진 막힘, 반시계 이동", 3, 3, 0);
    runCheckTest("직진/반시계 막힘, 시계 이동", 3, 3, 0);
    runCheckTest("직진/반시계/시계 막힘, 180도 이동", 3, 3, 0);
    runCheckTest("4방향 모두 막힘", 3, 3, 0);
    */
    
}


void simulate()
{
    visited[R][C] = true;
    cout << R << ' ' << C << '\n';

    for(int i = 0; i < N*N; i++){
        //주변 칸 탐색. 있으면 true 반환. 없으면 false 반환.
        bool moved = check();

        //이동했으면 출력
        if(moved){
            cout << R << ' ' << C << '\n';
            continue;
        }

        //주변 4칸 이동할 곳 없으므로 BFS 탐색.
        Node next = BFS(R, C);

        //더 이상 갈 곳 없으면 종료, if문 내부는 아직 생각 안해봄
        //if(next.r)
            //break;
        
        
        R = next.r;
        C = next.c;
        D = next.dir;

        //방문 처리 후, 이동 노드 출력 
        visited[R][C] = true;
        cout << R << ' ' << C << '\n';
    }
}

Node BFS(int R, int C)
{
    bool bfsVisited[53][53] = {false, };
    queue<Node> q;

    q.push({R, C, 0, D});

}


/*
    주변 4칸 중 우선순위대로 이동
    1. 직진
    2. 반시계 90 회전 후 직진
    3. 시계 90 회전 후 직진
    4. 180 회전 후 직진
*/
bool check()
{
    /*
    [x][y] : 현재 x를 바라보고 있을 때, 어느 방향이 우선인지
    x -> 0 : 상
     1 : 하
     2 : 좌
     3 : 우

    y -> 인덱스 [0], [1], [2], [3]은 우선순위
     값 0 : 상
        1 : 하
        2 : 좌
        3 : 우
    */
    int nextDir[4][4] = {
        {0, 2, 3, 1},
        {1, 3, 2, 0}, 
        {2, 1, 0, 3}, 
        {3, 0, 1, 2}};


    for(int i = 0; i < 4; i++){
        int dir = nextDir[D][i];
        int nr = R + dr[dir];
        int nc = C + dc[dir];

        //범위를 검증
        if(nr < 1 || nr > N || nc < 1 || nc > N)
            continue;

        //바위이거나 이미 방문한 바다면 이동 x
        if(m[nr][nc] == 1 || visited[nr][nc] == true)
            continue;

        //이동 가능하면 현재 위치, 방향, 방문 여부 갱신
        R = nr;
        C = nc;
        D = dir;
        visited[R][C] = true;

        return true;
    }

    //주변 4칸 중 이동 가능한 곳이 없으면
    return false;
}



//////////////////////////////////////////


/*
check함수 test code

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

 
    N = 5;

    //방향 번호: 0 = 상, 1 = 하, 2 = 좌, 3 = 우
    runCheckTest("직진 가능", 3, 3, 0);
    runCheckTest("직진 막힘, 반시계 이동", 3, 3, 0);
    runCheckTest("직진/반시계 막힘, 시계 이동", 3, 3, 0);
    runCheckTest("직진/반시계/시계 막힘, 180도 이동", 3, 3, 0);
    runCheckTest("4방향 모두 막힘", 3, 3, 0);
}

void resetTestMap()
{
    memset(m, 0, sizeof(m));
    memset(visited, 0, sizeof(visited));
}

void runCheckTest(string name, int startR, int startC, int startD)
{
    resetTestMap();

    R = startR;
    C = startC;
    D = startD;
    visited[R][C] = true;

    if(name == "직진 막힘, 반시계 이동"){
        m[R - 1][C] = 1; //상 막기
    }
    else if(name == "직진/반시계 막힘, 시계 이동"){
        m[R - 1][C] = 1; //상 막기
        m[R][C - 1] = 1; //좌 막기
    }
    else if(name == "직진/반시계/시계 막힘, 180도 이동"){
        m[R - 1][C] = 1; //상 막기
        m[R][C - 1] = 1; //좌 막기
        m[R][C + 1] = 1; //우 막기
    }
    else if(name == "4방향 모두 막힘"){
        m[R - 1][C] = 1; //상 막기
        m[R][C - 1] = 1; //좌 막기
        m[R][C + 1] = 1; //우 막기
        m[R + 1][C] = 1; //하 막기
    }

    bool moved = check();

    cout << name << '\n';
    cout << "moved: " << moved << '\n';
    cout << "R C D: " << R << ' ' << C << ' ' << D << "\n\n";
}
*/