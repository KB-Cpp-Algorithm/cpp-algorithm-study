/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;



class Solution {
    //[0]:상 [1]: 하 [2]: 좌 [3]: 우
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int R,C;
    stack<pair<int,int>> st;
    vector<vector<int>> visited;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        R = grid.size();
        C = R ? grid[0].size() : 0;

        visited = vector<vector<int>>(R, vector<int>(C, 0));
        
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    answer++;

                    dfs(grid, i, j);
                }
            }
        }

        return answer;
    }

    void dfs(vector<vector<char>>& grid, int y, int x){ 
        st.push(make_pair(y, x));
        visited[y][x] = 1;

        while(!st.empty()){
            int tempY = st.top().first;
            int tempX = st.top().second;
            st.pop();
            
            for(int i = 0; i < 4; i++){
                int ny = tempY + dy[i];
                int nx = tempX + dx[i];

                if(ny < 0 || ny >= R || nx < 0 || nx >= C)
                    continue;
                if(visited[ny][nx] == 1)
                    continue;
                if(grid[ny][nx] == '1'){
                    st.push(make_pair(ny, nx));
                    visited[ny][nx] = 1;
                }    
            }
        }
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<char>> grid = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
    vector<vector<char>> grid2 = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    cout << sol.numIslands(grid2) << '\n';
}