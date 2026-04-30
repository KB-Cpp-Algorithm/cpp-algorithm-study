/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Simulation                              KK KK    BB  BB  */
/* Time Complexity   : O(N * M)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int R, C;
    bool visited[11][11];
    // 방향(순서: 우 -> 하 -> 좌 -> 상)
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 세로 사이즈
        R = matrix.size();
        // 가로 사이즈
        C = matrix[0].size();
        vector<int> result;
        // 현재 좌표
        int y = 0, x = 0;
        // 현재 이동 방향
        int dirIndex = 0;

        for (int i = 0; i < R * C; i++) {
            // 현재 위치 값 저장
            result.push_back(matrix[y][x]);
            // 방문 처리
            visited[y][x] = true;

            // 다음 이동할 좌표
            int ny = y + dy[dirIndex];
            int nx = x + dx[dirIndex];

            // 유요한 범위를 벗어났거나 이미 방문한 곳일 경우
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) {
                // 방향을 전환
                dirIndex = (dirIndex + 1) % 4;
                // 다음 이동할 좌표를 수정: 방향을 수정한 좌표로 갱신
                ny = y + dy[dirIndex];
                nx = x + dx[dirIndex];
            }
            // 반복을 위해, 다음 좌표를 현재 좌표에 저장
            y = ny;
            x = nx;
        }

        return result;
    }
};