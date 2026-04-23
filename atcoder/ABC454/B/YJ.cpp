/********************************************************************************/
/* File Name         : B-Mapping.cpp                                            */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   : O(N+M)                                  KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; //n: 사람의 수, m: 옷의 종류
    bool isFirst = true, isSecond =false;

    cin >> n >> m;
    
    vector<int> v(m+1, 0); // i : 옷의 종류, v[i] : 옷을 입은 사람 수

    for(int i=0; i<n; i++){
        int tmp; //i : 사람의 순번, tmp : i 번째 사람이 입은 옷의 종류
        cin >> tmp;
        v[tmp] += 1;
        if(v[tmp] >= 2) isFirst = false;
    }

    for(int i=1; i<=m; i++){
        if(v[i] == 0){
            isSecond = false;
            break;
        }
        isSecond = true;
    }

    cout << (isFirst ? "Yes" : "No");
    cout << "\n";
    cout << (isSecond ? "Yes" : "No");

}