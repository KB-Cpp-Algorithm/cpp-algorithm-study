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

 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        //예외 처리
        if(root == nullptr)
            return 0;
        //BFS를 돌리기 위한 큐 선언
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));

        //제일 짧은 깊이의 리프노드를 찾아야 함. -> 최단거리는 BFS
        while(!q.empty()){
            TreeNode* tempNode = q.front().first;
            int tempDepth = q.front().second;
            q.pop();

            //자식 노드 유무 확인.
            //nullptr이면 자식이 없다는 뜻(리프노드)이므로 depth 리턴 후 종료
            if(tempNode->left == nullptr && tempNode->right == nullptr)
                return tempDepth;

            //자식 노드 있으면 큐에 넣고 이어서 탐색할 수 있도록 함
            if(tempNode-> left != nullptr)
                q.push(make_pair(tempNode->left, tempDepth + 1));

            if(tempNode-> right != nullptr)
                q.push(make_pair(tempNode->right, tempDepth + 1));
        }
       return 0;
    }
};

int main(void)
{
    Solution sol;

    //root = [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << sol.minDepth(root) << '\n';

    //root = [2,null,3,null,4,null,5,null,6]
    TreeNode* root2 = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(4);
    root2->right->right->right = new TreeNode(5);
    root2->right->right->right->right = new TreeNode(6);
    cout << sol.minDepth(root2) << '\n';
}