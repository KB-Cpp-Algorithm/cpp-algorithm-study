/********************************************************************************/
/* File Name         : LYJ.cpp                                                  */
/* By                : yoonjeong                               KK  KK   BBBBB   */
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
    int minDepth(TreeNode* root) {
        // 1. 애초에 아무것도 없는 빈 트리라면 깊이는 0입니다.
        if (root == nullptr) {
            return 0;
        }
        
        // 2. 양쪽 자식이 모두 없는 '진짜 리프 노드'에 도착했다면, 
        // 자기 자신(1칸)의 깊이인 1을 반환합니다.
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        // 3. [함정 방어!] 한쪽 자식만 비어있는 경우
        // 여기서 탐색을 멈추면 안 되고, 반드시 자식이 남아있는 반대쪽 길로 끝까지 파고들어야 합니다.
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        // 4. 양쪽 자식이 모두 멀쩡하게 있다면?
        // 왼쪽 길과 오른쪽 길을 모두 가보고, 더 짧은(min) 경로를 선택해 반환합니다.
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};