/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Binary Search                           KK KK    BB  BB  */
/* Time Complexity   : O(log n)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int index;

        // lower_bound: target 이상을 찾을 때
        // upper_bound: target 초과를 찾을 때
        // 타겟을 찾을 경우 모두 이터레이터를 반환
        // 타겟을 찾을 수 없을 경우 end() 반환

        // 타켓 값보다 같거나 큰 값이 등장하는 위치(이터레이터) 저장
        index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        // 인덱스가 배열에서 벗어나거나 타겟 값이 아닌 경우
        if (index == nums.size() || nums[index] != target) {
            return result;
        }

        // 가장 먼저 target이 등장한 위치를 저장
        result[0] = index;

        // 타켓 값보다 큰 값이 등장하는 위치(이터레이터) 저장
        index = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

        // 가장 마지막에 target이 등장한 위치를 저장
        result[1] = index;

        return result;
    }
};