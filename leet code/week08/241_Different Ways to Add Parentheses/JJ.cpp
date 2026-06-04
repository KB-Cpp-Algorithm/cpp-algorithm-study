/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
    }
};

int main(void)
{
    Solution sol;

    vector<int> answer = sol.diffWaysToCompute("2-1-1");
    vector<int> answer2 = sol.diffWaysToCompute("2*3-4*5");

    for(auto p : answer){
        cout << p << ' ';
    }
    cout << '\n';
    for(auto p : answer2){
        cout << p << ' ';
    }
}