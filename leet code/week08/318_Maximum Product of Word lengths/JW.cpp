/******************************************************************************/
/* File Name        : 318.cpp                                                 */
/* By               : yunjiu                              KK   KK   BBBBB     */
/* Algorithm        : Bit Masking                         KK  KK    BB  BB    */
/* Time Complexity  : O(N^2)                              KKKKK     BBBBB     */
/* Space Complexity : O(N)                                KK  KK    BB  BB    */
/* Note             :                                     KK   KK   BBBBB     */
/*                                                                            */
/******************************************************************************/

class Solution {
public:
    int maxProduct(vector<string>& words) {

        // 비트마스크로 변환한 값을 담을 배열
        vector<int> mask(words.size());

        // 알파벳 -> 비트 마스크 변환
        for (int i = 0; i < words.size(); i++) {
            int msk = 0;

            for (auto j : words[i]) {
                msk |= (1 << (j - 'a'));
            }
            
            mask[i] = msk;
        }

        // 모든 단어 쌍을 탐색하며 최대 곱 찾기
        int max_pro = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                // 공통 문자가 없는 경우
                if ((mask[i] & mask[j]) == 0) {
                    int pro = words[i].length() * words[j].length();
                    max_pro = max(pro, max_pro);
                }
            }
        }
        return max_pro;
    }
};
