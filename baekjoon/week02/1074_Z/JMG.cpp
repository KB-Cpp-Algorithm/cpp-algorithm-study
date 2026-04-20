/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 재귀, 분할정복                          KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N) - 재귀 깊이 N                      KK KK    BB  BB  */
/* Note              : 1트:시간초과(한 번 호출마다 4번 탐색)   KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
using namespace std;
// time limit : 0.5sec

// 0. AI 힌트 - 3번
// 1. size : 2^N X 2^N 
// 2. 현재 정사각형 4등분
// 3. !! r,c가 어느 사분면에 속하는지 판단하기 !! - GPT Hint!
// 3-1. 판별
//      사분면 기준선 (x+new_size,y+new_size)
//      cnt += (1,2,3,4 중)사분면 번호 * (new_size * new_size)
// 4. 그 사분면보다 먼저 방문하는 사분면들의 칸 수를 답에 더하기
// 5. 범위를 그 사분면으로 줄여서 다시 반복
int N,r,c;
int cnt = 0;

void solve(int x,int y, int size) {
    if (size == 1) return;
    int new_size = size/2;
    // 한 사분면 칸 수
    int area_cnt = new_size*new_size;
    // r,c가 1사분면일때
    if (r < x+new_size && c < y+new_size)
    {
        solve(x,y,new_size);
    }
    // r,c가 2사분면일때
    if (r < x+new_size && c >= y+new_size)
    {
        cnt+=area_cnt;
        solve(x,y+new_size,new_size);
    }
    
    // r,c가 3사분면일때
        if (r >= x+new_size && c < y+new_size)
    {
        cnt += area_cnt*2;
        solve(x+new_size,y,new_size);
    }
    // r,c가 4사분면일때
        if (r >= x+new_size && c >= y+new_size)
    {
        cnt += area_cnt*3;
        solve(x+new_size,y+new_size,new_size);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N >> r >> c;
    int size = 1;
    for (int i = 0; i < N; i++)
    {
        // size = 2^N
        size *= 2; 
    }
    solve(0,0,size);
    cout << cnt <<endl;
    
    return 0;
}





// ------------------------------------
// 시간 초과
// // 1. size : 2^N X 2^N 
// // 2. 현재 정사각형 4등분
// // 3. 현재 방문한 좌표가 (r,c) 이면 그 번호 출력

// int N,r,c;
// //방문 위치 저장
// int cnt = 0;

// void solve(int x,int y, int size) {
//     // size가 1이면 실제 칸 1개
//     if (size == 1)
//     {
//         if (x==r && y == c)
//         {
//             cout << cnt << endl;
//         }
//         cnt++;
//         return;
//     }
//     int new_size = size / 2;
//     // z순서로 4구역 전부 방문 - 재귀
//     solve(x,y,new_size);
//     solve(x,y+new_size,new_size);
//     solve(x+new_size,y,new_size);
//     solve(x+new_size,y+new_size,new_size);

    
// }

// int main(int argc, char const *argv[])
// {
//     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     int size = 1;
//     cin >> N >> r >> c;

//     for (int i = 0; i < N; i++)
//     {
//         // size = 2^N
//         size = size * 2;
//     }
    
//     solve(0,0,size);

//     return 0;
// }