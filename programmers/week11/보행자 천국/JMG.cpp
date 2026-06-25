// 시작,끝 좌표 고정
// 예외 상황
// 1. 이동 시 우측 1, 하단 1
// 2. 우측 진행 시 우측 1, 하단 2
// 3. 하단 진행 시 우측 2, 하단 1
// dp...라
// 각 좌표에 도착한 경우를 저장해아 됨(+ 방향 별로 )
// citimap[i][j] == 2에서 방향 전환 x
// dp[i][j] 정의 : i,j에 도착한 경우 카운트
// -> 방향 추가 
// dp[i][j][2]?
#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    // vector<vector<vector<int>>> 
    //     dp(500, vector<vector<int>>(500, vector<int>(2, 0)));
    // dp[i][j][0] : (하단)으로 이동해서 i,j 도착
    // dp[i][j][1] : (우측)으로 이동해서 i,j 도착
    int dp[500][500][2]={};
    
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;

    if(m == 1 && n == 1) return 1;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            
            if(city_map[i][j] == 1) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                continue;
            }
            if(i==0 && j==0) continue;
            
            
            
            if(i > 0) {
                //위 -> 아래로 내려오는 경우
                
                // 위쪽 칸 city_map == 2인 경우
                if(city_map[i-1][j] == 2) {
                    dp[i][j][0] = dp[i-1][j][0];
                }
                // 일반 도로인 경우
                else {
                    dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                }
            }
            
            if(j > 0) {
                // 좌 -> 우로 오는 경우
                
                // 왼쪽 칸 city_map == 2인 경우
                if(city_map[i][j-1] == 2) {
                    dp[i][j][1] = dp[i][j-1][1];
                }
                // 일반 도로
                else {
                    dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
                }
            }
            
        }
    }
    return (dp[m - 1][n - 1][0]
      + dp[m - 1][n - 1][1]) % MOD;
}




// 오답 사유
// 1. dp 배열 초기화 안함.
// 2. dp[0][0][0],dp[0][0][1] 두 개를 1로 초기화했는데 
//    이러면 dp[0][1][1],dp[1][0][0] == 2가 되는 문제 발생
// 3. ->  2. 수정 후 테케 정답, 최종 제출 오답
// 계산마다 MOD 나머지 연산을 해주니까 정답