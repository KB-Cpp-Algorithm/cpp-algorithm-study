/********************************************************************************************/
/* File Name        : LJE.cpp                                                               */
/* By               : Jieun                                              KK  KK  BBBBB      */
/* Algorithm        : Simulation                                         KK KK   BB  BB     */
/* Time Complexity  : O(M * N)                                           KKKKK   BBBBB      */
/* Space Complexity : O(M * N)                                           KK KK   BB  BB     */
/* Note             : 방향 전환 시 visited 배열로 벽/방문 체크            KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dr[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
    int dc[4] = {1, 0, -1, 0};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) return ans;

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int cr = 0, cc = 0, di = 0; // di는 현재 방향 인덱스

        for (int i = 0; i < m * n; i++) {
            ans.push_back(matrix[cr][cc]);
            visited[cr][cc] = true;

            // 다음에 갈 예정인 위치 계산
            int nr = cr + dr[di];
            int nc = cc + dc[di];

            // 갈 수 없는 곳이라면 (벽에 부딪히거나 이미 방문했거나)
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                di = (di + 1) % 4; // 방향 전환 (90도 회전)
                nr = cr + dr[di];
                nc = cc + dc[di];
            }

            cr = nr;
            cc = nc;
        }
        return ans;
    }
};
