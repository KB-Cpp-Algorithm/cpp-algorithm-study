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

/* Idea
    현재 포인터들이 가르키는 건물의 높이를 비교.
    건물 높이가 더 낮은 건물을 가르키는 포인터를 이동.
*/

class Solution {
public:

    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size - 1; //각각 시작·끝 포인터
        int result = 0;
        
        while(left <= right){
            int area = (right - left) * min(height[left], height[right]);
            result = max(result, area);

            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return result;     
    }
};


int main(void)
{
    Solution sol;
    
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> height2 = {1, 1};

    cout << sol.maxArea(height) << '\n';
    cout << sol.maxArea(height2) << '\n';
}