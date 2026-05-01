#include <bits/stdc++.h>

using namespace std;

class Solution {
    // 방향
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

   public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 세로 사이즈
        int R = grid.size();
        // 가로 사이즈
        int C = grid[0].size();
        // 신선한 오렌지 개수
        int freshOrangeCnt = 0;
        int result = 0;
        // 방문 배열
        vector<vector<int>> visited(R, vector<int>(C, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 신선한 오렌지일 경우
                if (grid[i][j] == 1) {
                    freshOrangeCnt++;
                }
                // 썩은 오렌지일 경우
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        // 처음부터 신선한 오렌지가 없을 경우
        if (freshOrangeCnt == 0) return 0;
        // 썩은 오렌지가 아예 없는는 경우
        if (q.empty()) return -1;

        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                // 다음 좌표가 영역을 벗어났을 경우
                if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                // 이미 방문했거나 썩게 만들 신선한 과일이 아닐 경우
                if (visited[ny][nx] != 0 || grid[ny][nx] != 1) continue;
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                // 신선한 과일을 썩게 만듦
                freshOrangeCnt--;
                // 결과 업데이트
                result = max(result, visited[ny][nx]);
            }
        }

        // 그럼에도 불구하고 신선한 오렌지가 남아있을 경우
        if (freshOrangeCnt > 0) return -1;

        // 방문 배열의 시작이 1이었으므로
        return result == 0 ? 0 : result - 1;
    }
};