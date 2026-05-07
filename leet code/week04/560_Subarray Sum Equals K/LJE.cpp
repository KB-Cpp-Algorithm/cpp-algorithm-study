/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : Prefix Sum, Hash Map                     KK KK    BB  BB */
/* Time Complexity   : O(n)                                     KKKKK    BBBBB  */
/* Space Complexity  : O(n)                                     KK KK    BB  BB */
/* Note              : 누적 합과 해시맵을 이용한 구간 합 계산   KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Key: 누적 합, Value: 해당 합이 등장한 횟수
        unordered_map<int, int> hash_map;
        
        // 배열의 맨 처음부터 현재까지의 누적 합이 정확히 k가 되는 경우를 위해 
        // {0, 1}을 미리 설정 (공집합의 합은 0으로 간주)
        hash_map[0] = 1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i]; // 현재 지점까지의 누적 합

            // 1. (현재 누적 합 - k)가 이전에 나온 적이 있는지 확인
            // sum[j] - sum[i] = k  =>  sum[i] = sum[j] - k
            if (hash_map.find(sum - k) != hash_map.end()) {
                // 2. 있다면, 그 위치들에서 현재 위치까지의 구간 합이 k라는 뜻
                ans += hash_map[sum - k];
            }

            // 3. 현재의 누적 합을 맵에 기록 (카운트 증가)
            hash_map[sum]++;
        }

        return ans;
    }
};
