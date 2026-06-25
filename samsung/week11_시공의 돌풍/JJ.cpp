/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : jjeong2                                 KK  KK   BBBBB   */
/* Algorithm         : 시뮬레이션                              KK KK    BB  BB  */
/* Time Complexity   : O(T*R*C)                                KKKKK    BBBBB   */
/* Space Complexity  : O(R*C)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int R, C, Time;
vector<vector<int>> Map;
vector<pair<int, int>> tornado;

//상하좌우 방향 벡터
vector<int> dr = {-1, 1, 0, 0};
vector<int> dc = {0, 0, -1, 1};


int solve(int r, int c, int time, const vector<vector<int>> input);
void spread();
void move();

int main(void)
{
    //초기화
    cin >> R >> C >> Time;
    Map.assign(R + 1, vector<int>(C + 1, 0));
    tornado.clear();
    
    vector<vector<int>> input(R, vector<int>(C));

    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            cin >> input[r][c];
        
    cout << solve(R, C, Time, input) << '\n';
    /*
    vector<vector<int>> input = {
        {10, 15, 17, 4, 50, 10, 16},
        {30, 16, 2, 4, 15, 21, 27},
        {-1, 11, 31, 51, 1, 22, 47},
        {-1, 34, 15, 21, 61, 15, 21},
        {31, 15, 20, 13, 41, 43, 4},
        {31, 12, 15, 20, 15, 20, 14}};
    cout << solve(6, 7, 1, input) << '\n';*/
}

// !!! : 모든 먼지가 확산이 끝나야 칸에 더해지게 되므로 바로 값을 수정하지 말고 temp에 넣고 한 번에 push한다
//temp를 쓰지 않으면 다른 칸 계산을 할 때 반영된 새로운 값이 영향을 주게 됨
//상화좌우 주변을 살피면서 temp에 5를 나눈 몫을 저장 후 Map에서 나눠준 만큼 빼주기. 이후 Map와 temp를 통합한다
void spread()
{
    vector<vector<int>> temp(R+1, vector<int>(C+1, 0));
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(Map[i][j] > 0){
                //주변 칸에 나눠줄 양
                int quota = Map[i][j] / 5;
                int cnt = 0;

                //주변 탐색 후 temp 배열에 나눠준 양 갱신
                for (int d = 0; d < 4; d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];

                    if (nr < 1 || nc < 1 || nr > R || nc > C)
                        continue;
                    if (Map[nr][nc] == -1)
                        continue;

                    temp[nr][nc] += quota;
                    cnt++;
                }
                //나눠줬으므로 그만큼의 양 빼주기
                Map[i][j] -= quota * cnt;
            }
        }
    }

    //Map와 temp 통합
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            Map[i][j] += temp[i][j];
        }
    }
}

//두 가지 case로 나눠야 함. 윗 부분은 반시계 방향으로, 아래 부분은 시계 방향으로 순환한다. 청소기 바로 옆칸은 깨끗한 바람이므로 먼지 양은 0.
void move()
{
    //윗 부분 (반시계)
    {
        //왼쪽 줄 : 아래로 밀림
        for(int i = tornado[0].first - 1; i > 1; i--)
            Map[i][1] = Map[i-1][1];

        //위쪽 줄  : 왼쪽으로 밀림
        for(int j = 1; j < C; j++)
            Map[1][j] = Map[1][j+1];

        //오른쪽 줄 : 위로 밀림
        for(int i = 1; i < tornado[0].first; i++)
            Map[i][C] = Map[i+1][C];
        
        //청소기가 있는 줄 : 오른쪽으로 밀림
        for(int j = C; j > 1; j--)
            Map[tornado[0].first][j] = Map[tornado[0].first][j-1];

        Map[tornado[0].first][2] = 0;
    }
    
    
    //아래 부분 (시계)
    {
        //왼쪽 줄 : 위로 밀림
        for(int i = tornado[1].first + 1; i < R; i++)
            Map[i][1] = Map[i+1][1];

        //아래쪽 줄  : 왼쪽으로 밀림
        for(int j = 1; j < C; j++)
            Map[R][j] = Map[R][j+1];

        //오른쪽 줄 : 아래로 밀림
        for(int i = R; i > tornado[1].first; i--)
            Map[i][C] = Map[i-1][C];

        //청소기가 있는 줄 : 오른쪽으로 밀림
        for(int j = C; j > 1; j--)
            Map[tornado[1].first][j] = Map[tornado[1].first][j-1];

        Map[tornado[1].first][2] = 0;
    }
}

int solve(int r, int c, int time, const vector<vector<int>> input)
{
    //Map은 1-indexed, input은 0-indexed이므로 보정 진행
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            Map[i][j] = input[i - 1][j - 1];
            if (Map[i][j] == -1) 
                tornado.push_back({i, j}); //청소기 위치 저장
        }
    }

    //매 시간마다
    //1. 먼지 확산
    //2. 청소기 작동
    for (int t = 0; t < Time; t++) {
        spread();
        move();
    }

    //Map에 존재하는 모든 먼지 값 더해주기
    int answer = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (Map[i][j] != -1)
                answer += Map[i][j];
        }
    }
    return answer;
}