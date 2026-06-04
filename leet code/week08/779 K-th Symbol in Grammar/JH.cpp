/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Recursion                               KK KK    BB  BB  */
/* Time Complexity   : O(n)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

/*
    - 1번째 행부터 시작해서 n번째 행까지 구할 때, 
    현재 문자열의 문자를 순회하면서 0은 01로 1은 10으로 변환할 경우
    최대 2^29 길이를 가지는 문자열이 반환된다. (n == 30)
    즉, 다른 방법을 사용해야 한다.

    - k 번째 행을 str라고 가정.
    이때 k + 1 번째 행은 (k 번째 행의 값) + (k 번째 행의 0과 1을 뒤집은 값)이다.
    ex) 3번째 행이 0110일 경우, 4번째 행은 0110 + 1001 = 01101001이다.
*/
class Solution {
public:
    // n 번째 행의 k번 원소
    int kthGrammar(int n, int k) {
        // 첫 번째 행일 경우
        if (n == 1) {
            return 0;
        }

        // n 번째 행의 전체 길이
        int size = pow(2, n - 1);
        // 절반 길이
        int halfSize = size / 2;

        // 절반 이하일 경우
        if (k <= halfSize) {
            // n-1 번째 행의 k번 원소
            return kthGrammar(n - 1, k);
        }
        // 절반 초과일 경우
        else {
            return 1 - kthGrammar(n - 1, k - halfSize);
        }
    }
};