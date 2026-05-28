#include <bits/stdc++.h>
using namespace std;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Bead {
    int w;   // 질량
    int s;   // 속도
    int dir; // 방향 0~7

    Bead(int w, int s, int d) {
        this->w = w;
        this->s = s;
        this->dir = d;
    }
}; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k; 

    vector<vector<vector<Bead>>> grid(n, vector<vector<Bead>>(n));

    for (int i = 0; i < m; i++) {
        int x, y, mass, s, d; 
        cin >> x >> y >> mass >> s >> d;
        grid[x - 1][y - 1].push_back(Bead(mass, s, d)); 
    }

    for (int i = 0; i < k; i++) {
        // 3차원 임시 배열(매 초마다 초기화 되어야함)
        vector<vector<vector<Bead>>> gridtmp(n, vector<vector<Bead>>(n));

        // 1. 모든 원자 이동시키기
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                for (int g = 0; g < grid[r][c].size(); g++) {
                    int speed = grid[r][c][g].s;
                    int dir = grid[r][c][g].dir;

                    //이동 위치
                    int cr = (r + dr[dir] * speed % n + n) % n;
                    int cc = (c + dc[dir] * speed % n + n) % n;

                    gridtmp[cr][cc].push_back(grid[r][c][g]);
                }
            }
        }

        // 기존 grid를 싹 비우고 gridtmp 결과 담을 준비!!!!!!!
        grid = vector<vector<vector<Bead>>>(n, vector<vector<Bead>>(n));

        // 2. 임시 배열 보면서 합성 
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (gridtmp[r][c].empty()) continue;

                // 칸에 원자가 1개면 합성 없이 그대로 복사
                if (gridtmp[r][c].size() == 1) {
                    grid[r][c].push_back(gridtmp[r][c][0]);
                    continue;
                }

                // 2개 이상일 때 합성 시작
                int nw = 0, ns = 0; 
                
                // 원자의 방향이 모두 짝수거나 모두 홀수이면 상하좌우(0,2,4,6)로 세팅
                // 한개라도 성향이 다르면 대각선(1,3,5,7)으로 세팅
                bool is_even = (gridtmp[r][c][0].dir % 2 == 0);
                bool all_same = true; // 모두 짝수거나 모두 홀수인가?

                for (int s = 0; s < gridtmp[r][c].size(); s++) {
                    nw += gridtmp[r][c][s].w;
                    ns += gridtmp[r][c][s].s;

                    // 첫 번째 원소와 방향의 홀짝 성향이 다르면 false
                    if ((gridtmp[r][c][s].dir % 2 == 0) != is_even) {
                        all_same = false;
                    }
                }

                int next_w = nw / 5;
                if (next_w == 0) continue; // 질량이 0이면 소멸

                int next_s = ns / gridtmp[r][c].size();
                
                // 방향 결정
                int start_dir = all_same ? 0 : 1;
                for (int d = 0; d < 4; d++) {
                    grid[r][c].push_back(Bead(next_w, next_s, start_dir + d * 2));
                }
            }
        }
    }

    // 3. k번의 이동이 끝난 후 남은 원소의 질량의 합
    int total_w = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int g = 0; g < grid[r][c].size(); g++) {
                total_w += grid[r][c][g].w;
            }
        }
    }

    cout << total_w << "\n";
    return 0;
}
