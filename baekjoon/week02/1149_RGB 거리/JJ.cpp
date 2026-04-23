/********************************************************************************/
/* File Name         : 1149.cpp                                                 */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : DP                                      KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
    Idea: 인접한 집끼리는 색이 달라야 함.
    완전 탐색 -> 경우의 수 : 3 * 2^(N-1) -> 불가!!!!

    R[i] = min(R_Cost + G[i-1] , R_Cost + B[i-1]) 
         = R_Cost + min(G[i-1] , B[i-1])
    B[i] = B_Cost + min(R[i-1] , G[i-1])
    G[i] = G_Cost + min(R[i-1] , B[i-1]) 
*/
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R_Cost, B_Cost, G_Cost;

    cin >> N;
    vector<int> R(N,0),G(N,0),B(N,0);

    cin >> R[0] >> G[0] >> B[0];
    for(int i = 1; i < N; i++){
        cin >> R_Cost >> G_Cost >> B_Cost;
        R[i] = R_Cost + min(B[i-1], G[i-1]);
        G[i] = G_Cost + min(R[i-1], B[i-1]);
        B[i] = B_Cost + min(R[i-1], G[i-1]);
    }
    
    cout << min({R[N-1], G[N-1], B[N-1]});
}