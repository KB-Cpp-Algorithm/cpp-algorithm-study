/********************************************************************************************/
/* File Name        : LJE.cpp                                                               */
/* By               : Jieun                                              KK  KK  BBBBB      */
/* Algorithm        : BFS                                                KK KK   BB  BB     */
/* Time Complexity  : O(M * N)                                           KKKKK   BBBBB      */
/* Space Complexity : O(M * N)                                           KK KK   BB  BB     */
/* Note             : 썩은 오렌지 동시 출발, freshCount로 결과 판단       KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isRange(int cr, int cc, int cm, int cn){
        return (cr >= 0 && cr < cm && cc >= 0 && cc < cn);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int freshCount = 0;

        // 1. 초기 썩은 오렌지 위치와 싱싱한 오렌지 개수 파악
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0; // 이미 다 썩어있으면 0분

        int minutes = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 2. BFS
        while(!q.empty()){
            bool fresh_to_rotten = false;
            int current_q_size = q.size();

            // 이 for문 안에서 썩는 오렌지는 모두 동시에 썩는 오렌지
            for(int i = 0; i < current_q_size; i++){
                pair<int, int> f = q.front();
                q.pop();

                for(int j = 0; j < 4; j++){
                    int nr = f.first + dr[j];
                    int nc = f.second + dc[j];

                    if(isRange(nr, nc, m, n) && grid[nr][nc] == 1){
                        fresh_to_rotten = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshCount--; // 싱싱한 오렌지 하나 감소
                    }
                }
            }

            if(fresh_to_rotten) minutes++;
        }

        // 3. 최종 결과 리턴
        return (freshCount == 0) ? minutes : -1;
    }
};
