/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 비트마스킹                              KK KK    BB  BB  */
/* Time Complexity   : O(n * L + n^2)                          KKKKK    BBBBB   */
/* Space Complexity  : O(n)                                    KK KK    BB  BB  */
/* Note              : n: words 크기, L : word 최대 길이       KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*
알파벳 비트 마스킹 (알파벳 C 기준)

1. 알파벳 추가 : |
mask | (1 << 2) : C를 집합에 추가

2. 알파벳 확인 : &
mask & (1 << 2) : C가 포함되어 있는지 확인. 있으면 해당 자리 비트값은 1.


3. 알파벳 제거 : & ~
mask & ~(1 << 2) : C를 집합에서 제거


4. 알파벳 토글 : ^
mask ^ (1 << 2) : C가 있으면 제거, 없으면 추가

5. 포함 개수 : 내장함수
__builtin_popcount(mask) : 현재 체크된 알파벳의 총 개수 확인
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        //각 원소를 26자리 비트로 표현.
        //비트로 표현한 각 원소를 and 연산을 해 0이 되는 단어 쌍 찾기
        //만족하는 것 중 max값 갱신
        int n = words.size();
        vector<int> mask(n, 0);

        //각 words의 string을 26비트 비트로 변환
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        //모든 단어 비교
        int answer = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                //비트연산. and 결과가 0이면 겹치는 단어가 하나도 없다는 의미
                if((mask[i] & mask[j]) == 0){
                    int temp = words[i].size() * words[j].size();
                    answer = max(answer, temp);
                }
            }
        }
        return answer;
    }
};

int main(void)
{
    Solution sol;

    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    vector<string> words3 = {"a", "aa", "aaa", "aaaa"};

    cout << sol.maxProduct(words) << ' ' << sol.maxProduct(words2) << ' ' << sol.maxProduct(words3) << '\n';

}
