/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Priority Queue, Map                     KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 더 효율적인 아이디어가 존재             KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> completed;
        unordered_map<char, int> um;
        priority_queue<pair<int, char>> pq;

        // 각 작업의 빈도 저장
        // "작업명" = 작업량
        for (const char& task : tasks) {
            um[task]++;
        }

        // 남은 작업량을 기준
        for (const auto& p : um) {
            // {작업량, 작업명}
            pq.push({p.second, p.first});
        }

        while (!pq.empty()) {
            vector<pair<int, char>> temp;

            // 주기
            for (int i = 0; i < n + 1; i++) {
                // 꺼낼 수 있는 작업이 있을 경우
                if (!pq.empty()) {
                    // 작업량이 많은 작업 꺼내기
                    pair<int, char> task = pq.top();
                    pq.pop();
                    // 작업 수행
                    completed.push_back(task.second);
                    task.first--;
                    // 완료된 작업이 아닐 경우
                    if (task.first > 0) {
                        temp.push_back(task);
                    }
                }
                // 주기 안에 모든 작업을 완료했을 경우
                else {
                    // 다음 주기에 수행할 작업이 없는 경우
                    if (temp.empty()) break;
                    // 다음 주기에 작업이 남아있기 때문에
                    // 현재 주기 내 잔여 시간은 idle 처리
                    completed.push_back('I');
                }
            }

            // 수행할 작업이 있을 경우
            for (const auto& task : temp) {
                pq.push(task);
            }
        }

        return completed.size();
    }
};