/********************************************************************************/
/* File Name         : A.cpp                                                    */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 단순 구현                               KK KK    BB  BB  */
/* Time Complexity   : O(1)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 입력 정수 사이의 정수 개수 찾기         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L,R;
    cin >> L >> R;
    cout << (R - L + 1);
}