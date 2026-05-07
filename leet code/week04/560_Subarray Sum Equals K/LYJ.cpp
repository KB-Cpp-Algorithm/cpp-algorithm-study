/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : hash                                    KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {    
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_map; //누적합의 값, 등장 횟수

        int cnt = 0; //정답을 저장할 변수
        int crr_sum = 0; //현재의 누적합을 저장할 변수

        //1. 초기상태
        //아무것도 더하지 않았을 때 합(0)이 1번 존재함
        prefix_map[0] = 1;

        //2. nums 배열을 순회
        for(int num: nums){
            crr_sum += num; //현재까지의 누적합

            int target = crr_sum - k; //우리가 찾아야 할 이전 누적합 계산

            //target이 등장했었다면 그 횟수만큼 추가
            if(prefix_map.count(target) > 0){
                    cnt += prefix_map[target]; //target이 등장했던 횟수만큼 통째로 정답에 더해줌
            }


            //이번 턴의 누적합을 맵에 기록
            prefix_map[crr_sum]++;
        

        }

        return cnt;

    }
};