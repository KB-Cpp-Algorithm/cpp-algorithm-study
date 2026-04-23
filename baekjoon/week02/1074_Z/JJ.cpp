/********************************************************************************/
/* File Name         : 1074.cpp                                                 */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 재귀                                    KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : 호출 N, 각 스택 프레임 O(1) -> O(N)     KK KK    BB  BB  */
/* Note              : 1 -> 2 -> 3 -> 4분면 순서대로 방문      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

// 호출 회수 N회 (size=2^N -> 1 될 때까지가 재귀 깊이, 즉 호출 횟수임)
// 함수 호출 회당 작업량 : O(1)
// 시간복잡도 N * O(1) = O(N)
#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void solve(int x, int y, int size, int r, int c)
{
    if(size == 1){
        cout << ans;
        return ;
    }

    //절반 크기의 사각형으로 계속 나뉨
    int half = size / 2;

    //1사분면
    if(c < x + half && r < y + half)
        solve(x, y, half, r, c);

    //2사분면
    else if(c >= x + half && r < y + half){
        ans += half * half;
        solve(x + half, y, half, r, c);
    }
        
    //3사분면
    else if(c < x + half && r >= y + half){
        ans += 2 * half * half;
        solve(x, y + half, half, r, c);
    }
        
    //4사분면
    else {
        ans += 3 * half * half;
        solve(x + half, y + half, half, r, c);
    }
    
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c;

    solve(0, 0, pow(2, N), r, c);

}