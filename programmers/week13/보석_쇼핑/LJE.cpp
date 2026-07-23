#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    // 1. 전체 보석 종류의 개수
    unordered_set<string> unique_gems(gems.begin(), gems.end());
    int total_kinds = unique_gems.size();

    // 현재 윈도우[left, right] 내부의 보석 카운트용 map
    unordered_map<string, int> us;

    pair<int, int> min_sec = {0, (int)gems.size() - 1};
    int min_len = INT_MAX;
    int left = 0;
    int sz = gems.size();

    for (int right = 0; right < sz; right++) {
        // 윈도우 늘리기
        us[gems[right]]++;

        // 윈도우 내부의 보석 종류 수가 전체 보석 종류 수와 같으면 구간 줄이기
        while (us.size() == total_kinds) {

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_sec = {left, right};
            }

            // 윈도우 줄이기
            us[gems[left]]--;
            
            if (us[gems[left]] == 0) {
                us.erase(gems[left]);
            }

            left++;
        }
    }

    // 1-based index로 변환하여 반환
    return {min_sec.first + 1, min_sec.second + 1};
}
