/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : bitmasking                              KK KK    BB  BB  */
/* Time Complexity   : O(n * 한 원소의 최대 길이 + n^2              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 시간 초과로 실패, 비트 마스킹 생각하는데에 ai 사용 KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        //각 단어마다 어떤 알파벳이 있는지 비트마스킹으로 표현
        //총 26개의 알파벳이 있으므로 26비트 필요, int로 커버 가능
        vector<int> masks(words.size(),0);

        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                //charactor - 'a': 0 ~ 25
                //or 연산으로 비트값 누적
                masks[i] |= (1 << (words[i][j]-'a'));
            }
        }

        int max_len = 0;
        for(int i = 0; i < masks.size(); i++){
            for(int j = i+1; j < masks.size(); j++){
                //&연산의 결과가 0이면 값이 같은 비트가 없다는 뜻 -> 공통된 문자가 없다!
                if((masks[i] & masks[j]) == 0){
                    max_len = max(max_len, (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return max_len;
    }
};