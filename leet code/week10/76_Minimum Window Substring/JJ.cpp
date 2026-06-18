/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 슬라이딩 윈도우(투포인터)               KK KK    BB  BB  */
/* Time Complexity   : O(s + t)                                KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

//윈도우를 확장하면서 문자를 늘려가고 t의 문자를 포함하게 되면 left를 움직여 윈도우를 줄이기
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t){
        //need : t 값 저장
        //window : s[left~right] 구간 안에 들어있는 문자 개수 저장
        unordered_map<char, int> need, window;

        //t에 들어있는 문자의 종류와 그 개수 저장
        for(int i = 0; i < t.size(); i++)
            need[t[i]]++;
        
        
        int required = need.size(); //만족해야 하는 문자 종류의 수
        
        //need[A] = 2일 때, window[A] = 2가 될 때 satisfied++
        int satisfied = 0; //현재 윈도우에서 need 조건을 만족한 문자 종류의 수

        
        int left = 0; //윈도우 왼쪽
        int minLen = 1000000; //조건 만족하는 최소 윈도우 길이
        int subIdx = -1; //최소 윈도우의 첫 인덱스

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++; //윈도우에 문자 c 저장

            //윈도우에서 c의 개수가 필여한 개수가 같아지면
            //if (need.count(c) && window[c] == need[c])
                //satisfied++;
            if (window[c] == need[c])
                satisfied++;

            //satisfied == requred -> 윈도우는 현재 t의 문자를 전부 포함하고 있음    
            while (satisfied == required) {

                //윈도우 길이가 minLen보다 짧으면 갱신
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    subIdx = left;
                }

                //left를 줄이기 위해 left에 대응되는 문자 삭제
                char temp = s[left];
                window[temp]--;

                //조건 검사
                if (window[temp] < need[temp])
                    satisfied--;
                //left 이동
                left++;
            }
        }

        if (subIdx == -1)
            return "";
        else
            return s.substr(subIdx, minLen);
    }
};


int main(void)
{
    Solution sol;
    string s = sol.minWindow("ADOBECODEBANC", "ABC");
    string s2 = sol.minWindow("a", "a");
    string s3 = sol.minWindow("a", "aa");

    cout << s << '\n' << s2 << '\n' << s3 << '\n';
}