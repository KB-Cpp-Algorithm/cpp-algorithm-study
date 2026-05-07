/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : DFS, 트리                                KK KK    BB  BB */
/* Time Complexity   : O(n)                                     KKKKK    BBBBB  */
/* Space Complexity  : O(h)                                     KK KK    BB  BB */
/* Note              :                                          KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = INT_MAX;

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int cnt) {
        if (root == nullptr) {
            return;
        }
        
        // 리프 노드(Leaf Node) 판별
        if (root->right == nullptr && root->left == nullptr) {
            ans = min(ans, cnt + 1);
            return;
        }
        
        dfs(root->right, cnt + 1);
        dfs(root->left, cnt + 1);
    }
};
