#include <bits/stdc++.h>
using namespace std;

//a가 b보다 크면 true -> a가 앞으로
bool compare1(const pair<int,int>& a, const pair<int, int>& b){
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

bool compare2(const pair<string,int>& a, const pair<string,int>& b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = plays.size();

    //**장르별 총 노래 재생 횟수(1번 조건: 가장 많이 재생된 장)
    unordered_map<string, int> plays_per_genres;
    
    //**{고유번호, plays}저장후, plays기준으로 내림차순 정렬
    vector<pair<int,int>> sorted_plays;
    
    for(int i = 0; i < n; i++){
        sorted_plays.push_back({i, plays[i]});
    }
    
    //plays가 큰 거 먼저, 같다면 고유번호가 낮은 거 먼저-> compare1
    sort(sorted_plays.begin(), sorted_plays.end(), compare1);
    
    //**장르별 top2 (plays, 고유 변호)
    unordered_map<string, vector<pair<int,int>>> top2;
    
    for(int i = 0; i < n; i++){
        int original_idx = sorted_plays[i].first;  // 원래 노래의 고유 번호
        int play_count = sorted_plays[i].second;   // 재생 횟수
        string genre = genres[original_idx];       // 진짜 고유 번호에 매칭되는 장르!
    
        if(top2[genre].size() < 2) {    //top2만 저장
            top2[genre].push_back({play_count, original_idx});
        }
        
        plays_per_genres[genre] += play_count;
    }
    
    //장르별 총 노래 재생 횟수를 벡터로(value 기준 정렬 위함)
    vector<pair<string, int>> vec(plays_per_genres.begin(), plays_per_genres.end());
    
    //value 기준으로 정렬
    sort(vec.begin(), vec.end(), compare2);
    
    // return할 vector
    vector<int> answer;
    
    for(const auto& v: vec){
        for(const auto& c: top2[v.first]){
            answer.push_back(c.second);
        }
    }
    
    return answer;
}
