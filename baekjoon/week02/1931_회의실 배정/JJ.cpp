/********************************************************************************/
/* File Name         : 1931.cpp                                                 */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 그리디                                  KK KK    BB  BB  */
/* Time Complexity   : O(NlogN)                                KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{   
    //idea : 제일 빨리 끝나는 회의 위주로 집어서 cnt가 최대가 되게끔. 그러면서 일찍 시작하는 회의 잡기
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, end = 0, cnt = 0;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for(int i = 0; i < N; i++)
        cin >> meetings[i].first >> meetings[i].second;
    
    //끝나는 시간을 기준으로 정렬. 사실 second를 first에 넣어서 정렬을 해도 됐음. (end time, start time) 형태로 저장되게끔
    sort(meetings.begin(), meetings.end(), cmp);

    //마지막 회의가 끝난 시간 <= 배열 속 시작 시간
    for(const auto &m : meetings){
        if(end <= m.first){
            end = m.second;
            cnt++;
        }
    }
    cout << cnt << ' ';
}