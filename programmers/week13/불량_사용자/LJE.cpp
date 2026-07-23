#include <bits/stdc++.h>
using namespace std;

// 1. user가 banned와 일치하는지 확인하는 함수
bool isMatch(const string& user, const string& banned) {
    // 길이가 다르면 같을 수 없음
    if (user.length() != banned.length()) return false;
    
    // 글자 하나씩 비교
    for (int i = 0; i < user.length(); i++) {
        // '*' 문자는 모든 글자와 매칭되니까 coninue
        if (banned[i] == '*') continue;
        
        // '*'가 아닌데 문자가 다르면 매칭 x 
        if (user[i] != banned[i]) return false;
    }
    
    // 모든 글자가 조건에 맞으면 true
    return true;
}

// 2. DFS로 모든 조합을 찾는 함수
void dfs(int idx, 
         const vector<string>& user_id, 
         const vector<string>& banned_id, 
         vector<string>& current, 
         vector<bool>& visited, 
         set<vector<string>>& unique_sets) {
    
    // base case: 모든 banned_id 패턴에 대해 매칭되는 user_id를 하나씩 선택한 경우
    if (idx == banned_id.size()) {
        vector<string> temp = current;
        
        // 순서가 달라도 동일한 구성이면 같은 목록으로 처리해야 하므로 정렬
        sort(temp.begin(), temp.end());
        
        // set에 넣어 중복 제거
        unique_sets.insert(temp);
        return;
    }

    // 모든 user_id를 순회하며 현재 banned_id[idx] 패턴과 매칭 시도
    for (int i = 0; i < user_id.size(); i++) {
        // 아직 선택되지 않았고, 패턴 조건에 맞는지 확인
        if (!visited[i] && isMatch(user_id[i], banned_id[idx])) {
            //방문 처리
            visited[i] = true;                
            current.push_back(user_id[i]);     
            
            dfs(idx + 1, user_id, banned_id, current, visited, unique_sets); 
            
            //백트래킹
            current.pop_back();                
            visited[i] = false;                
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    set<vector<string>> unique_sets;              // 중복 없는 제재 아이디 목록 
    vector<bool> visited(user_id.size(), false);  // user_id 사용 여부 체크 배열
    vector<string> current;                       // 현재 탐색 중인 제재 아이디 조합

    // 0번 banned_id 패턴부터 탐색 시작
    dfs(0, user_id, banned_id, current, visited, unique_sets);

    // 구한 조합의 개수 반환
    return unique_sets.size();
}
