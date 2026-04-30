/********************************************************************************************/
/* File Name        : LJE.cpp                                                               */
/* By               : Jieun                                              KK  KK  BBBBB      */
/* Algorithm        : DP                                                 KK KK   BB  BB     */
/* Time Complexity  : O(N)                                               KKKKK   BBBBB      */
/* Space Complexity : O(N)                                               KK KK   BB  BB     */
/* Note             : 원형 배열 -> 두 번의 선형 DP로 분리하여 해결        KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 105
using namespace std;

class Solution {
public:
    int solve(int start, int end, vector<int>& nums){
        // 처음에 모두 0으로 초기화
        int DP[MAX][2];
        memset(DP, 0, sizeof(DP));

        for(int i = start; i <= end; i++){
            // 오늘 선택을 안 하는 경우
            DP[i][0] = max(DP[i-1][0], DP[i-1][1]);
            // 오늘 선택을 하는 경우
            DP[i][1] = DP[i-1][0] + nums[i-1];
        }

        return max(DP[end][0], DP[end][1]);
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }

        // solve함수만으로는 맨뒤, 맨앞의 관계를 고려할 수 없다
        // 따라서 따로 solve돌려서 마지막에 max로 최댓값 결정
        int robFirst = solve(1, nums.size()-1, nums);
        int robSecond = solve(2, nums.size(), nums);

        return max(robFirst, robSecond);
    }
};
