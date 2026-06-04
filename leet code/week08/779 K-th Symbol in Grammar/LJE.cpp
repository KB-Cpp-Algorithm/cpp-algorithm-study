/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : 재귀                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 완탐은 시간 초과, 트리형태를 떠올려 재귀로 해결    KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int target){
        //루트(0)까지 올라갔으면 리턴
        if(target == 1) return 0;
        
        //target이 짝수면 부모 노드와 값 같고, 홀수면 부모 노드와 값 다름
        if(target % 2 == 0){
            return (int)solve(target / 2);
        }else{
            return (int)!solve(target/2);
        }
    }

    int kthGrammar(int n, int k) {
        
        //n번째 줄의 k번쩨 원소를 배열 인덱스로 변환했을 때 값
        int target = pow(2, n-1) + k - 1;
        
        return solve(target);
    }
};