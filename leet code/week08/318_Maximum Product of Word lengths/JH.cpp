/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Bitmasking                              KK KK    BB  BB  */
/* Time Complexity   : O(n * L + n^2)                          KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

/*
    - words에 포함된 단어는 최대 1000개
    - 각 단어의 길이는 최대 1000
    - 두 단어를 선택할 때, 약 500,000
    - 선택된 단어를 비교할 때, 1000 * 1000 -> 1,000,000
    - 50만 * 100만 = 5000억..?

*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int answer = 0;
        int N = words.size();

        // 0으로 초기화 수행, 즉 모든 비트가 꺼져있는 상태로
        vector<int> masks(N, 0);

        for (int i = 0; i < N; i++) {
            for (const char& ch : words[i]) {
                // 몇 번째 비트인지 결정하기 위함
                int index = ch - 'a';
                // or 연산으로 비트 값 누적
                masks[i] = masks[i] | (1 << index);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                // & 연산을 적용했는데 비트가 1인 부분이 있을 경우, 공통된
                // 문자를 가지는 것 1개라도 공통된 문자를 가질 경우
                if ((masks[i] & masks[j]) != 0)
                    continue;
                // 두 문자열의 길이를 곱한 결과
                int multiSize = words[i].size() * words[j].size();
                answer = max(answer, multiSize);
            }
        }

        return answer;
    }
};