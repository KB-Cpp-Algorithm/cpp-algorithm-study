/********************************************************************************/
/* File Name         : 1074-z.cpp                                               */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : Divide and Conquer / Recursion          KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int ans;

void Z(int y, int x, int size){ //size = 현재 사분면의 크기
    //y, x 현재 사각형의 가장 왼쪽 위 좌표
    //도달
    if(y == r && x == c){
        cout << ans << "\n";
        return;
    }

    //r, c가 현재 사분면에 존재하지 않는다면?
    // 이 구역은 일일이 들어가지 않고 넓이(size* size)만큼 정답에 더하고 스킵
    if(!(y <= r && r < y + size && x <= c && c < x+size)){
        ans += size* size;
        return;
    }

    //네모 구역 안에 (r, c)가 있다면?
    //네모를 반으로 쪼개서 (size/2) 4개의 사분면을 z모양 순서대로 탐색
    int half = size/2;
    Z(y, x, half); //1. 왼쪽 위
    Z(y, x+half, half); //2. 오른쪽 위
    Z(y+half, x, half); //3. 왼쪽 아래
    Z(y+half, x+half, half); //4. 오른쪽 아래

}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> c;

    Z(0, 0, (1 << n));

    return 0;
}