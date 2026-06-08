/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                  KK  KK   BBBBB   */
/* Algorithm         : topological sort(위상정렬)                KK KK    BB  BB  */
/* Time Complexity   : O(V + E)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //자신으로 부터 나가는 방향에 있는 정점들의 리스트
        vector<vector<int>> adj(numCourses);
        vector<int> in_deg(numCourses, 0);
        vector<int> result;
        queue<int> q;

        for(auto pre: prerequisites){
            int pre_c = pre[1];
            int cur_c = pre[0];
            //방향이 out인 edge로 이어져 있는 노드의 리스트
            adj[pre_c].push_back(cur_c);
            
            //in-degree
            in_deg[cur_c]++;
        }

        //1. in-degree 값이 0인 정점 찾아서 큐에 넣기
        for(int i = 0; i < numCourses; i++){
            if(in_deg[i] == 0){
                q.push(i);
            }
        }

        //2. 위상정렬
        while(!q.empty()){

            int cur = q.front();
            q.pop();

            //결과에 추가
            result.push_back(cur);

            for(auto next: adj[cur]){
                in_deg[next]--;
                if(in_deg[next] == 0){
                    q.push(next);
                }
            }
        }

        // cycle이 존재하면 모든 노드를 방문할 수 없음
        if(result.size() < numCourses){
            return false;
        }
        return true;
    }
};