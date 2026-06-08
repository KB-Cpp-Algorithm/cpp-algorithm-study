/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 문자열,구현                             KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 단어 파싱, 범위 계산, 중복 검사         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

// message를 단어 단위 파싱
// 마지막으로 공개된 단어 스포일러 단어인지 확인
// 스포 공개될 떄 2개 이상 단어가 같이 공개되는데 두 단어가 같은 단어면 둘 다 중요한 단어 처리 필요 - 예외
//      [special]
//    [spo]
//        [spo]
//     [   spo   ]
//             [spo]

struct word_info {
    string word;
    int start;
    int end;
};


int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    vector<word_info> words;
    
    int n = message.size();
    int index = 0;
    
    // 단어 파싱
    while(index < n) {
        
        // 공백
        while(index < n && message[index] == ' ') {
            index++;
        }
        // message 마지막 단어에 공백 있으면 종료
        if(index >= n) break;
        
        int start = index;
        string word ="";
        // 단어 추가
        while(index < n && message[index] != ' ') {
            word += message[index];
            index++;
        }
        // index가 공백에 위채해서
        int end = index - 1;
        
        words.push_back({word,start,end});
    }
    
    int spo_cnt = spoiler_ranges.size();
    
    
    // spo에 한 번도 안 걸린 단어
    unordered_set<string> normal_words;
    // 스포일러 오픈할 때 공개되는 단어들
    vector<vector<string>> special_word_candidates(spo_cnt); 
    
    for(auto word : words) {
        // 스포 단어 언제 공개되는지 확인 필요해서 int형
        int tmp_spo = -1;
        for(int i = 0; i < spo_cnt; i++) {
            
            int spo_start = spoiler_ranges[i][0];
            int spo_end = spoiler_ranges[i][1];
            
            // 단어 - 스포 겹치는 구간
            if(word.start <= spo_end && word.end >= spo_start) {
                tmp_spo = i;
            }
        }
        // 단어 1개 다 돌고
        if(tmp_spo == -1) normal_words.insert(word.word);
        else special_word_candidates[tmp_spo].push_back(word.word);
        

    }
    
    // 공개된 스포 단어 저장
    unordered_set<string> reveal_spo_words;
    
    for(int i = 0; i < spo_cnt; i++) {
        for(auto word : special_word_candidates[i]) {
            bool reveal_spo = reveal_spo_words.count(word);
            bool reveal_normal = normal_words.count(word);
            // 예외 처리 - 오답.
            // gpt 도움 -> normal_word도 아니여야 함
            if(!reveal_spo && !reveal_normal) answer++;
            
            // 공개된 것들 기록
            reveal_spo_words.insert(word);
        }
    }
    
    
    
    
    return answer;
}