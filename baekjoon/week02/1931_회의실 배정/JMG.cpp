/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 그리디                                  KK KK    BB  BB  */
/* Time Complexity   : O(N log N)                              KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              : 빨리 끝나느 회의 케이스 세기            KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

// 빨리 종료되는 회의 선택
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int N;
    cin >> N;
    pair<int, int> meeting[100001];

    for (int i = 0; i < N; i++)
    {
        cin >> meeting[i].first >> meeting[i].second;
    }

    // 끝나는 시간 기준으로 정렬 
    sort(meeting, meeting + N, [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second)
            return a.first < b.first;
        // 끝 시간 동일하면 회의시작 빠른 순으로 정렬
        return a.second < b.second;
    });

    int cnt = 0; 
    int last_end = 0;

    // 선택 - 안 겹치는 회의만
    for (int i = 0; i < N; i++)
    {
        if (meeting[i].first >= last_end)
        {
            cnt++;
            last_end = meeting[i].second;
        }
    }  
    
    cout << cnt;
    return 0;
}