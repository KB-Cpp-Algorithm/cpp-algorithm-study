/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
using namespace std;
// time limit : 0.5sec


// 1. size : 2^N X 2^N 
// 2. 현재 정사각형 4등분
// 3. 현재 방문한 좌표가 (r,c) 이면 그 번호 출력

int N,r,c;
//방문 위치 저장
int cnt = 0;

void solve(int x,int y, int size) {
    // size가 1이면 실제 칸 1개
    if (size == 1)
    {
        if (x==r && y == c)
        {
            cout << cnt << endl;
        }
        cnt++;
        return;
    }
    int new_size = size / 2;
    // z순서로 4구역 전부 방문 - 재귀
    solve(x,y,new_size);
    solve(x,y+new_size,new_size);
    solve(x+new_size,y,new_size);
    solve(x+new_size,y+new_size,new_size);

    
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int size = 1;
    cin >> N >> r >> c;

    for (int i = 0; i < N; i++)
    {
        // size = 2^N
        size = size * 2;
    }
    
    solve(0,0,size);

    return 0;
}





// 1. size : 2^N X 2^N 
// 2. 현재 정사각형 4등분
// 3. !! r,c가 어느 사분면에 속하는지 판단하기 !! - GPT Hint!
// 4. 그 사분면보다 먼저 방문하는 사분면들의 칸 수를 답에 더하기
// 5. 범위를 그 사분면으로 줄여서 다시 반복

// int main(int argc, char const *argv[])
// {
//     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//     return 0;
// }