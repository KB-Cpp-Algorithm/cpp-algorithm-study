#include <bits/stdc++.h>

using namespace std;
// res는 [start+1,end+1] 
// 투포인터?

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    // 전체 보석 종류 개수
    set<string> all_gems(gems.begin(), gems.end());
    int gem_count = all_gems.size();

    // 현재 구간 안 보석 종류별 개수
    map<string, int> current_gems;

    int left = 0;
    int right = 0;

    // 일단 최대로 크게 설정
    int min_length = gems.size() + 1;

    while (right < gems.size()) {
        // right 위치 보석 구간에 추가
        current_gems[gems[right]]++;
        right++;

        // 현재 구간에 모든 종류의 보석이 있으면
        while (current_gems.size() == gem_count) {
            // 현재 구간 길이 비교
            if (right - left < min_length) {
                min_length = right - left;

                // 문제 번호는 1부터 시작
                // right는 이미 다음 칸을 가리키고 있어서 그대로 사용
                answer = {left + 1, right};
            }

            // 왼쪽 보석 하나 빼고 구간 줄이기
            current_gems[gems[left]]--;

            // 해당 보석이 구간에서 완전히 사라지면 map에서도 제거
            if (current_gems[gems[left]] == 0) {
                current_gems.erase(gems[left]);
            }

            left++;
        }
    }

    return answer;
}