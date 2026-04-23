/********************************************************************************/
/* File Name         : 1149-RGBstreet.cpp                                       */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : DP(Dynamic Programming)                 KK KK    BB  BB  */
/* Time Complexity   : o(n)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n;
int h[1005][3];
int r[1005], g[1005], b[1005];


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;


    //입력받기
    for(int i=1; i<=n; i++) cin >> r[i] >> g[i] >> b[i];

    //초기값 정의하기
    h[1][0] = r[1];
    h[1][1] = g[1];
    h[1][2] = b[1];

    for(int i=2; i<=n; i++){
        h[i][0] = min(h[i-1][1], h[i-1][2]) + r[i]; //i번째 집은 빨강
        h[i][1] = min(h[i-1][0], h[i-1][2]) + g[i]; //i번째 집은 초록
        h[i][2] = min(h[i-1][0], h[i-1][1]) + b[i]; //i번째 집은 파랑

    }

    cout << min({h[n][0], h[n][1], h[1][2]});

}