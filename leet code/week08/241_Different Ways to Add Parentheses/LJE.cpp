/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                  KK  KK   BBBBB   */
/* Algorithm         : 재귀                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 아이디어 ai도움 받음                        KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        //base case - expression의 길이가 1이라면 숫자만 남은거니까 바로 리턴
        // if(expression.size() == 1){
        //     result.push_back(expression[0] - '0');
        //     return result;
        // } --> 일의자리 숫자만 있는 것이 아니니까 에러!

        for(int i = 0; i < expression.size(); i++){
            char ch = expression[i];

            if(ch == '+' || ch == '-' || ch == '*'){
                //현재 연산자 기준으로 왼쪽에 있는 식에서 나올 수 있는 모든 계산 결과
                vector<int> left = diffWaysToCompute(expression.substr(0,i));

                //현재 연산자 기준으로 오른쪽에 있는 식에서 나올 수 있는 모든 계산 결과
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                //left와 right를 조합해서 만들 수 있는 모든 계산 결과들을 restult에 저장
                for(auto l : left){
                    for(auto r: right){
                        if(ch == '+'){
                            result.push_back(l + r);

                        }else if(ch == '-'){
                            result.push_back(l - r);

                        }else if(ch == '*'){
                            result.push_back(l * r);
                        }   
                    }
                }
            }

        }

        //base case를 여기서 처리
        //result의 크기가 0이라는 것은 현재 expression안에 연산자가 없다는 뜻
        if(result.size() == 0){
            result.push_back(stoi(expression));
        }
        
        return result;
    }
};