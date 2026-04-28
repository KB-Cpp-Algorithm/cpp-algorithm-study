/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 분할정복 , 재귀                         KK KK    BB  BB  */
/* Time Complexity   : O(N^2 * (log_3 N))                      KKKKK    BBBBB   */
/* Space Complexity  : O(N^2)                                  KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <iostream>
using namespace std;

// 선언부
// 3^7 = 2187
int arr[2190][2190];
int cnt_m1, cnt_0,cnt_p1 = 0;

// 각 반복마다 시작좌표 : (row,col)
// 크기 : (size X size)

// func - solve : 현재 종이 숫자 동일 여부 검사 + 모두 같으면 각자 cnt_?++;
// 다르면 기존 크기 / 3 -> solve 호출 (크기 == 1 => 전부 카운트)
void solve(int row,int col, int size) {
    //시작 값
    int temp = arr[row][col];
    //반복문 탈출용 트리거 - 영역이 전부 같은 순자인지 검사
    bool isSame = true;
    // 0,0부터 시작 -> (0+size,0+size)까지 
    for (int i = row; i < row+size; i++)
    {
        for (int j = col; j < col+size; j++)
        {
            if (arr[i][j] != temp)
            {
                isSame = false;
                break;
            }           
        }
        if (!isSame) break;
    }
    // 영역이 전부 같은 숫자면 각 숫자 카운트 후 종료
    if (isSame)
    {   
        if (temp == -1) cnt_m1++;
        if (temp == 0) cnt_0++;
        if (temp == 1) cnt_p1++;
        return;
    }

    // 순차 진행
    int new_size = size / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solve(row + i*new_size, col + j*new_size, new_size);
        }
    }
// N == 9 시작 시 
// -> 한 번 분할 시 
// solve(0,0,3); solve(0,3,3); solve(0,6,3);
// solve(3,0,3); solve(3,3,3); solve(3,6,3);
// solve(6,0,3); solve(6,3,3); solve(6,6,3);
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    // 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    solve(0,0,N);
    cout << cnt_m1 << endl;
    cout << cnt_0 << endl;
    cout << cnt_p1 << endl;
    
    return 0;
}


