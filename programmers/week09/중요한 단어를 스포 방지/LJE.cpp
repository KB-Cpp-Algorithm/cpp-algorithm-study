/********************************************************************************/
/* File Name         : LJE.cpp                                                   */
/* By                : jieun                                  KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 문자열 처리 문제 더 많이 풀어보기..             KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct WordInfo{
    string text;
    int start;
    int end;
    bool is_spoiler;
};

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int n = message.size();
    
    //1. 각 인덱스가 스포일러 구간에 속하는가?
    vector<bool> is_spoiler_idx(n, false);
    for(const auto& range: spoiler_ranges){
        for(int i = range[0]; i <= range[1]; i++){
            is_spoiler_idx[i] = true;
        }
    }
    
    //2. 메세지에서 단어 뽑기
    vector<WordInfo> words;
    unordered_set<string> normal_words; //일반 구간에 나온 단어 저장
    int i = 0; 
    while(i < n){
        //공백이면 건너뛰기
        if(message[i] == ' '){
            i++;
            continue;
        }
        
        //단어의 시작점
        int start_idx = i;
        string current_word = "";
        bool has_spoiler = false;
        
        //공백이 아닐 때까지 글자 추가
        while(i < n && message[i] != ' '){
            current_word += message[i];
            //글자가 하나라도 spoiler 구간에 잇으면 spoiler 단어
            if(is_spoiler_idx[i]){
                has_spoiler = true;
            }
            i++;
        }
        //현재 end_idx는 공백 문자
        int end_idx = i -1;
        
        //단어 정보 저장
        words.push_back({current_word, start_idx, end_idx, has_spoiler});
        
        //단어 중 한글자도 스포일러 구간에 해당하지 않는다면 일반 구간 단어
        if(!has_spoiler){
            normal_words.insert(current_word);
        }
    }
    
    //3. 스포일러 구간을 왼->오 방향으로 돌면서 중요한 단어 수 세기
    int important_count = 0;
    unordered_set<string> visited_spoiler_words; //이미 공개된 스포일러 단어
    
    for(const auto& range: spoiler_ranges){
        int r_start = range[0];
        int r_end = range[1];
        
        //현재 스포일러 구간과 겹치는 단어를 확인
        for(const auto& word: words){
            //스포일러 단어면서 현재 구간과 인덱스 겹치는지
            if(word.is_spoiler && (word.start<= r_end && word.end >= r_start)){
                
                //중요 단어 조건: 일반 구간에 없어야하고 이전에 공개된 적 x
                if(normal_words.find(word.text) == normal_words.end() 
                && visited_spoiler_words.find(word.text) == visited_spoiler_words.end()){
                    important_count++;
                }
                
                //조건 만족하지 않아도 공개된 단어 리스트에 추가해야함!!
                visited_spoiler_words.insert(word.text);
            }
        }
    }
    return important_count;
}