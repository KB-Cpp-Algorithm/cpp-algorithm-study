#include <bits/stdc++.h>

using namespace std;

// 장르 안 노래 정렬
bool compareSong(pair<int, int> a, pair<int, int> b) {
    // 재생 횟수가 같으면 고유 번호 오름차순
    if (a.first == b.first) {
        return a.second < b.second;
    }

    // 재생 횟수 내림차순
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 장르별 전체 재생 횟수
    map<string, int> totalPlay;

    // 장르별 노래 목록
    // pair<int, int> = 재생 횟수, 고유 번호
    map<string, vector<pair<int, int>>> genreSongs;

    for (int i = 0; i < genres.size(); i++) {
        string genre = genres[i];

        totalPlay[genre] += plays[i];
        genreSongs[genre].push_back({plays[i], i});
    }

    // 장르 전체 재생 횟수 기준 정렬하기 위한 벡터
    // 전체 재생 횟수, 장르 이름
    vector<pair<int, string>> genreReorder;

    for (auto& [genre, total] : totalPlay) {
        genreReorder.push_back({total, genre});
    }

    // 장르 전체 재생 횟수 내림차순
    sort(genreReorder.begin(), genreReorder.end(),
         [](pair<int, string> a, pair<int, string> b) {
             return a.first > b.first;
         });

    // 재생 횟수가 높은 장르부터 확인
    for (auto& [total, genre] : genreReorder) {
        vector<pair<int, int>>& songs = genreSongs[genre];

        // 장르 안 노래 정렬
        sort(songs.begin(), songs.end(), compareSong);

        // 장르별 최대 2곡
        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}