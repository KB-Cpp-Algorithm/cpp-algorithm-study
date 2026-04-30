/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : DFS                                     KK KK    BB  BB  */
/* Time Complexity   : O(R * C)                                KKKKK    BBBBB   */
/* Space Complexity  : O(R * C)                                KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int R, C;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    bool visited[301][301];

    void dfs(int y, int x, vector<vector<char>>& grid) {
        visited[y][x] = true;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 해당 좌표가 범위를 벗어난 경우
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            // 해당 영역이 바다이거나 이미 방문했을 경우
            if (grid[ny][nx] == '0' || visited[ny][nx]) continue;
            // 다음 좌표 주변 탐색 시작
            dfs(ny, nx, grid);
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        // 세로 사이즈
        R = grid.size();
        // 가로 사이즈
        C = grid[0].size();
        // 섬의 개수
        int result = 0;

        // 방문 배열 초기화
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 해당 영역이 섬이면서 방문한 경험이 없을 경우
                if (grid[i][j] == '1' && !visited[i][j]) {
                    // 해당 좌표 주변 탐색 시작
                    dfs(i, j, grid);
                    // 섬 카운트 증가
                    result++;
                }
            }
        }

        // 섬의 개수 반환
        return result;
    }
};