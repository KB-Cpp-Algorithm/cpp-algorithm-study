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
    // 여러 개의 기둥 중 2개의 기둥을 선택하여
    // 가능한 컨테이너에 물을 최대로 담을 수 있도록 설계
    int maxArea(vector<int>& height) {
        // 좌측 포인터
        int left = 0;
        // 우측 포인터
        int right = height.size() - 1;
        int result = INT_MIN;

        while (left < right) {
            // 두 기둥 사이의 너비
            int width = right - left;
            // 더 낮은 높이를 가진 기둥을 높이로 설정
            int minHeight = min(height[left], height[right]);
            // 물을 최대로 담을 수 있는 넓이로 최대값 갱신
            result = max(result, width * minHeight);
            // 더 낮은 높이의 기등을 포기
            // 좌측 기둥의 높이가 더 낮거나 같은 경우
            if (height[left] <= height[right]) {
                left++;
            }
            // 우측 기둥의 높이가 더 낮을 경우
            else {
                right--;
            }
        }

        return result;
    }
};