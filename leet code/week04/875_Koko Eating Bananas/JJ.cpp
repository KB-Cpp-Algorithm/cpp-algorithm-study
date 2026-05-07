/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 이분탐색                                KK KK    BB  BB  */
/* Time Complexity   : O(nlogm)                                KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              : n은 piles 개수, m은 최대 pile 크기      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    //가능 가능 가능 불가능 | 불가능 불가능 불가능 가능  <- 시점이 바뀌는 지점 찾기
    //이분탐색 사용 가능함
    int minEatingSpeed(vector<int>& piles, int h) {
        int answer = INT_MAX;
        sort(piles.begin(), piles.end());

        int left = 1, right = piles.back();

        //이분탐색. K를 중심으로 이분탐색 진행
        while(left <= right){
            long long tempHour = 0;
            int mid = (left + right) / 2;

            //올림 나눗셈을 이용하여 걸리는 시간을 잰다
            for(int i = 0; i < piles.size(); i++)
                tempHour += (piles[i] + mid - 1) / mid;
            
            //시간초과 -> 먹는 속도를 올려야 함
            if(tempHour > h){
                left = mid + 1;
            }
            //다 먹을 수 있음 -> 먹는 속도를 줄이면서 최소값 찾기
            else{
                answer = min(answer, mid);
                right = mid - 1;
            }
        }
        return answer;
    }
};


int main(void)
{
    Solution sol;

    vector<int> piles = {3, 6, 7, 11};
    vector<int> piles2 = {30, 11, 23, 4, 20};
    vector<int> piles3 = {30, 11, 23, 4, 20};

    cout << sol.minEatingSpeed(piles, 8) << '\n';
    cout << sol.minEatingSpeed(piles2, 5) << '\n';
    cout << sol.minEatingSpeed(piles3, 6) << '\n';
}