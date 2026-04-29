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

//실행시간 3초나 걸림. 더 줄일 방법?

class Solution {
public:
    int R, C;
    int minute = 0;
    int numFresh = 0;
    vector<vector<int>> newGrid;
    //rotted : 탐색 시작지점
    //st : 한 사이클을 나타내는 스택. rotted를 st에 복사하고 st 안에서 처리 후, 비게 되면 한 주기가 끝났으므로 minute++ 한다.
    stack<pair<int,int>> rotted, st;
    

    //상하좌우 체크. 1이면 시작지점을 나타내는 rotted에 push 후 2로 변환시켜줌(일종의 visited). 그리고 신선한 오렌지 개수 차감.
    void checkUp(const int& row, const int& col)
    {
        if(newGrid[row - 1][col] == 1){
            rotted.push(make_pair(row - 1, col));
            newGrid[row - 1][col] = 2;
            numFresh--;
        }
    }

    void checkDown(const int& row, const int& col)
    {
        if(newGrid[row + 1][col] == 1){
            rotted.push(make_pair(row + 1, col));
            newGrid[row + 1][col] = 2;
            numFresh--;
        }  
    }

    void checkLeft(const int& row, const int& col)
    {
        if(newGrid[row][col - 1] == 1){
            rotted.push(make_pair(row, col - 1));
            newGrid[row][col - 1] = 2;
            numFresh--;
        }   
    }

    void checkRight(const int& row, const int& col)
    {
        if(newGrid[row][col + 1] == 1){
            rotted.push(make_pair(row, col + 1));
            newGrid[row][col + 1] = 2;
            numFresh--;
        }
    }

    int orangesRotting(vector<vector<int>>& grid)
    {
        //grid 사이즈
        R = grid.size();
        C = R ? grid[0].size() : 0;
        
        // 바운더리 검사 피하기 위해 grid 벡터 주변을 전부 0으로 감싸주기
        newGrid = vector<vector<int>>(R + 2, vector<int>(C + 2, 0));
        
        //newGrid 안에 grid 복사 + 신선한 오렌지 개수 세고 썩은 오렌지 좌표 벡터에 저장
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                newGrid[i][j] = grid[i-1][j-1];

                //신선한 오렌지 개수 세기 및 썩은 오렌지 좌표 저장
                if(newGrid[i][j] == 1)
                    numFresh++;
                else if(newGrid[i][j] == 2) 
                    rotted.push(make_pair(i,j));
            }
        }

        //처음부터 신선한 오렌지 없을 때
        if(numFresh == 0)
            return 0;

        //신선한 오렌지가 있지만 썩은 오렌지가 없으면 다 썩게 만드는 것이 불가능하므로 -1 리턴
        if(rotted.size() == 0)
            return -1;

        //상하좌우 검사후 썩을 오렌지 후보들을 스택에 넣어주면서 탐색을 끝낼 때까지 반복문 돌리기 
        while(!rotted.empty()){
            //rotted만 쓰게 되면 주기 구분이 어려워지므로 st라는 한 주기를 나타내는 임시 스택 사용
            st = rotted;
            //다음 주기 시작 지점을 담아야하므로 비워줌
            rotted = stack<pair<int,int>>();

            if(numFresh == 0)
                break;
            //스택에 들어가 있는 썩은 오렌지 주변을 탐색하면서 인접한 오렌지를 썩은 오렌지로 바꾸기
            //st에는 현재 주기에서의 시작지점을 담고 있음
            while(!st.empty()){
                int row = st.top().first;
                int col = st.top().second;

                st.pop();
                //상하좌우 검사
                checkUp(row, col);
                checkDown(row, col);
                checkLeft(row, col);
                checkRight(row, col);
            }
            //주기 끝났으므로 시간++
            minute++;
        }
        
        //신선한 오렌지 개수가 0개면 다 썩히는 데 성공했다는 의미이므로 걸린 시간 리턴
        if(numFresh == 0)
            return minute;
        //while문 통과 후(다 썩힌 후) 신선한 오렌지의 개수가 0 초과면 실패했다는 뜻이므로 -1 리턴
        else
            return -1;
    }
};


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    vector<vector<int>> grid2 = {{2,1,1}, {0,1,1}, {1,0,1}};
    vector<vector<int>> grid3 = {{0,2}};
    vector<vector<int>> grid4 = {{2,1,1}, {1,1,1}, {0,1,2}};
    cout << sol.orangesRotting(grid3) << '\n';
}