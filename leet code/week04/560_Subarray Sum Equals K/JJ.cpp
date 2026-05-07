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

//int sum = accumulate(더하고싶은 시작점,더하고싶은 도착점, 초기값);

//슬라이딩 윈도우 불가 [1, -2, 1] / k = 3일 때 문제 발생
//누적합 - 부분배열 = 부분배열2 <- 이 때, 부분배열2의 값이 k가 되는 부분배열의 개수를 구하면 된다.
//-> 누적합 - k(부분배열2) = 부분배열


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
        }
    }
};


int main(void)
{
    Solution sol;

    vector<int> nums = {1, 1, 1};
    vector<int> nums2 = {1, 2, 3};

    cout << sol.subarraySum(nums, 2) << '\n';
    cout << sol.subarraySum(nums2, 3) << '\n';
}