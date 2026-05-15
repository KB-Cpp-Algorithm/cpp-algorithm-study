/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : jjeong2                                 KK  KK   BBBBB   */
/* Algorithm         : 시뮬레이션 / 해시                       KK KK    BB  BB  */
/* Time Complexity   : O(N + M)                                KKKKK    BBBBB   */
/* Space Complexity  : O(M)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int dir = 0; //0 : 북쪽 , 1 : 남쪽 , 2 : 서쪽 , 3 : 동쪽
        int maxDistance = 0;
        vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
        int x = 0, y = 0;

        //장애물 위치 등록
        unordered_set<string> obstacle;
        for(int i = 0; i < obstacles.size(); i++){
            for(int j = 0; j < 2; j++){
                int tempx = obstacles[i][0];
                int tempy = obstacles[i][1];

                obstacle.insert(to_string(tempx) + " " + to_string(tempy));
            }
        }

        for(int i = 0; i < commands.size(); i++){

            //오른쪽으로 90도 회전
            if(commands[i] == -1){
                if(dir == 0)
                    dir = 3;
                else if(dir == 1)
                    dir = 2;
                else if(dir == 2)
                    dir = 0;
                else
                    dir = 1;
            }
            //왼쪽으로 90도 회전
            else if(commands[i] == -2){
                if(dir == 0)
                    dir = 2;
                else if(dir == 1)
                    dir = 3;
                else if(dir == 2)
                    dir = 1;
                else
                    dir = 0;
            }
            else{
                for(int j = 0; j < commands[i]; j++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    //장애물 있는지 확인
                    string nextPos = to_string(nx) + " " + to_string(ny);
                    if(obstacle.find(nextPos) != obstacle.end())
                        break;

                    x = nx;
                    y = ny;

                    maxDistance = max(maxDistance, x*x + y*y);
                }
            }
        }
        return maxDistance;
    }
};

int main(void)
{
    Solution sol;

    vector<int> cmd = {4, -1, 3};
    vector<vector<int>> obstacle = {};

    vector<int> cm2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacle2 = {{2,4}};

    cout << sol.robotSim(cmd, obstacle) << ' ' << sol.robotSim(cm2, obstacle2);
}