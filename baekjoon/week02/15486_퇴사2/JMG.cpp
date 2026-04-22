/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : DP                                      KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              : 거꾸로 DP                               KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

// AI 사용
// Runtime Error -> 백준 실행 환경에서는 스택 제한 때문에 Segmentation fault
// main 함수 바깥에 전역으로 선언 or vector로 해결
long long t[1500001];
long long p[1500001];
long long dp[1500002];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    // -> 전역 변수로 선언, dp[] int -> long long 교체(계산 때문에 나머지도 변경) 
    // int t[1500001];
    // int p[1500001];
    // int dp[1500002]={0};

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }

    // dp[i] = i일부터 얻는 최대 수익
    // 거꾸로 계산 - 퇴사일 기준
    for (int i = N; i >= 1; i--)
    {
        // 퇴사일 넘는 경우 -> 상담 못하는 경우 제외 
        if (i + t[i] - 1 > N) {
            dp[i] = dp[i+1];
            continue;
        }

        dp[i] = max(p[i] + dp[i+t[i]] , dp[i+1]);        
    }
    cout << dp[1];
    return 0;
}
