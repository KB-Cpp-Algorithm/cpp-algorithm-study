/******************************************************************************/
/* File Name        : 684.cpp                                                 */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : Union-Find                          KK  KK    BB  BB    */
/* Time Complexity  : O(N)                                KKKKK     BBBBB     */
/* Space Complexity : O(N)                                KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    // 부모 탐색
    int find(int x, vector<int>& parent) {
        if(parent[x] == x) return x;

        // 부모로 거슬러 올라가며 최상위 조상 업데이트
        return parent[x] = find(parent[x], parent);
    }

    // parent 비교하며 union
    bool unite(int x, int y, vector<int>& parent) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);

        // 조상이 다르면 한쪽으로 편입
        if(rootX != rootY) {
            parent[rootY] = rootX;
            return true;
        } 
        // 조상이 같으면 사이클 발생이므로 false return
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // node 번호가 N번까지이므로 사이즈 + 1
        vector<int> parent(edges.size()+1);
        // 부모 초기화
        for(int i = 0; i<edges.size(); i++) {
            parent[i] = i;
        }

        // 간선 돌면서 연결
        for(auto i : edges) {
            // 두 간선끼리의 unite가 실패 시 사이클 형성 -> 잉여 간선 return
            if(!unite(i[0], i[1], parent)) return i;
        }
        return {};
    }
};
