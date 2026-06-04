/******************************************************************************/
/* File Name        : 1011.cpp                                                */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : Parametic Search                    KK  KK    BB  BB    */
/* Time Complexity  : O(Nlog(amount))                     KKKKK     BBBBB     */
/* Space Complexity : O(1)                                KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    
    // cap = 용량, cap으로 days 안에 weights 내의 모든 물건을 배송 가능한지 판별
    bool check(int cap, vector<int>& weights, int days) {
        //현재 날짜 수
        int cur_days = 1;
        
        // 현재 날짜에 남은 용량
        int cur_cap = cap;
        
        // 배열을 돌며 날짜를 계산하는 반복문
        for (int j : weights) {
            if (cur_days > days)
                return false;
    
            // 용량 초과 시 다음날로 넘김
            if (cur_cap < j) {
                cur_days++;
                // 용량 초기화
                cur_cap = cap;
            }
            
            cur_cap -= j;
        }

        // days 안에 배송 가능하면 true return
        return cur_days <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        // 전체 물건 무게의 합
        int amount = 0;
        // 가장 무거운 물건의 무게
        int max_weight = 0;
        
        // 배열을 돌면서 amount, max_weight 계산
        for (auto i : weights) {
            amount += i;
            max_weight = max(i, max_weight);
        }

        // 용량의 최솟값 = 가장 무거운 물건의 무게
        int left = max_weight;
        int right = amount;
        
        // 이분 탐색
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // mid 값으로 배송 가능 시 더 작은 값으로 탐색
            if (check(mid, weights, days))
                right = mid - 1;
            // 배송 불가 시 더 큰 값으로 탐색
            else
                left = mid + 1;
        }
        
        // 조건을 만족하는 최소 용량
        return left;
    }
};
