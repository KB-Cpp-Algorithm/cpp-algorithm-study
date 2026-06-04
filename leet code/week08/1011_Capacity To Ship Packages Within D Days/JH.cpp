/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Parametric Search                       KK KK    BB  BB  */
/* Time Complexity   : O(N log S)                              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 정답이 될 수 있는 값의 범위를 탐색      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 최소 수용량
        int minCapacity = *max_element(weights.begin(), weights.end());
        // 최대 수용량
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        int answer = maxCapacity;

        while (minCapacity <= maxCapacity) {
            // 주어진 정수 값이 낮아서 long long 필요 없음
            int midCapacity = (minCapacity + maxCapacity) / 2;
            int currentCapacity = 0;
            int currentDays = 1;

            for (const int& weight : weights) {
                if (currentCapacity + weight <= midCapacity) {
                    currentCapacity += weight;
                } else {
                    currentDays++;
                    currentCapacity = weight;
                }
            }

            if (currentDays <= days) {
                answer = midCapacity;
                maxCapacity = midCapacity - 1;
            } else {
                minCapacity = midCapacity + 1;
            }
        }

        return answer;
    }
};