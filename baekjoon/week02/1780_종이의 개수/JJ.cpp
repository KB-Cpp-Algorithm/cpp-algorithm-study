/********************************************************************************/
/* File Name         : 1780.cpp                                                 */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 재귀                                    KK KK    BB  BB  */
/* Time Complexity   : O(N^2 * log_3(N))                       KKKKK    BBBBB   */
/* Space Complexity  : O(N^2)                                  KK KK    BB  BB  */
/* Note              : N을 3으로 계속 나누므로 log_3           KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

/*

일반 참조(int&)는 lvalue만 받을 수 있고
상수 참조(const int&)는 리터럴/계산식 결과 같은 rvalue도 받을 수 있다.

*/
#include <bits/stdc++.h>

using namespace std;

int arr[3] = {0, }; // [-1개수][0개수][1개수] 카운트 배열

//영역 안의 데이터가 전부 같으면 true, 다르면 false 반환
bool check(const int& startX, const int& endX, const int& startY, const int& endY, const vector<vector<int>>& v){
    int flag = v[startX][startY]; //첫 번째 값 flag에 주입
    for(int i = startX; i <= endX; i++){
        for(int j = startY; j <= endY; j++){
            if(v[i][j] != flag) //배열값이 flag와 다르면 false 리턴
                return false;
        }
    }
    return true;
}

void solve(const int& startX, const int& endX, const int& startY, const int& endY, const vector<vector<int>>& v, int N)
{   
    //같은지 체크 후 내부값이 같으면 cnt++
    if(check(startX, endX, startY, endY, v)){
        if(v[startX][startY] == -1)
            arr[0]++;
        else if(v[startX][startY] == 0)
            arr[1]++;
        else
            arr[2]++;
    }

    else{
        //나누게 되면 사각형 한 변의 길이가 1/3로 줄어듦.
        //이를 기반으로 좌표 계산을 하여 9개의 케이스로 나눠 다시 check 계산.
        //위 과정을 반복(재귀)
        int tempN = N / 3;

        solve(startX, startX + tempN-1, startY, startY + tempN-1, v, tempN);
        solve(startX + tempN, startX + 2*tempN-1, startY, startY + tempN-1, v, tempN);
        solve(startX + 2*tempN, startX + 3*tempN-1, startY, startY + tempN-1, v, tempN);

        solve(startX, startX + tempN-1, startY + tempN, startY + 2*tempN-1, v, tempN);
        solve(startX + tempN, startX + 2*tempN-1, startY + tempN, startY + 2*tempN-1, v, tempN);
        solve(startX + 2*tempN, startX + 3*tempN-1, startY + tempN, startY + 2*tempN-1, v, tempN);

        solve(startX, startX + tempN-1, startY + 2*tempN, startY + 3*tempN-1, v, tempN);
        solve(startX + tempN, startX + 2*tempN-1, startY + 2*tempN, startY + 3*tempN-1, v, tempN);
        solve(startX + 2*tempN, startX + 3*tempN-1, startY + 2*tempN, startY + 3*tempN-1, v, tempN);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N,0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
        }
    }
    
    solve(0, N-1, 0, N-1, v, N);

    cout << arr[0] << '\n' << arr[1] << '\n' << arr[2];
}

    /*
    cout << "\n----------------------\n";
    for(int i = startX; i <= endX; i++){
        for(int j = startY; j<= endY; j++){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "----------------------\n";*/