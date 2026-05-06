/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Priority Queue                          KK KK    BB  BB  */
/* Time Complexity   : O(N log N)                              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 상위 데이터 유지는 Min Heap 권장        KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        int result = 0;
        // 최대 힙
        priority_queue<int> pq;
        // priority_queue<int, vector<int>, greater<int>> minPQ; 

        // 우선순위 큐에 값 저장
        for (const int& num : nums) {
            pq.push(num);
        }

        // k번으로 큰 값 추출
        for (int i = 0; i < k; i++) {
            result = pq.top();
            pq.pop();
        }

        return result;
    }
};
