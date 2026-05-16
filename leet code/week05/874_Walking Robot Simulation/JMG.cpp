/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

// 위치했던 좌표들 배열에 저장
// 반복문(배열 순회){
//     answer = max(각 요소들 sqrt(cur[0]) + sqrt(cur[1]))
// }
// 

//test case 2 실패 -> k칸 한 번에 이동해서 에러
// ex) nr = nr + k;
// -> nr,nc가 다음에 이동할 칸 검사해서 obstacles 좌표랑 같은지 확인을 안해서 에러 발생

// 3번째 실패
// Time Limit Exceeded
// 45 / 51 testcases passed
// -> 전체 장애물 전부 순회하는 반복문이 문제 -> set에 저장
class Solution {
public:
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> nodes;

        set<pair<int,int>> obstacle_nodes;

        for(auto obs : obstacles) {
            obstacle_nodes.insert({obs[1], obs[0]});
        }
        //북쪽 기본(0 : 북, 1 : 동, 2 : 남, 3 : 서)
        int now_dir = 0;
        int nr = 0;
        int nc = 0;

        int answer = 0;

        for(int k : commands) {
            if(k == -1) {
                if(now_dir == 3) now_dir = 0;
                else now_dir +=1;
                continue;
            }
            if(k == -2) {
                if(now_dir == 0) now_dir = 3;
                else now_dir -= 1; 
                continue;
            }
            // 방향 별 이동
            for(int i = 0; i<k; i++) {
                //장애물 검사 필요
                int next_r = nr;
                int next_c = nc;

                if(now_dir == 0) next_r++;
                if(now_dir == 1) next_c++;
                if(now_dir == 2) next_r--;
                if(now_dir == 3) next_c--;

                if(obstacle_nodes.count({next_r, next_c})) break;

                // for(vector<int> ob : obstacles) {
                //     // next_r을 x축 좌표로 헷갈려서 에러 발생 
                //     if(next_c == ob[0] && next_r == ob[1]) {
                //         flag = false;
                //         break;
                //     }
                // }

                nr = next_r;
                nc = next_c;
            }
            nodes.push_back({nr,nc});
        }
        for(int i = 0; i < nodes.size(); i++) {
            int x = nodes[i][0];
            int y = nodes[i][1];
            int cur = x*x + y*y;
            answer = max(answer, cur);
        }

        return answer;
    }
};