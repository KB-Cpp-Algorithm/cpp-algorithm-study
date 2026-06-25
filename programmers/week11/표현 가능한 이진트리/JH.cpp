/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Tree                                    KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

bool possible;

bool dfs(string binary) {
    int size = binary.size();

    // 리프 노드일 경우
    if (size == 1) {
        // 1이면 true, 0이면 false
        return binary[0] == '1';
    }

    int mid = size / 2;

    // 왼쪽 부분 문자열
    string left = binary.substr(0, mid);
    // 오른쪽 부분 문자열
    string right = binary.substr(mid + 1);

    bool leftDfs = dfs(left);
    bool rightDfs = dfs(right);

    // 현재 루트가 0인데, 자식 서브트리 중 1이 있으면 불가능
    if (binary[mid] == '0' && (leftDfs || rightDfs)) {
        possible = false;
    }

    // 현재 부분 트리 안에 1이 하나라도 있는지 반환
    return binary[mid] == '1' || leftDfs || rightDfs;
}

string makePerfectBinaryTree(string binary) {
    int k = 1;
    
    // 문자열의 길이
    int size = binary.size();
    
    // 포화 이진 트리의 노드 사이즈는 2^k - 1
    // 따라서 k는 1, 3, 7, 15 ... 순서로
    while (k < size) {
        k = k * 2 + 1;
    }
    
    // 부족한 노드 수
    int diff = k - size;
    
    // 부족한 노드 수만큼 채우기
    string zero;
    for (int i = 0; i < diff; i++) {
        zero += '0';
    }

    // 0을 붙인 문자열 반환
    return zero + binary;
}

string toBinary(long long n) {
    string result = "";

    while (n > 0) {
        // 가장 왼쪽 비트에 따라 문자 저장
        result += '0' + (n & 1);
        // 오른쪽으로 비트를 이동(2로 나누는 것과 동일)
        n = n >> 1;
    }

    // 마지막으로 뒤집어서 이진수로 완성하기
    reverse(result.begin(), result.end());

    return result;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (const long long& number : numbers) {
        // 이진수로 변환
        string binary = toBinary(number);
        // 포화 이진 트리로 만들기
        binary = makePerfectBinaryTree(binary);

        // 플래그 초기화
        possible = true;
        dfs(binary);

        // 가능 여부에 따라 벡터에 저장
        answer.push_back(possible ? 1 : 0);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
