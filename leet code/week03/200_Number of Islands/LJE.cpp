/********************************************************************************************/
/* File Name        : LJE.cpp                                                             */
/* By               : jieun                                          KK  KK  BBBBB      */
/* Algorithm        : DFS                                                KK KK   BB  BB     */
/* Time Complexity  : O(M * N)                                           KKKKK   BBBBB      */
/* Space Complexity : O(M * N)                                           KK KK   BB  BB     */
/* Note             : grid 값을 '0'으로 바꿔 visited 배열 대체           KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int m, n;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void dfs(int r, int c, vector<vector<char>>& grid) {
        // 1. 방문 처리: grid 값을 바꿔버려서 visited 배열을 대체
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            // 2. 범위 체크와 땅인지 확인
            if ((nr >= 0 && nr < m) && (nc >= 0 && nc < n) && grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // 아직 방문 안 한 땅 발견
                    num++;
                    dfs(i, j, grid);
                }
            }
        }
        return num;
    }
};
