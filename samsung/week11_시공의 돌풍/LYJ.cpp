/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    // Please write your code here.
    int n, m, t, input, upper_wind, down_wind;
    int sum = 0;
    cin >> n >> m >> t;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<vector<int>> maps(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> input;
            maps[i][j] = input;
            if(input == -1){
                upper_wind = i-1;
                down_wind = i;
            }
            else{
                sum += input;
            }
        }
    }

    while(t--){
        vector<vector<int>> new_maps(n, vector<int>(m, 0));
        new_maps = maps;

        //1. 먼지 확산
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(maps[i][j] != -1){
                    for(int dir =0; dir<4; dir++){
                        //4방향 탐색
                        int n_x = i + dx[dir];
                        int n_y = j + dy[dir];

                        //방문 가능한 경우 (maps안에 있고, 돌품이 아닌 경우에 확산 가능)
                        if(n_x >= 0 && n_x < n && n_y >=0 && n_y <m && maps[n_x][n_y] != -1){
                            int move_dust = maps[i][j] / 5;
                        
                            new_maps[n_x][n_y] += move_dust;
                            new_maps[i][j] -= move_dust;
                        }
                    }
                }            
            }
        }
        
        maps = new_maps;

        //2. 돌풍 발생
            // SUM 값을 UPDATE 하는 것을 잊지 말기.

            //위 돌풍
            //우 상 좌 하 (반시)
            int dir = 0;
            int prev_dust = 0;

            int up_dx[4] = {0, -1, 0, 1};
            int up_dy[4] = {1, 0, -1, 0};

            //[upper_wind, 0]이 위 돌풍의 시작
            int now_x = upper_wind;
            int now_y = 1;
            while(true){
                //1. 먼지 교환
                int temp_dust = maps[now_x][now_y];
                maps[now_x][now_y] = prev_dust;
                prev_dust = temp_dust;

                //2. 다음 이동 칸
                int next_x = now_x + up_dx[dir];
                int next_y = now_y + up_dy[dir];

                //3. 만약 벽을 만난다면, dir을 변경
                if(next_x < 0 || next_y < 0 || next_x > upper_wind || next_y >= m){
                    dir = (dir+1) % 4; //방향을 다시 계산

                    next_x = now_x + up_dx[dir];
                    next_y = now_y + up_dy[dir];
                }

                //4. 종착지 확인
                // 다시 -1을 만나면 루프 종료
                if(maps[next_x][next_y] == -1){
                    sum -= prev_dust;
                    break;
                }

                now_x = next_x;
                now_y = next_y;
            }

            //아래 돌풍
            dir = 0;
            prev_dust = 0;

            //우 하 좌 상
            int down_dx[4] = {0, 1, 0, -1};
            int down_dy[4] = {1, 0, -1, 0};

            //[upper_wind, 0]이 위 돌풍의 시작
            now_x = down_wind;
            now_y = 1;

            while(true){
                //1. 먼지 교환
                int temp_dust = maps[now_x][now_y];
                maps[now_x][now_y] = prev_dust;
                prev_dust = temp_dust;

                //2. 다음 이동 칸
                int next_x = now_x + down_dx[dir];
                int next_y = now_y + down_dy[dir];

                //3. 만약 벽을 만난다면, dir을 변경
                if(next_x < down_wind || next_y < 0 || next_x >= n || next_y >= m){
                    dir = (dir+1)%4; //방향을 다시 계산

                    next_x = now_x + down_dx[dir];
                    next_y = now_y + down_dy[dir];
                }

                //4. 종착지 확인
                // 다시 -1을 만나면 루프 종료
                if(maps[next_x][next_y] == -1){
                    sum -= prev_dust;
                    break;
                }

                now_x = next_x;
                now_y = next_y;
            }


    }

    cout << sum << "\n";
    return 0;

    // return sum;

}