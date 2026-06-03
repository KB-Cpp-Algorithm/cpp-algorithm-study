/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : DFS                                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 반환 타입이 vector인 DFS는 오랜만..     KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> dfs(const string& str) {
        // 기저 사례 - 숫자로만 구성된 문자열일 경우
        // 연산자가 포함된 문자열은 최소 3자리 이상이므로
        if (str.size() <= 2) {
            // 문자열을 숫자로 변환
            return {stoi(str)};
        }

        vector<int> answer;

        for (int i = 0; i < str.size(); i++) {
            char op = str[i];

            // 연산자가 등장했을 경우
            if (op == '+' || op == '-' || op == '*') {
                // 연산자 기준 왼쪽 부분 문자열
                string left = str.substr(0, i);
                // 연산자 기준 오른쪽 부분 문자열
                string right = str.substr(i + 1);

                vector<int> leftResults = dfs(left);
                vector<int> rightResults = dfs(right);

                for (const int& l : leftResults) {
                    for (const int& r : rightResults) {
                        if (op == '+') {
                            answer.push_back(l + r);
                        } else if (op == '-') {
                            answer.push_back(l - r);
                        } else {
                            answer.push_back(l * r);
                        }
                    }
                }
            }
        }

        return answer;
    }

    vector<int> diffWaysToCompute(string expression) {
        // You may return the answer in any order.
        // 따라서, 정렬없이 정답 벡터 반환
        return dfs(expression);
    }
};