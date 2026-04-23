/********************************************************************************/
/* File Name         : A-ClosedInterval.cpp                                     */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : Math (수학) / Arithmetic (사칙연산)     KK KK    BB  BB  */
/* Time Complexity   : O(1)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<iostream>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << b-a+1;
}