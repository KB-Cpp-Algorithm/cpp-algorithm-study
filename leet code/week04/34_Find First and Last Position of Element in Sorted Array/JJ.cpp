/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 이진탐색                                KK KK    BB  BB  */
/* Time Complexity   : O(logn)                                 KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer(2, -1);  

        //찾는 값이 없으면
        if(!binary_search(nums.begin(), nums.end(), target))
            return answer;

        //찾는 값이 있으면 target 인덱스 추출
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        //target보다 큰 값의 인덱스 추출
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            
        answer[0] = start;
        answer[1] = end - 1;
        // for(auto i : answer)
        //    cout << i << ' ';
        return answer;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> nums3 = {};

    sol.searchRange(nums, 8);
    cout << '\n';
    sol.searchRange(nums2, 6);
    cout << '\n';
    sol.searchRange(nums3, 0);
    cout << '\n';
}