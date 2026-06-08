/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     
        vector<vector<int>> arr(numCourses);
        queue<int> q;
        int visitedCnt = 0;
        vector<int> indegree(numCourses, 0);

        for(auto tmp: prerequisites){
            int next = tmp[0];
            int pre = tmp[1];

            arr[pre].push_back(next);
            indegree[next]++;
        }

        //1. indegree개수를 탐색
        //indegree = 0인 노드 cnt에 삽입
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        //2. q가 빌때까지 순환
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            visitedCnt ++;

            for(int next: arr[cur]){
                indegree[next] --;

                if(indegree[next] == 0)
                    q.push(next);
            }
        }
        return visitedCnt == numCourses;
    }
};