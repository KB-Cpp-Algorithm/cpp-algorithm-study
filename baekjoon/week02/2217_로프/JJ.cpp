/********************************************************************************/
/* File Name         : 2217.cpp                                                 */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 그리디                                  KK KK    BB  BB  */
/* Time Complexity   : O(NlogN)                                KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //key: 로프를 선택해서 사용할 수 있다
    int N, maxWeight = 0, minTemp = 10000;
    cin >> N;
    vector<int> v(N, 0);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    //내림차순 정렬
    sort(v.begin(), v.end(), greater<>());

    for(int i = 1; i <= v.size(); i++){
        //min * rope 수(i) = maxWeight
        minTemp = min(minTemp, v[i-1]);
        maxWeight = max(maxWeight, minTemp * i);
    }

    cout << maxWeight << '\n';
}