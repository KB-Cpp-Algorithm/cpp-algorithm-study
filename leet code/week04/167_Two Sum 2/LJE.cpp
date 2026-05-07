/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : Two Pointer                              KK KK    BB  BB */
/* Time Complexity   : O(n)                                     KKKKK    BBBBB  */
/* Space Complexity  : O(1)                                     KK KK    BB  BB */
/* Note              : Sorted Array 특성을 활용한 탐색          KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // 1. 리턴할 벡터 설정
        vector<int> ans;

        // 2. 투 포인터를 활용한 탐색
        int left = 0; 
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // 결과는 1-based index로 반환
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                return ans;
            } else if (sum < target) {
                // 합이 작으면 왼쪽 포인터를 오른쪽으로 (값 증가)
                left++;
            } else {
                // 합이 크면 오른쪽 포인터를 왼쪽으로 (값 감소)
                right--;
            }
        }

        return ans;
    }
};
