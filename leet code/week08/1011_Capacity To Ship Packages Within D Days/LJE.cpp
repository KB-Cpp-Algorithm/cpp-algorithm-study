/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : parametric search                       KK KK    BB  BB  */
/* Time Complexity   : O(n log S)                              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : binary search                           KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //주어진 수용량(w)으로 며칠동안 옮기는지 계산 - O(n)
    int count(int w, vector<int>& weights){
        int cnt = 1;
        int sum = 0;

        for(auto weight: weights){
            if(sum + weight <= w){
                sum += weight;
            }else{
                cnt++;
                sum = weight;
            }
        }

        return cnt;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        //수용량의 최솟값은 max(weights), 최댓값은 sum(weights)
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;

        for(auto w: weights){
            right += w;
        }

        int min_w = right+1;

        //이진탐색 - O(log s)
        while(left <= right){
            int mid_w = (left + right) / 2;

            //O(n)
            int cnt = count(mid_w, weights);

            //days안에 옮길 수 있을 때 min_w를 업데이트, 더 작은 수용량으로도 옯길 수 있는지 탐색
            if(cnt <= days){
                min_w = min(min_w, mid_w);
                right = mid_w -1;
            }
            else{
                left = mid_w + 1;
            }
        }

        return min_w;
    }
};