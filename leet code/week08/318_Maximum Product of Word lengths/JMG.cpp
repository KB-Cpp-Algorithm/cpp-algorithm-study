/******************************************************************************/
/* File Name        : 318.cpp                                                 */
/* By               :                                     KK   KK   BBBBB     */
/* Algorithm        : 비트마스킹                          KK  KK    BB  BB    */
/* Time Complexity  : O(N^2)                              KKKKK     BBBBB     */
/* Space Complexity :                                     KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/    
#include <bits/stdc++.h>

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int answer = 0;
        int n = words.size();

        // 각 단어가 가진 알파벳 정보 비트마스크로 저장
        vector<int> masks(n, 0);

        for(int i = 0; i < n; i++) {
            int mask = 0;

            for(char c : words[i]) {
                // "|=" (OR 연산자)
                // gpt 힌트! 
                // a -> 0번 비트, b -> 1번 비트에 푸쉬
                mask |= (1 << (c - 'a'));
            }

            masks[i] = mask;
        }

        // 모든 단어 쌍 확인
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                // 공통 문자 아예 없으면
                if((masks[i] & masks[j]) == 0) {
                    int cur = words[i].length() * words[j].length();
                    answer = max(answer, cur);
                }
            }
        }

        return answer;
    }
};

