/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Backtracking                            KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 가능한 경우의 수를 담고 있는 2차원 벡터
        vector<vector<int>> result;
        // 현재까지 후보 정수를 담고있는 벡터
        vector<int> current;

        // 효율적인 백트래킹을 위해 오름차순 정렬
        sort(candidates.begin(), candidates.end());

        // 탐색 시작
        go(0, current, candidates, target, result);

        return result;
    }

   private:
   // 현재 위치, 현재까지 누적된 후보 정수 저장 벡터, 후보 정수 벡터, 목표 정수, 결과 반환 벡터
    void go(const int& index, vector<int>& current, const vector<int>& candidates, const int& target, vector<vector<int>>& result) {
        // 목표하던 값에 도달했을 경우
        if (target == 0) {
            // 후보 벡터를 결과 벡터에 저장
            result.push_back(current);
            return;
        }

        // 중복해서 같은 번호를 선택할 수 있기에, index 위치부터 시작
        for (int i = index; i < candidates.size(); i++) {
            // 현재 숫자가 남은 target보다 클 경우
            if (candidates[i] > target) break;
            // 해당 후보 정수 선택
            current.push_back(candidates[i]);
            // 다시 탐색 시작(중복 선택 가능)
            go( i, current, candidates, target - candidates[i], result);
            // 해당 후보 정수 제거(원상복구 -> 백트래킹)
            current.pop_back();
        }
    }
};