/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Tree, BFS                               KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 코테에서 포인터가 맞아..?               KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int minDepth(TreeNode* root) {
        int result = 0;
        // 루트 포인터가 가르키는 주소가 없을 경우
        if (root == nullptr) {
            return result;
        }

        queue<pair<TreeNode*, int>> q;
        // 깊이 1부터 시작
        q.push({root, 1});

        while (!q.empty()) {
            TreeNode* currentNode = q.front().first;
            int currentDepth = q.front().second;
            q.pop();

            // 현재 노드의 왼쪽 포인터와 오른쪽 포인터 모두 가르키는 값이 없을
            // 경우 -> 리프 노드로 판별 left 포인터에 저장된 주소가 없음 right
            // 포인터에 저장된 주소도 없음
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                result = currentDepth;
                break;
            }

            // 둘 중에서 어느 포인터는 가르키는 주소 값이 존재함
            // 즉, 자식 노드가 있음

            // 왼쪽 포인터가 가르키는 값이 있으므로 리프 노드가 아님
            if (currentNode->left != nullptr) {
                q.push({currentNode->left, currentDepth + 1});
            }
            // 오른쪽 포인터가 가르키는 값이 있으므로 리프 노드가 아님
            if (currentNode->right != nullptr) {
                q.push({currentNode->right, currentDepth + 1});
            }
        }

        return result;
    }
};