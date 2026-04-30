/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
중복 없는 배열 candidates, int target 있다
candidates에서 요소들 합이 target이 되는 여러 조합들을 배열 형태로 출력
배열의 각 숫자들 여러 번 사용 가능
*/


class Solution {
public:
    vector<vector<int>> answer;
    vector<int> comb;
    void dfs(vector<int>& candidates, int start ,int target) {
        if(target == 0) {
            answer.push_back(comb);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            // 다음 경우의 수가 target보다 큰 경우 -> 선택 불가
            if(candidates[i] > target) continue;
            comb.push_back(candidates[i]);
            // 요소 여러 번 쓰니까 재귀 시작점 i부터 다시 시작
            dfs(candidates,i,target - candidates[i]);
            //targett==0이 안되면
            comb.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        return answer;
    }
};