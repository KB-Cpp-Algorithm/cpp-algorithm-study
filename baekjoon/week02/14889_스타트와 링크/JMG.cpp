/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : dfs 탐색                                KK KK    BB  BB  */
/* Time Complexity   : O(2^N)                                  KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int S[21][21];

// team_select[i] == true면 start팀으로
bool team_select[21];
int answer = 1000000000;

// 탐 간 점수 차이 계산 함수
void check() {
    //각 팀 능력치 총합
    int start = 0;
    int link = 0;

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            // start팀
            if(team_select[i] && team_select[j]){
                start += S[i][j] + S[j][i];
            }

            // link팀
            if(!team_select[i] && !team_select[j]){
                link += S[i][j] + S[j][i];
            }
        }
    }


    answer = min(answer, abs(start-link));
}


// cnt - 스타트팀 인원 수
void dfs(int index, int cnt){
    // 에러 -> 모든 인원을 다 봤는데도 팀원이 안 찬 경우 종료(ai hint)
    if(index == N) return;
    if(cnt==N/2){
        check();
        return;
    }
    
    
    // index번째 사람 스타트팀 넣기
    team_select[index]=true;
    dfs(index+1,cnt+1);

    // 위에서 스타트팀에 안 넣으면 링크팀으로
    team_select[index]=false;
    dfs(index+1,cnt);
}


int main(){

    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }

    dfs(0,0);

    cout<<answer;
}