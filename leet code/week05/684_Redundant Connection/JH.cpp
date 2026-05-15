/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Union-Find                              KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;
/*
    - N개의 노드를 가지는 트리가 존재(무방향, 번호 1 ~ N)
    - 이때, 간선이 1개 추가되어 트리에 사이클이 형성
    - 간선 정보가 담긴 edges가 주어질 때, 1개만 제거해서 사이클을 제거하기
    - 정답이 여러 개일 경우, 마지막 등장 간선을 반환
*/
class Solution {
   public:
    // 부모 노드 탐색
    int findRootNode(const int& node, vector<int>& parent) {
        // 부모 노드가 없을 경우
        if (parent[node] == node) {
            // 자신의 노드 번호 반환
            return node;
        }
        // 루트 노드에 도착하지 않았을 경우
        // 부모 노드로 재탐색하고 루트 노드로 설정
        return parent[node] = findRootNode(parent[node], parent);
    }

    bool unionNode(const int& x, const int& y, vector<int>& parent) {
        int rootX = findRootNode(x, parent);
        int rootY = findRootNode(y, parent);

        // 두 노드의 루트 노드가 같을 경우
        if (rootX == rootY) {
            // 두 노드가 루트 노드가 같은데 서로를 연결할 경우, 사이클이 발생
            return false;
        }

        // 하나의 루트 노드를 다른 루트 노드 하위로 배치
        parent[rootX] = rootY;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 간선의 수
        int n = edges.size();
        // 각 노드의 부모 노드를 저장할 벡터
        vector<int> parent(n + 1);

        // 각 노드의 부모 노드를 자신으로 초기화
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            if (!unionNode(edge[0], edge[1], parent)) {
                return edge;
            }
        }

        return {};
    }
};