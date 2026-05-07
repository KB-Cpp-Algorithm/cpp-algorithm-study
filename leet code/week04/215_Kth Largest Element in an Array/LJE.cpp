/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : Priority Queue (Max Heap)                KK KK    BB  BB */
/* Time Complexity   : O(n log n)                               KKKKK    BBBBB  */
/* Space Complexity  : O(n)                                     KK KK    BB  BB */
/* Note              : K번째 큰 원소를 찾기 위한 힙 활용        KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    priority_queue<int> pq;

    int findKthLargest(vector<int>& nums, int k) {
        
        // 1. 모든 원소를 우선순위 큐에 삽입 (Max Heap 구성)
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        // 2. (k-1)번 pop하여 k번째 큰 값이 top에 오도록 함
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }

        // 3. 현재 top이 k번째 큰 값
        return pq.top();
    }
};
