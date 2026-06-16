/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                   KK  KK   BBBBB   */
/* Algorithm         : dynamic sliding window                  KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : leetcode 643, 3                         KK  KK   BBBBB   */
/*                                                                             */
/********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //s의 길이보다 t의 길이가 길면 답이 나올 수 없음
        if(s.size() < t.size()) return "";
        
        //찾아야하는 문자와 그 개수 저장 맵
        unordered_map<char, int> window;
        for(int i = 0; i < t.size(); i++){
            window[t[i]]++;
        }

        int answer = INT_MAX;
        //찾아야하는 문자 수(중복 포함)
        int required = t.size();
        int start = -1;

        int left = 0;
        int n = s.size();

        for(int right = 0; right < n; right++){
            char c = s[right];

            //1. 윈도우 확장
            if(window.count(c)){
                window[c]--;
                //위 코드 실행 결과가 음수인 경우는 이미 다 찾았는데 또 있다는 거니까 required 반영 X
                //required를 조건 없이 업데이트해서 틀림
                if(window[c] >= 0) required--;
            }
            
            //2. 답이된다면 left옯김
            while(required == 0){
                //3. 값 업데이트
                if(answer > right-left+1){
                    answer = right-left+1;
                    start = left;
                }

                if(window.count(s[left])){
                    window[s[left]]++;
                    //위의 결과가 양수면 아직 찾아야하는 문자가 더 있다는 거니까 requrired 반영
                    //찾아야하는 글자개수가 생길 때부터 required ++
                    if(window[s[left]] > 0)required++;
                }
                left++;
            }
        }

        if(start == -1) return "";
        return s.substr(start, answer);
    }
};