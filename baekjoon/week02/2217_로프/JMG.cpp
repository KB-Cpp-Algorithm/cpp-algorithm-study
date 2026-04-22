/********************************************************************************/
/* File Name         : JMG.cpp                                                  */
/* By                : MinGyu Jeong                            KK  KK   BBBBB   */
/* Algorithm         : 그리디                                  KK KK    BB  BB  */
/* Time Complexity   : O(n*logn) - 정렬                        KKKKK    BBBBB   */
/* Space Complexity  : O(n)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

// 로프 k개 사용 -> 가장 약한 로프가 버틸 수 있는 무게 기준으로 생각
// 들 수 있는최대 무게 - 가장 약한 로프 * k
// sort해서 rope[i]를 가장 약한 로프로 두고 i ~ 끝까지 사용하는 경우 계산 
// rope[i] * N-i
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);    
    int N;
    int rope[100001];
    int max_w = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> rope[i];
    }
    // 정렬
    sort(rope, rope + N);

    // i번째 로프를 최약체로 두고 i~N-1번까지 로프 다 더하기
    for (int i = 0; i < N; i++)
    {
        int w = rope[i] * (N-i);
        if (w >= max_w)
        {
            max_w = w;
        }
    }

    cout << max_w;
    

    return 0;
}


