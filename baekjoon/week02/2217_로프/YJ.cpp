/********************************************************************************/
/* File Name         : 2217-rope.cpp                                            */
/* By                : yoonjeong                               KK  KK   BBBBB   */
/* Algorithm         : Greedy/Sorting                          KK KK    BB  BB  */
/* Time Complexity   : O(N * logN)                             KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

// 최대 100,000개의 로프 하중을 저장할 배열 (Space Complexity: O(N))
int r[100001]; 
int maxW = -1; // 최대 중량을 저장할 변수 초기화

int main(void){
    // C++ 입출력 속도 향상을 위한 Fast I/O 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 로프의 개수
    cin >> n;

    // 각 로프가 버틸 수 있는 최대 하중 입력
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        r[i] = a;
    }
    
    // 로프 하중을 오름차순으로 정렬 (Time Complexity: O(N log N))
    sort(r, r+n);

    // 가장 약한 로프부터 순회하며 들 수 있는 최대 중량 계산 (Greedy)
    for(int i=0; i<n; i++){
        // 현재 로프(r[i])를 포함하여, 이보다 튼튼한 로프들을 모두 병렬로 연결했을 때의 하중
        // 병렬 연결 시 감당 가능한 중량 = (가장 약한 로프의 하중) * (연결된 로프의 총 개수)
        // 오름차순 정렬되어 있으므로, 현재 로프보다 같거나 강한 로프의 개수는 (n - i)개임
        maxW = max(maxW, r[i] * (n-i));
    }
    
    // 계산된 최대 중량 출력
    cout << maxW;
}