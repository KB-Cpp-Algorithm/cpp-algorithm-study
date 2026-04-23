/********************************************************************************/
/* File Name         : 14889.cpp                                                */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 시뮬레이션, 완전탐색, 조합              KK KK    BB  BB  */
/* Time Complexity   : 스털링 근사 O(((2^N / sqrt(N))) * N^…   KKKKK    BBBBB   */
/* Space Complexity  : O(N^2)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int N;
bool selected[20] = {false, };
int ans = INT_MAX;

void dfs(int person, int cnt, const vector<vector<int>>& v)
{
    //사람이 N/2명이면 스타트와 링크 두 팀의 점수 계산 (탈출 조건)
    if(cnt == N/2){
        vector<int> TStart, TLink;
        
        //두 팀으로 나눔 (선택된 사람 N/2 , 선택 안된 사람 N/2명)
        for(int i = 0; i < N; i++){
            if(selected[i])
                TStart.push_back(i);
            else
                TLink.push_back(i);
        }
        
        int SScore = 0, LScore = 0;
        
        //시너지 점수 계산
        for(int i = 0; i < TStart.size(); i++){
            for(int j = i + 1; j < TStart.size(); j++){
                int a = TStart[i];
                int b = TStart[j];
                SScore += v[a][b] + v[b][a];
            }
        }

        for(int i = 0; i < TLink.size(); i++){
            for(int j = i + 1; j < TLink.size(); j++){
                int a = TLink[i];
                int b = TLink[j];
                LScore += v[a][b] + v[b][a];
            }
        }
        
        //시너지 점수차 최소 갱신
        ans = min(ans, abs(SScore - LScore));
        return;
    }

    //팀에 사람 추가
    for(int i = person; i < N; i++){
        selected[i] = true;
        dfs(i + 1, cnt + 1, v);
        selected[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    
    //점수 시너지 배열 갱신
    vector<vector<int>> v(N, vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
        }
    }
    
    //사람 '0'을 기준으로 잡음. -> 중복 제거
    dfs(0, 0, v);
    cout << ans << '\n';
    
}
