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

/*
가장 많이 남은 task를 우선적으로 스케줄링
이번 사이클(n)동안 쓸 수 있는 task 없으면 idle
*/
class Solution {
public:
    int time = 0;
    int leastInterval(vector<char>& tasks, int n) {
        int answer = 0;
        //맵에 task와 그 빈도 기록
        unordered_map<char, int> um;
        for(int i = 0; i < tasks.size(); i++)
            um[tasks[i]]++;
        
        //map을 이용하여 우선순위 큐에 집어넣기
        priority_queue<pair<int, char>> ready;
        for(auto i : um)
            ready.push(make_pair(i.second, i.first));

        while(!ready.empty()){
            int tempFrequent = ready.top().first;
            char tempTask = ready.top().second;
            ready.pop();
            tempFrequent--;


        }
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