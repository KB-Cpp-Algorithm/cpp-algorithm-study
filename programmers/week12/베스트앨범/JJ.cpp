#include <bits/stdc++.h>

using namespace std;

/*
장르별 재생 횟수 높은 순으로 내림차순 정렬
각 장르 안의 노래들을 정렬
    1. 재생 횟수 기준 내림차순 정렬
    2. 재생 횟수가 같으면 인덱스 기준 오름차순 정렬
*/

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> genrePlayed; //장르 : 장르별 총 재생 횟수
    unordered_map<string, vector<pair<int, int>>> songList; // 장르 : {재생횟수, 인덱스} 벡터

    for(int i = 0; i < genres.size(); i++){
        genrePlayed[genres[i]] += plays[i]; // 장르별로 총 재생 횟수 더하기
        songList[genres[i]].push_back({plays[i], i}); //장르별 곡 분리. {재생횟수, 인덱스} 저장
    }

    //재생 횟수 높은 순으로 장르 내림차순 정렬
    vector<pair<string, int>> genrePlayedList; //맵은 정렬 못하므로 vector로 복사해야함
    for(auto p : genrePlayed)
        genrePlayedList.push_back({p.first, p.second});
    
    sort(genrePlayedList.begin(), genrePlayedList.end(), [](const auto& a, const auto& b){
        return a.second > b.second; //재생 횟수 내림차순
    });


    //장를 별로 벡터 안의 노래들을 정렬
    for(auto& p : songList){
        sort(p.second.begin(), p.second.end(), [](const auto& a, const auto& b){
            if(a.first == b.first)
                return a.second < b.second; //재생 횟수가 같으면 인덱스 오름차순
            return a.first > b.first; //재생 횟수 내림차순
        });
    }


    //총 재생 횟수가 높은 장르부터 최대 2곡씩 answer에 추가
    for(int i = 0; i < genrePlayedList.size(); i++){
        string Genre = genrePlayedList[i].first;

        for(int j = 0; j < songList[Genre].size() && j < 2; j++) //songList는 벡터를 담은 map
            answer.push_back(songList[Genre][j].second);
    }

    
    return answer;
}