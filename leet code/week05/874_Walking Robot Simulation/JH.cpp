/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Simulation, Set                         KK KK    BB  BB  */
/* Time Complexity   : O((M + N)log M)                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    set<pair<int, int>> s;

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int result = 0;
        // 로봇의 현재 위치
        pair<int, int> pos = {0, 0};
        // 로봇의 현재 방향
        int dir = 0;

        // 장애물의 좌표를 저장
        for (const auto& obstacle : obstacles) {
            int x = obstacle[0];
            int y = obstacle[1];
            s.insert({y, x});
        }

        // 로봇이 수행할 명령
        for (const int& command : commands) {
            // 왼쪽으로 90도 회전
            if (command == -2) {
                dir = (dir + 3) % 4;
            }
            // 오른쪽으로 90도 회전
            else if (command == -1) {
                dir = (dir + 1) % 4;
            }
            // 회전 없이 이동
            else {
                for (int i = 0; i < command; i++) {
                    // 다음 이동 좌표
                    int ny = pos.first + dy[dir];
                    int nx = pos.second + dx[dir];
                    // 다음 좌표에 장애물이 있을 경우
                    if (s.find({ny, nx}) != s.end()) break;
                    // 다음 좌표로 로봇이 이동
                    pos.first = ny;
                    pos.second = nx;
                    // 최대 거리 갱신
                    int dist = pow(pos.first, 2) + pow(pos.second, 2);
                    result = max(result, dist);
                }
            }
        }

        return result;
    }
};