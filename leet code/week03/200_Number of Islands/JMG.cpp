/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


/*
m x n grid에 1은 땅, 0은 물
1은 0에 둘러쌓여있고
인접한 땅은 수직 수편으로 연결되어 있는 상태로 1개의 땅 취급!

땅덩어리 개수 출력
*/
// 케이스 전체 오답 -> discussion 댓글 참고 -> grid char 타입 (조건문 수정)
class Solution {
public:
    bool flag[300][300] = {};
    int m,n;

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int island_cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !flag[i][j]) {
                    island_cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return island_cnt;
    }


    void dfs(vector<vector<char>>& grid, int r,int c) {
        // 방향배열
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        // 탈출
        if(r < 0 || r >= m || c < 0 || c >= n) return;
        if(grid[r][c] == '0') return;
        if(flag[r][c]) return;

        flag[r][c] = true;
        for(int i = 0; i < 4; i++) {
            int temp_r = r + dir[i][0];
            int temp_c = c + dir[i][1];
            dfs(grid,temp_r,temp_c);
        }

    }
};