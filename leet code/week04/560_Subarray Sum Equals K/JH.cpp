

/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

/*
    Q. 부분 배열의 합이 k일 경우, 몇 개의 부분 배열이 존재?
    a[i] ~ a[j] 부분 배열은 sum[j] - sum[i - 1].
    즉, 문제 요구사항은 sum[j] - sum[i - 1] = k를 만족하는 것 찾기.
    이때 sum[i - 1]는 sum[j] - k = 로 표현 가능.
    그렇다면 현재 누적합(sum[j])에서 k를 뺀 값이 과거(sum[i - 1])에 몇 번 등장했는지 계산.
*/

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        // 해시 맵
        unordered_map<int, int> um;

        // 누적합(최대 2000만)
        int pSum = 0;
        um[0] = 1;

        for (const int& num : nums) {
            // 누적 합에 현재 값 추가
            pSum += num;
            // 과거에 등장 했을 경우
            if (um.find(pSum - k) != um.end()) {
                // 등장 수만큼 카운팅
                result += um[pSum - k];
            }
            // 현재 누적합 값 등장 수 +1
            um[pSum]++;
        }

        return result;
    }
};

// version.1 시간복잡도: O(N * N) 약 1.5초 소요

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         // 사이즈
//         int size = nums.size();
//         int result = 0;
//         // 누적합 배열
//         vector<int> pSum(size);

//         // 만약 사이즈가 1일 경우
//         if (size == 1) {
//             return (nums[0] == k) ? 1 : 0;
//         }

//         // [0, 0] 누적합은 0번 배열 값과 같음
//         pSum[0] = nums[0];

//         // 누적합 계산
//         for (int i = 1; i < size; i++) {
//             // [0, i] 누적합은 [0, i - 1] 누적합에 i번 배열의 값을 더한 값
//             pSum[i] = pSum[i - 1] + nums[i];
//         }

//         for (int i = 0; i < size; i++) {
//             for (int j = i + 1; j < size; j++) {
//                 if (pSum[j] - pSum[i] == k)
//                     result++;
//             }
//         }

//         for (int i = 0; i < size; i++) {
//             if (pSum[i] == k)
//                 result++;
//         }

//         return result;
//     }
// };