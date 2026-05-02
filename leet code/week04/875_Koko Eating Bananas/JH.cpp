/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Binary Search                           KK KK    BB  BB  */
/* Time Complexity   : O(N log M)                              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 이분탐색: 무엇을 기준으로 탐색할지?     KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
   public:
   // 제한시간 안에 먹을 수 있는 바나나 최소값 찾기 
    int minEatingSpeed(const vector<int>& piles, int h) {
        int result = INT_MAX;
        // 바나나 범위
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            // 시간 당 먹을 수 있는 바나나
            int mid = (left + right) / 2;
            // 모든 바나나를 먹기까지 걸린 시간
            ll hours = 0;

            // 각 바나나 더미를 먹는데 걸리는 시간 누적
            for (const int& pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            // 경비가 돌아오는 시간안에 먹을 수 있는 경우
            if (hours <= h) {
                // 정답이 최소값 찾기이므로
                // 시간 당 먹을 바나나 수의 범위를 낮추기
                right = mid - 1;
                // 먹는데 걸린 최소 시간 갱신
                result = min(result, mid);
            }
            // 경비가 돌아오는 시간안에 먹을 수 없는 경우
            else {
                // 시간 당 먹을 바나나 수의 범위를 늘리기
                left = mid + 1;
            }
        }

        return result;
    }
};