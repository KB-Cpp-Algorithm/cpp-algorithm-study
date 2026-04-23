/********************************************************************************/
/* File Name         : 15486-quit2.cpp                                          */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : dp                                      KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
int t[1500005]; //걸리는 시간
int p[1500005]; //수익
int maxP[1500001] = {0, }; //maxP[k] = 일자별 최대 수익

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> t[i] >> p[i];
    }

    //초기값 정하기 maxP는 모두 0


    for(int i=1; i<=n; i++){
        //수익 이월하기
        maxP[i] = max(maxP[i], maxP[i-1]);
        //미래 갱신하기
        if((i+t[i])<= n+1) 
            maxP[i+t[i]] = max(maxP[i] + p[i], maxP[i+t[i]]);  
    }

    //출력 : maxP[1~n] 중에 가장 큰거 선택
    cout << *max_element(maxP + 1, maxP+n+2);

    return 0;
}