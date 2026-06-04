/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 재귀                                    KK KK    BB  BB  */
/* Time Complexity   : O(n)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(n)                                    KK KK    BB  BB  */
/* Note              : 배열을 직접 만들지 말고 규칙 찾기       KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int kthGrammar(int n, int k) {
        //dq 벡터 선언해서 앞의 정보 확인, dq에 채워나가는 식으로 구현 -> 시간 초과
        /*
        0 -> 01
        1 -> 10

        0  
        01 
        01 10 
        01 10 10 01 
        01 10 10 01 10 01 01 10 
        
        k가 홀수면 이전 값 그대로
        k가 짝수면 이전 값 반대로
        */

        if(n == 1)
            return 0;

        //k번째 인덱스의 부모 위치는 n-1 행, (k+1) / 2 에 존재
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        
        if(k % 2 == 1)
            return parent;
        else{
            if(parent == 1)
                return 0;
            else
                return 1;
        }
        
    }
};

int main(void)
{
    Solution sol;
    cout << sol.kthGrammar(1, 1) << ' ' << sol.kthGrammar(2,1) << ' ' << sol.kthGrammar(2, 2) << '\n';
}
