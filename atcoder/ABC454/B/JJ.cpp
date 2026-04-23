/********************************************************************************/
/* File Name         : B.cpp                                                    */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 단순 구현                               KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 위치벡터 사용                           KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //1번 질문 : 모든 사람이 다른 종류의 옷을 입고 있나?
    //2번 질문 : 모든 종류의 옷이 등장했는가?

    int N, M, Fflag = 1, Sflag = 1;
    cin >> N >> M;
    vector<int> F(M,0); //옷 종류 벡터

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        F[temp - 1]++; //인덱스에 해당하는 옷을 입고 있는 사람 수가 저장됨
    }

    for(auto i : F){
        //배열 값이 2 이상이면 2명 이상이 해당 옷을 입고 있음 -> 1번 No가 됨
        if(i >= 2){
            Fflag = 0;
        } 
        
        //배열 값이 0이 있으면 해당 옷을 입고 있는 사람이 없음 -> 2번 No가 됨
        if(i == 0)
            Sflag = 0;
    }
    
    if(Fflag)
        cout << "Yes\n";
    else
        cout << "No\n";

    if(Sflag)
        cout << "Yes";
    else
        cout << "No";
}