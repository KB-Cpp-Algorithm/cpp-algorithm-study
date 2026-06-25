/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : jjeong2                                 KK  KK   BBBBB   */
/* Algorithm         : dp                                      KK KK    BB  BB  */
/* Time Complexity   : O(n*m)                                  KKKKK    BBBBB   */
/* Space Complexity  : O(n*m)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;

/*
(1,1)에서 출발해 (m,n)까지 가는 경로 개수 구하기. 이동은 우 / 하 두 가지만 가능
0 : 자유롭게 지나갈 수 있음
1 : 지나갈 수 없음
2 : 지나갈 수는 있지만 방향 전환 불가

dp 배열을 3차원으로 저장해 방향 벡터를 저장하면 될 거 같음
*/


int solution(int n, int m, vector<vector<int>> city_map)
{
    //dp[i][j][0] : [i][j]에 도착. 이후 아래로 갈 수 있는 경로 수
    //dp[i][j][1] : [i][j]에 도착. 이후 오른쪽으로 갈 수 있는 경로 수
    int dp[501][501][2] = {0,};
    
    //초기값 설정
    dp[1][1][0] = dp[1][1][1] = 1;

    //dp 배열은 1-index based , city_map은 0-index based임. 따라서 dp[i][j]은 city_map[i-1][j-1]에 대응
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(city_map[i - 1][j - 1] == 0){ //0이면 왼쪽과 위에서 올 수 있으므로 케이스를 모두 더해줌
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD; //int 오버플로우 때문에 미리미리 MOD로 나눠줌
                dp[i][j][1] = (dp[i][j][1] + dp[i - 1][j][0] + dp[i][j - 1][1]) % MOD;
            }

            else if(city_map[i - 1][j - 1] == 1) //1이면 올 수 없음
                dp[i][j][0] = dp[i][j][1] = 0;

            else{ //2이면 이전 방향 그대로 유지 돼야 함. 이전 값
                dp[i][j][0] = dp[i - 1][j][0];
                dp[i][j][1] = dp[i][j - 1][1];
            }
        }
    }

    return dp[n][m][0] % MOD;
}

int main(void)
{
    vector<vector<int>> map1 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    vector<vector<int>> map2 = {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};

    cout << solution(3, 3, map1) << '\n' << solution(3, 6, map2) << '\n';
}