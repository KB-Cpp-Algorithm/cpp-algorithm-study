/********************************************************************************/
/* File Name         : 1931-meetingRoom.cpp                                     */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : Greedy / Sorting                        KK KK    BB  BB  */
/* Time Complexity   : O(N * logN)                             KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 회의의 (종료 시간, 시작 시간) 정보를 담을 벡터 (Space Complexity: O(N))
vector<pair<int, int>> v;

int main(void){
    // C++ 입출력 속도 향상을 위한 Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt=0;
    cin >> n;

    // 회의 정보 입력
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;

        // C++의 pair는 첫 번째 원소(first)를 기준으로 먼저 정렬됩니다.
        // 따라서 '종료 시간'을 기준으로 오름차순 정렬하기 위해 
        // (종료 시간 b, 시작 시간 a) 순서로 순서를 뒤집어서 벡터에 삽입합니다.
        v.push_back(make_pair(b, a));
    }

    // 오름차순 정렬 (Time Complexity: O(N \log N))
    // 1순위: 빨리 끝나는 순, 2순위: (종료시간이 같다면) 빨리 시작하는 순
    sort(v.begin(), v.end());

    // 현재 시간을 0으로 초기화 (아직 아무 회의도 진행하지 않은 상태)
    int time = 0;

    // 가장 일찍 끝나는 회의부터 순서대로 탐색 (Greedy)
    for(int i=0; i<n; i++){
        // 현재 시간(이전에 선택한 회의가 끝난 시간)보다 
        // 탐색 중인 회의의 시작 시간(v[i].second)이 크거나 같다면, 그 회의를 진행할 수 있음
        if(time <= v[i].second){
            time = v[i].first; // 현재 시간을 진행한 회의의 종료 시간으로 업데이트
            cnt++;             // 진행할 수 있는 회의 개수 1 증가
        }
    }

    // 최대로 진행할 수 있는 회의의 수 출력
    cout << cnt;
}