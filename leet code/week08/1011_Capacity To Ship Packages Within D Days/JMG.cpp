/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 파라메트릭 서치                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>


// 이분 탐색 -> capacity의 최소 최대 구하고 그게 범위가 됨
// capacity로 얼마나 걸리는지 계산
// 계산한 값들 중 최소값 return

class Solution {
public:
    bool search_cap(vector<int>& weights, int days, int capacity) {
        // capacity로 며칠 걸리는지 계산히기
        int usedDays = 1;
        int curr = 0;

        for (int w : weights) {
            if (curr + w > capacity) {
                usedDays++;
                curr = 0;
            }
            curr += w;
        }
        // usedDays가 days 넘어가면 false
        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int min_cap = 0;
        int max_cap = 0;

        for (int w : weights) {
            min_cap = max(min_cap, w);
            max_cap += w;
        }
        int answer = max_cap;

        while (min_cap <= max_cap) {
            // 중간값 - 이분탐색하기 위해
            int center_cap = min_cap + (max_cap - min_cap) / 2;

            if (search_cap(weights, days, center_cap)) {
                answer = center_cap;
                max_cap = center_cap - 1;
            }
            else if (!search_cap(weights, days, center_cap)) {
                min_cap = center_cap + 1;
            }
        }

        return answer;
    }
};