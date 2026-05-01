/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Two Pointers                            KK KK    BB  BB  */
/* Time Complexity   : O(n)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 왼쪽 포인터
        int left = 0;
        // 오른쪽 포인터
        int right = numbers.size() - 1;
        vector<int> result;

        // 투 포인터 알고리즘은 정렬이 중요
        // 이미 오름차순으로 정렬된 numbers

        while (left < right) {
            // 투 포인터가 가르키는 값의 합
            long long sum = numbers[left] + numbers[right];
            // 합이 목표 값보다 클 경우
            if (sum > target)
                right--;
            // 합이 목표 값보다 작을 경우
            else if (sum < target)
                left++;
            // 합이 목표 값과 같을 경우
            else
                return {left + 1, right + 1};
        }

        // 만족하는 결과가 무조건 1개 존재하므로, 빈 배열 반환 가능 
        return {};
    }
};