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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = numes.size();
        vector<vector<int>> v(size, vector<int>(size, 0));
        for(int i = 0; i )
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