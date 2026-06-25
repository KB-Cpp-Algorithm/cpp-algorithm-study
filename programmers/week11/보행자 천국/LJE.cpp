#include <bits/stdc++.h>
using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    //dp table
    /*  
        0. 
        모든 경로의 수라길래 백트래킹인가? 원소 수 넘 많음 -> o(n) dp
        
        1.
        2번 경우 때문에 각 칸은 전에 왔던 방향을 기억해야 한다.
        하나의 차원을 더 써서 전에 이동했던 경로를 기억하자
        
        2. dp table정의
        dp[i][j][0] : (i,j)에 위에서 아래로 내려온 경로의 수 
        dp[i][j][1] : (i,j)에 왼쪽에서 오른쪽으로 온 경로의 수
        
        3. 점화식 정의
            1) city_map[i][j] == 0
                dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1]
                dp[i][j+1][1] += dp[i][j][0] + dp[i][j][1]
                
            2) city_map[i][j] == 1
                XXX!
            
            3) city_map[i][j] == 2
                dp[i+1][j][0] += dp[i][j][0]
                dp[i][j+1][1] += dp[i][j][1]
                
    */
    
    if(m == 1 && n == 1) return 1;
    
    //dp table
    vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
    
    //시작점 설정
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    
    //순회
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
                        
            if(i == 0 && j == 0) {
                if(i + 1 < m) dp[i+1][j][0] = (dp[i+1][j][0] + 1) % MOD;
                if(j + 1 < n) dp[i][j+1][1] = (dp[i][j+1][1] + 1) % MOD;
                continue;
            }
            
            if(city_map[i][j] == 1){
                continue;
            }
            else if(city_map[i][j] == 0){
                if(i+1 < m) {
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0] + dp[i][j][1]) % MOD;
                }
                if(j+1 < n) {
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
                }
            }
            else if(city_map[i][j] == 2){
                if(i+1 < m) {
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % MOD;
                }
                if(j+1 < n) {
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][1]) % MOD;
                }
            }
        }
    }
    
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
}
