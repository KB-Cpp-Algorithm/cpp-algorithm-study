/********************************************************************************/
/* File Name         : 15486.cpp                                                */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : DP                                      KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              : dp[N] : N-1일까지 일해서 번 최대값      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, dp[1500001] = {0, };
    //curr : i번째 날까지의 최대 이익
    int ans = 0, curr = 0;
    cin >> N;

    
    for(int i = 0; i < N; i++){
        int period, cost;
        cin >> period >> cost;

        //i번째 날까지의 최대 이익 갱신(과거 현재만 봄)
        //현재 진행 중인 상담이 있으면 해당 상담의 보상은 반영 x
        curr = max(curr, dp[i]);
        //N일 보다 커지면 의미 없으므로 계산 스킵
        if(i + period > N)
            continue;

        //끝나는 날 기준 맥스값 갱신
        dp[i + period] = max(dp[i + period], curr + cost);
        ans = max(dp[i + period], ans);
    }

    cout << ans;
}