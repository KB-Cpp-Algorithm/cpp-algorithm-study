/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 사칙연산                                KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 뺄셈 후 절대값 예외처리.                KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int L,R;
    cin >> L >> R;
    int answer = L-R;
    if (answer < 0)
    {
        answer = -1*answer;
    }
    
    cout << answer + 1;
    

    return 0;
}
