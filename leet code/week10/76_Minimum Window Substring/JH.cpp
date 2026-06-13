/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Sliding Window                          KK KK    BB  BB  */
/* Time Complexity   : O(N + M)                                KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 가변 슬라이딩 윈도우도 있다!            KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int window[123];
    int required[123];

    string minWindow(string s, string t) {
        // 전체 문자 수는 s가 t보다 크거나 같아야 함
        if (s.size() < t.size()) {
            return "";
        }

        // t가 요구하는 최소 문자를 저장
        for (const char& ch : t) {
            required[ch]++;
        }

        // 왼쪽 포인터
        int left = 0;
        // 일치하는 문자 수
        int matchedCnt = 0;
        // 최소 윈도우의 시작 인덱스
        int startIndex = 0;
        // 최소 윈도우의 길이
        int minLength = INT_MAX;

        // 오른쪽 포인터
        for (int right = 0; right < s.size(); right++) {
            // 오른쪽 포인터의 문자
            char rightChar = s[right];
            // 윈도우에 추가
            window[rightChar]++;

            // 추가한 문자가 필요한 문자였을 경우
            // cf) window[rightChar] > required[rightChar]일 경우
            // 필요 이상의 문자이므로 매치를 증가시키면 안 됨
            if (window[rightChar] <= required[rightChar]) {
                matchedCnt++;
            }

            // 윈도우에 필요한 문자가 모두 모였을 경우
            while (matchedCnt == t.size()) {
                // 윈도우의 길이
                int windowLength = right - left + 1;

                // 최소 윈도우 갱신
                if (windowLength < minLength) {
                    minLength = windowLength;
                    startIndex = left;
                }

                // 왼쪽 포인터의 문자
                char leftChar = s[left];
                // 윈도우에서 제거
                window[leftChar]--;

                // 필요 문자에서 빠졌을 경우
                if (window[leftChar] < required[leftChar]) {
                    matchedCnt--;
                }

                // 왼쪽 포인터 증가
                left++;
            }
        }

        // 조건을 만족하는 윈도우가 없을 경우
        if (minLength == INT_MAX) {
            return "";
        }

        // 최소 윈도우 반환
        return s.substr(startIndex, minLength);
    }
};