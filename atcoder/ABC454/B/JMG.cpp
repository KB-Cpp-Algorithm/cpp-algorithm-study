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
#include <set>
using namespace std;

// Q1 : N명의 사람들이 다른 타입의 옷을 입고 있는가?
// Q2 : 옷 M개를 N명의 사람들이 전부 한 번씩 입었는가? -> 등장 횟수 카운팅
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    set<int> s;
    
    for(int i=0;i<N;i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    // Q1
    if(s.size()==N)
        cout<<"Yes\n";
    else {
        cout<<"No\n";
    }
    // Q2
    if(s.size()==M)
        cout<<"Yes\n";
    else {
        cout<<"No\n";
    }
        
    return 0;
}