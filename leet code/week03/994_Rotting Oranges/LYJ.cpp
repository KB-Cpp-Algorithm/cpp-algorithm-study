/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : BFS                                     KK KK    BB  BB  */
/* Time Complexity   : O(M*N)                                  KKKKK    BBBBB   */
/* Space Complexity  : O(M*N)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();

        //섞은 귤의 위치(행, 열)을 담은 큐: q
        queue<pair<int, int>> q;
        int fresh_count = 0; //신선한 귤
        
        // 1. 초기 썩은 귤 큐에 삽입 및 신선한 귤 개수 카운트
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    fresh_count++;
                }
            }
        }
        
        // 처음부터 신선한 귤이 없다면 0분 소요
        if (fresh_count == 0) return 0;
        
        int minutes = 0;
        // 상하좌우 탐색을 위한 방향 배열 (위, 아래, 왼, 오)
vector<pair<int, int>> dirs = {
            make_pair(-1, 0), make_pair(1, 0), 
            make_pair(0, -1), make_pair(0, 1)
        };        
        // 2. BFS 탐색
        while (!q.empty()) {
            int size = q.size();
            bool isRotted = false;
            
            // 현재 큐에 있는(동일한 시간대의) 썩은 귤들만 처리
            for (int i = 0; i < size; ++i) {
                pair<int, int> current = q.front();
                int r = current.first;
                int c = current.second;
                q.pop();
                
                for (pair<int, int> d : dirs) { //이 부분이 어렵
                    int nr = r + d.first;
                    int nc = c + d.second;
                    
                    // 그리드 범위를 벗어나지 않고 신선한 귤(1)이라면
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2; // 귤을 썩게 만듦
                        fresh_count--;    // 신선한 귤 개수 감소
                        q.push({nr, nc}); // 새로 썩은 귤을 큐에 추가
                        isRotted = true; // 이번 분에 귤이 썩었음을 표시
                    }
                }
            }
            // 이번 1분 동안 귤이 하나라도 새로 썩었다면 시간 증가
            if (isRotted) minutes++;
        }
        
        // 3. 탐색 후 신선한 귤이 남아있는지 확인
        return fresh_count == 0 ? minutes : -1;
    }
};