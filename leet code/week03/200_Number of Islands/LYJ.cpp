/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : DFS                                     KK KK    BB  BB  */
/* Time Complexity   : O(M*N)                                  KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <vector>

using namespace std;

class Solution {
public:
    // 육지와 연결된 모든 땅을 찾으면 바다로 바꾸고 순회하는 함수 (DFS)
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        // 지도를 벗어났거나
        // 육지가 아니라 바다(0)이거나 이미 방문해서 가라앉힌 땅(0)이라면 뒤로 돌아가기 , 종료
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }

        // 현재 육지(1)를 바다(0)로 (방문 처리 완료)
        grid[r][c] = '0';

        // 상하좌우 로 한 칸씩 이동하며 연결된 땅이 있는지 계속 (재귀 호출)
        dfs(grid, r - 1, c); // 상
        dfs(grid, r + 1, c); // 하
        dfs(grid, r, c - 1); // 좌
        dfs(grid, r, c + 1); // 우
    }

    int numIslands(vector<vector<char>>& grid) {
        // (\grid가 비어있는 예외 상황 처리)
        if (grid.empty()) return 0;

        int m = grid.size();    // 지도 세로 길이
        int n = grid[0].size(); // 지도 가로 길이
        int island_count = 0;   // 우리가 제출할 섬의 개수

        // 지도의 모든 칸을 처음부터 끝까지 순회
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                // 새로운 육지(1)를 발견
                if (grid[i][j] == '1') {
                    island_count++; // 개수 +1
                    
                    // 방금 찾은 육지를 시작점으로 해서, 
                    // 연결된 모든 땅을 찾아내 바다로 덮기
                    dfs(grid, i, j); 
                }
            }
        }

        // 최종 섬의 개수 반환
        return island_count;
    }
};