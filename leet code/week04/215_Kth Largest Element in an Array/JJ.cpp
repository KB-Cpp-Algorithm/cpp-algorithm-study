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
    int findKthLargest(vector<int>& nums, int k) {
        int answer;
        //우선순위 큐는 내림차순으로 자동 정렬이 되므로
        //큐에 넣고 K번째 출력하면 된다
        priority_queue<int> pq;

        for(int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        for(int i = 0; i < k; i++){
            answer = pq.top();
            pq.pop();
        }

        return answer;
    }
};


int main(void)
{
    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << sol.findKthLargest(nums, 2) << '\n';
    cout << sol.findKthLargest(nums2, 4) << '\n';
}