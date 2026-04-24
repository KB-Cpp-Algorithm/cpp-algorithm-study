/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

/*
1. 회전 (deque pop_back 후 push_front) 후 N-1 검사. 사람 있으면(1이면) 0으로 만들기
2. back부터 탐색. 사람 있으면 뒤 칸 검사. 사람이 없고 safety가 0이 아니면 현재 0으로 만들고 다음칸 1 set, safety--
3. [0] 검사. 사람 없고 safety 0아니면 1로 만들고 safety--
4. safety가 0이 될 때 cnt++. cnt 변동이 생기면 k 이상 검사. 만족되면 종료

* 1,2번 끝날 때마다 N-1에 사람이 있는지 확인해야함
* safety 값이 변동될 때마다 0됐는지 검사해야함
*/

deque<pair<int, int>> dq;
int N, k, experiment = 1, cntK = 0;
bool flag = true;

//idx N에 사람 여부 검사. 사람이 있으면 true, 없으면 false
bool check(int N) 
{
    if(dq[N].second == 1)
        return true;
    else
        return false;
}

//무빙워크 회전 함수
void rotate() 
{
    int temp = dq.back().first;
    dq.pop_back();
    dq.push_front(make_pair(temp, 0));

    //idx 0부터 시작이므로 N번째 칸은 N-1임. N-1에 사람이 있으면 내리므로 검사 후 있다면 사람 빼주기
    if(check(N-1))
        dq[N-1].second = 0;
}

//사람 이동 함수
void move() 
{
    for(int i = N-2; i >= 0; i--){ //역순으로 이동
        if(check(i)){ //사람이 있으면
            if(!check(i+1) && dq[i+1].first > 0){ //뒤에 사람이 없고 safety 1이상이면
                dq[i].second = 0; //현재 칸 사람이
                dq[i+1].second = 1; //다음 칸으로
                dq[i+1].first -= 1; //다음 칸에 사람이 탔으므로 safety--

                if(dq[i+1].first == 0){ //safety값 체크. 0이 k가 되면 탈출 플래그 셋업
                    cntK++;
                    if(cntK == k){
                        flag = false;
                        return ;
                    } 
                }
                
                if(check(N-1)) //N-1에 사람이 있으면 내리므로 검사 후 있다면 사람 빼주기
                    dq[N-1].second = 0;
            }
        }
    }
}

//사람이 첫 번째 칸(idx = 0)에 타는 함수
void Geton() 
{
    if(!check(0) && dq[0].first != 0){ //첫 칸에 사람 없고 safety도 0이 아니면 사람이 타게 됨
        dq[0].second = 1; //사람 타고
        dq[0].first -= 1; //safety--

        if(dq[0].first == 0){ //safety값 체크. 0이 k가 되면 탈출 플래그 셋업
            cntK++;
            if(cntK == k){
                flag = false;
                return ;
            }            
        }
    }
}

int main(void)
{
    cin >> N >> k;
    for(int i = 0; i < 2*N; i++){
        int safe;
        cin >> safe;
        dq.push_back(make_pair(safe, 0)); 
    }

    while(1){
        rotate(); //1번과정. 무빙워크 이동
        move(); //2번과정. 사람 한 칸 이동
        Geton(); //3번과정. 첫 칸에 사람 싣기

        //탈출 조건 검사
        if(!flag){
            cout << experiment << '\n';
            return 0;
        }

        //한 사이클 끝났으므로 다음 실험으로
        experiment++;
    }

    return 0;
}