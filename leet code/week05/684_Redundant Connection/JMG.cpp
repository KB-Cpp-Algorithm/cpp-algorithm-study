/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : Union-Find                              KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

// 양방향 그래프에서 추가된 제거해도 되는 간선 찾기 - 중복이면 마지막에 발견된 애 출력
// 이미 (간접적으로라도 )연결된 노드 간에 간선 또 발견해야 함
class Solution {
public:
    vector<int> roots; 

    int rootfind(int idx) {
        // 부모가 본인
        if(roots[idx] == idx) return idx;
        // 가장 부모까지 올라가기
        return rootfind(roots[idx]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // 노드 번호 1번 시작이라서
        roots.resize(n + 1);
        // 처음 세팅
        for(int i = 0; i <= n; i++) {
            roots[i] = i;
        }

        // 연결 확인
        for(auto edge : edges) {
            int x = edge[0];
            int y = edge[1];

            int r_x = rootfind(x);
            int r_y = rootfind(y);
            if(r_x == r_y) return edge;
            
            // 부모 다르면 연결
            roots[r_y] = r_x;
        }
        return {};
    }
};