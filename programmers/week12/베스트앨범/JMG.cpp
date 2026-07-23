#include <bits/stdc++.h>

using namespace std;

// 500^2 x log500 널널
// 장르 별 먼저 -> 장르 안에서 재생 수 큰 노래 2개
// 요청 시간 기준 정렬
bool compare_request(vector<int> i, vector<int> j) {
    // 요청 시간이 같으면 작업 번호 작은 순
    if (i[0] == j[0]) {
        return i[2] < j[2];
    }

    return i[0] < j[0];
}

// 대기 중인 작업 정렬
// 소요 시간 -> 요청 시간 -> 작업 번호 순
bool compare_wait(vector<int> i, vector<int> j) {
    // 소요 시간이 같으면 요청 시간 빠른 순
    if (i[1] == j[1]) {
        // 요청 시간도 같으면 작업 번호 작은 순
        if (i[0] == j[0]) {
            return i[2] < j[2];
        }

        return i[0] < j[0];
    }

    // 소요 시간 짧은 작업 우선
    return i[1] < j[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // jobs[i] = { 요청 시간, 소요 시간, 작업 번호 }
    for (int i = 0; i < jobs.size(); i++) {
        jobs[i].push_back(i);
    }

    // 요청 시간 빠른 순으로 정렬
    sort(jobs.begin(), jobs.end(), compare_request);

    vector<vector<int>> wait_jobs;

    int time = 0;
    int job_idx = 0;
    int done = 0;

    while (done < jobs.size()) {
        // 현재 시간까지 들어온 작업 모두 넣기
        while (job_idx < jobs.size() && jobs[job_idx][0] <= time) {
            wait_jobs.push_back(jobs[job_idx]);
            job_idx++;
        }

        // 현재 대기 중인 작업이 없으면
        if (wait_jobs.empty()) {
            // 다음 작업 요청 시간으로 이동
            time = jobs[job_idx][0];
            continue;
        }

        // 대기 중인 작업 우선순위대로 정렬
        sort(wait_jobs.begin(), wait_jobs.end(), compare_wait);

        // 가장 앞의 작업 실행
        vector<int> now_job = wait_jobs[0];
        wait_jobs.erase(wait_jobs.begin());

        // 작업 수행 시간만큼 현재 시간 증가
        time += now_job[1];

        // 반환 시간 = 끝난 시간 - 요청 시간
        answer += time - now_job[0];

        done++;
    }

    return answer / jobs.size();
}