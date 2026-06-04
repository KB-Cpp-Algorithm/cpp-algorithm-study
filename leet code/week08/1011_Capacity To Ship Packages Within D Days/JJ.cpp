/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 파라메트릭 서치, 이분 탐색              KK KK    BB  BB  */
/* Time Complexity   : O(nlog(S)                               KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              : log(S) : 이분 탐색 반복 횟수            KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
파라메트릭 서치 : 최적화 문제를 결정 문제로 바꿔서 푸는 기법
최적화 문제? : 주어진 조건 하에서 '가장 좋은 해'를 찾는 문제. 답은 정수, 경로, 조합 등 다양한 형태로 표현될 수 있음
결정 문제?   : 해의 존재 여부를 묻는 문제. 답은 항상 Yes or No 형태로 나옴



최적화 문제 : D일 안에 모든 패키지를 배송할 수 있는 배의 '최소' 용량은?
-> 가능한 capacity 중 최솟값을 찾아라

결정 문제 : capacity가 N일 때, D일 안에 배송 가능한가?
-> 예/아니오 로 대답할 수 있는 결정 문제

-> 처음으로 true가 되는 배의 용량을 이분 탐색으로 찾기


이분탐색 vs 파라메트릭 서치

이분탐색 : 주어진 배열(졍렬된) 안에서 값을 찾는 알고리즘
파라메트릭 서치 : 배열 안에서 답을 찾는 것이 아닌 특정 범위 안에서 답을 찾는 알고리즘

불가능 | 가능
FFFF...|..TTTT
       ^
    이 경계 지점을 찾는 것이 파라메트릭 서치
*/


class Solution {
public:
    //days안에 모든 패키지를 배송할 수 있는지 판별하는 함수
    bool canShip(vector<int>& weights, int days, int capacity) {
        //패키지를 다 담는데 소모한 날
        int currDay = 1;
        //오늘 실은 무게
        int currWeight = 0;

        for (int i = 0; i < weights.size(); i++){
            int w = weights[i];

            //오늘 실은 무게가 용량을 초과하면 더 못실음
            //다음날로 넘기기
            if (currWeight + w > capacity) {
                currDay++;
                currWeight = 0;
            }

            //더 실을 수 있으면 적재
            currWeight += w;
        }

        return currDay <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {


        //무게를 이분탐색으로 찾을 것
        //최소 용량은 가장 무건운 짐보다 작을 수 없음. 최대 용량은 하루에 모든 짐을 다 싣는 경우
        //초기값 세팅. 
        int left = 0;
        int right = 0;
        for(int i = 0; i < weights.size(); i++){
            left = max(weights[i], left);
            right += weights[i];
        }
        
        //이분탐색 형태로 탐색 시작
        while(left < right){
            //경계값 지정
            int mid = (left + right) / 2;

            //가능 여부 판별
            //가능하면 최소가 돼야 하므로 더 낮춰보기
            if (canShip(weights, days, mid)) 
                right = mid;
            //불가능하면 용량을 늘려야 함
            else 
                left = mid + 1;
        }
        
        return left;
    }
};

int main(void)
{
    Solution sol;

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    vector<int> weights3 = {1, 2, 3, 1, 1};

    cout << sol.shipWithinDays(weights, 5) << ' ' << sol.shipWithinDays(weights2, 3) << ' ' << sol.shipWithinDays(weights3, 4) << '\n'; 
}
