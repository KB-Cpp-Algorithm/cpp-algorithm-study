/********************************************************************************************/
/* File Name        : LJE.cpp                                                               */
/* By               : Jieun                                              KK  KK  BBBBB      */
/* Algorithm        : Backtracking                                       KK KK   BB  BB     */
/* Time Complexity  : O(N^(T/M))                                         KKKKK   BBBBB      */
/* Space Complexity : O(T/M)                                             KK KK   BB  BB     */
/* Note             : 중복 선택 허용, idx 고정으로 순서 중복 방지          KK  KK  BBBBB      */
/*                                                                                          */
/********************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, int sum, int target, vector<int>& candidates, vector<int>& temp) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (sum + candidates[i] <= target) {
                temp.push_back(candidates[i]);
                // 중복 선택 가능하므로 다음 재귀에도 i를 그대로 넘김.
                solve(i, sum + candidates[i], target, candidates, temp);
                temp.pop_back(); 
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp;
        solve(0, 0, target, candidates, temp);
        return ans;
    }
};
