#include <bits/stdc++.h>

using namespace std;

set<string> answer_set;
vector<bool> visited;

// 36.4/100 - 실패.....
// banned_id 패턴이 user_id와 맞는지 확인
bool is_match(string user_id, string banned_id) {
    // 길이 다르면 애초에 불가능
    if (user_id.size() != banned_id.size()) {
        return false;
    }

    for (int i = 0; i < user_id.size(); i++) {
        // *은 어떤 문자든 가능
        if (banned_id[i] == '*') {
            continue;
        }

        if (user_id[i] != banned_id[i]) {
            return false;
        }
    }

    return true;
}

void dfs(int depth, vector<string>& user_id,
         vector<string>& banned_id, vector<string>& selected_id) {
    // banned_id 개수만큼 다 골랐으면
    if (depth == banned_id.size()) {
        // 같은 사용자 조합은 순서가 달라도 하나로 처리
        sort(selected_id.begin(), selected_id.end());

        string selected = "";

        // 선택된 아이디들을 하나의 문자열로 만들기
        for (int i = 0; i < selected_id.size(); i++) {
            selected += selected_id[i];
        }

        answer_set.insert(selected);
        return;
    }

    for (int i = 0; i < user_id.size(); i++) {
        // 이미 다른 banned_id에 사용한 아이디면 패스
        if (visited[i]) {
            continue;
        }

        // 현재 불량 사용자 패턴과 안 맞으면 패스
        if (!is_match(user_id[i], banned_id[depth])) {
            continue;
        }

        visited[i] = true;
        selected_id.push_back(user_id[i]);

        dfs(depth + 1, user_id, banned_id, selected_id);

        selected_id.pop_back();
        visited[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    answer_set.clear();
    visited.assign(user_id.size(), false);

    vector<string> selected_id;

    dfs(0, user_id, banned_id, selected_id);

    return answer_set.size();
}