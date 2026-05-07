/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : Binary Search (Lower/Upper Bound)        KK KK    BB  BB */
/* Time Complexity   : O(log n)                                 KKKKK    BBBBB  */
/* Space Complexity  : O(1)                                     KK KK    BB  BB */
/* Note              : 이진 탐색을 이용한 범위 검색             KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        
        int left = 0;
        int right = arr.size() - 1;

        // target이 arr[mid]보다 클 때 mid값들 중 최솟값 
        int upper = arr.size();
        
        // target이 arr[mid]보다 크거나 같을 때 mid값들 중 최솟값
        int lower = arr.size();

        // 1. lower bound 찾기 
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] >= target) {
                right = mid - 1;
                lower = min(mid, lower);
            } else {
                left = mid + 1;
            }
        }

        // 2. upper bound 찾기
        left = 0;
        right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] > target) {
                right = mid - 1;
                upper = min(mid, upper);
            } else {
                left = mid + 1;
            }
        }

        vector<int> ans;
        
        // lower랑 upper가 같다는 것은 target값이 배열에 존재하지 않는다는 뜻
        if (lower == upper) {
            ans.push_back(-1);
            ans.push_back(-1);
        } else {
            ans.push_back(lower);
            ans.push_back(upper - 1);
        }
        
        return ans;
    }
};
