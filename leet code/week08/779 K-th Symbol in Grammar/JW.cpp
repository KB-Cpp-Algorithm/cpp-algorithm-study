/******************************************************************************/
/* File Name        : 779.cpp                                                 */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : Recursion                           KK  KK    BB  BB    */
/* Time Complexity  : O(n)                                KKKKK     BBBBB     */
/* Space Complexity : O(n)                                KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    int dfs(int n, int k) {
        
        // 첫 번째 행은 항상 0, base case
        if (n == 1) {
            return 0;
        }
        
        // 부모의 노드 위치 
        int parent = dfs(n - 1, (k + 1) / 2);
        
        // 짝수 위치일 경우 부모의 값을 뒤집어 줌
        if (k % 2 == 0) {
            if (parent == 0)
                return 1;
            else
                return 0;
            // return parent ^ 1;
        } else
            return parent;
    }
    
    int kthGrammar(int n, int k) { return dfs(n, k); }
};
