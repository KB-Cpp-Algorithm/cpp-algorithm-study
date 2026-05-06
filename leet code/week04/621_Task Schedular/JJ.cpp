/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<pair<int, char>> ready; //실행할 수 있는 작업 목록 저장하는 큐
        queue<tuple<int, char, int>> wait; //복귀시간, 작업 이름, 남은 횟수

        //맵에 task와 그 빈도 기록
        unordered_map<char, int> um;
        for(int i = 0; i < tasks.size(); i++)
            um[tasks[i]]++;
        
        //map을 이용하여 레디큐(우선순위 큐)에 집어넣기
        for(auto i : um)
            ready.push({i.second, i.first});

        //작업이 다 끝날 때까지(ready, wait큐가 빌때까지) 작업 돌리기
        //ready큐에서 가장 남은 작업 수가 많은 task를 실행. (ready큐에서 빠짐)
        //frequent 수를 줄이고 0이 아니면 wait큐에 저장 후 time++
        //wait큐의 task가 복귀 시간에 도달하면 ready큐로 이동
        //ready큐가 비어있고 wait큐가 비어있지 않으면 idle

        while(!ready.empty() || !wait.empty()){
            //대기큐가 비어있지 않고 현재 시간이 큐 제일 앞에 있는 작업의 복귀 시간에 도달하면 대기큐에서 레디큐로 복귀
            //대기큐는 FIFO이기 때문에 맨 앞 작업의 복귀 시간만 확인하면 됨
            while(!wait.empty() && get<0>(wait.front()) <= time){
                char tempTask = get<1>(wait.front());
                int tempFrequent = get<2>(wait.front());
                wait.pop();
                ready.push({tempFrequent, tempTask});
            }
            
            //레디큐가 비면 대기큐에서 레디큐로 올 수 있는 시간으로 스킵
            if(ready.empty()){
                time = get<0>(wait.front());
                continue;
            }

            //레디큐에서 task 실행
            int tempFrequent = ready.top().first;
            char tempTask = ready.top().second;
            ready.pop();
            //해당 task가 끝났으므로 빈도수--
            tempFrequent--;
            //빈도수가 0이 되면 작업이 아예 끝났다는 의미이므로 대기큐에 푸쉬 x
            if(tempFrequent != 0)
                wait.push({time + n + 1, tempTask, tempFrequent});

            //작업 하나가 아예 끝났으므로 시간 증가
            time++;
        }
        return time;
    }
};

int main(void)
{
    Solution sol;

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};

    cout << sol.leastInterval(tasks, 2) << '\n';
    cout << sol.leastInterval(tasks2, 1) << '\n';
    cout << sol.leastInterval(tasks3, 3) << '\n';
}