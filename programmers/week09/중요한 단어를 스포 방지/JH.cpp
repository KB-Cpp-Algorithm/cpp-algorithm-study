/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int startPos, endPos;
string currentWord;
unordered_set<string> spoWord, notSpoWord;

void init() {
    startPos = 0;
    endPos = 0;
    currentWord.clear();
    spoWord.clear();
    notSpoWord.clear();
}

void check(const vector<vector<int>>& spoiler_ranges) {
    // 비어있을 경우
    if (currentWord.empty()) return;

    // 스포 방지 기능이 적용됬는지
    bool isSpoiler = false;

    for (const auto& spoiler_range : spoiler_ranges) {
        // 해당 단어의 구간이 현재 스포 방지 구간과 곂치지 않을 경우
        // 다음 스포 방지 구간으로 패스
        if (endPos < spoiler_range[0] || spoiler_range[1] < startPos) continue;
        // 스포 방지 구간에 곂쳐서 스포 방지 기능 적용
        isSpoiler = true;
        break;
    }

    // 스포 방지 기능 O
    if (isSpoiler) {
        // 일반 단어에 없을 경우
        if (!notSpoWord.count(currentWord)) {
            // 스포 방지 단어로 추가
            spoWord.insert(currentWord);
        }
    }
    // 스포 방지 기능 X
    else {
        // 스포 방지 단어에 있을 수 있으니 일단 제거
        spoWord.erase(currentWord);
        // 일반 단어에 추가
        notSpoWord.insert(currentWord);
    }
}

int solution(string message, vector<vector<int>> spoiler_ranges) {
    // 전역변수 초기화
    init();

    for (int i = 0; i < message.size(); i++) {
        // 등장 단어
        char ch = message[i];

        // 공백이 아닐 경우
        if (ch != ' ') {
            // 문자열이 비어 있을 경우, 시작 지점으로 설정
            if (currentWord.empty()) startPos = i;
            // 단어 누적
            currentWord += ch;
            // 끝 지점 갱신
            endPos = i;
        }
        // 공백이 등장했을 경우
        else {
            // 중요한 단어인지 체크
            check(spoiler_ranges);
            // 현재 문자열 초기화
            currentWord.clear();
        }
    }

    // 남아있는 마지막 단어도 처리
    check(spoiler_ranges);

    // 중요한 단어의 수
    return (int)spoWord.size();
}