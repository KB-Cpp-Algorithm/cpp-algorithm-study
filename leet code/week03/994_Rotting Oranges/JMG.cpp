/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 행 열 크기
        int m = grid.size();
        int n = grid[0].size();
        int minute = 0;
        int fresh = 0;
        // 방향배열
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>> rottens;
        // 귤 상태 확인
        for(int i = 0; i < m; i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    rottens.push({i,j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        //fresh 아예 없는 경우
        if(fresh == 0) return 0;

        //탐색 시작
        while(!rottens.empty()) {
            // 시간 체크용
            bool flag = false;
            // for(int i = 0; i < rottens.size(); i++) {
            // -> rottens.size() 가변!! (case 1 Fail)
            int rottens_size = rottens.size();

            // 현재 썩은 귤 처리
            for(int i = 0; i < rottens_size; i++) {
                auto temp = rottens.front();
                rottens.pop();

                int dir_r = temp.first;
                int dir_c = temp.second;
                // 상하좌우 탐색
                for(int j = 0;j < 4;j++) {
                    int temp_r = dir_r + dir[j][0];
                    int temp_c = dir_c + dir[j][1];

                    if(temp_r < 0 || temp_r >=m || temp_c < 0 || temp_c >=n)
                    continue;

                    if(grid[temp_r][temp_c] == 1) {
                        grid[temp_r][temp_c] = 2;
                        rottens.push({temp_r,temp_c});
                        fresh--;
                        flag = true;
                    }
                }
            }
            // 이번 턴에 썩었으면
            if(flag) minute++;
        }
        // 다 끝난 상황
        if(fresh > 0) return -1;
        return minute;
    }
};