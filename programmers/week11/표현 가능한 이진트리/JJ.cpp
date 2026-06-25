/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : jjeong2                                 KK  KK   BBBBB   */
/* Algorithm         : dfs(재귀)                               KK KK    BB  BB  */
/* Time Complexity   : O(NlogM)                                KKKKK    BBBBB   */
/* Space Complexity  : O(logM)                                 KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
포화 이진트리 노드 개수 : 1 , 3, 7, 15 , 31 ... -> 2^n - 1개

이진수를 2^n -1 로 맞춘다. 중앙에 있는 문자가 현재 (서브)트리의 루트가 된다.
(서브)트리의 루트 왼쪽에 있는 문자열은 왼쪽 서브트리, 오른쪽에 있는 문자열은 오른쪽 서브트리로 본다.

ex) 42 는 이진수로 101010 . 길이가 7이 돼야 하므로 0101010 이 됨.

0 1 0 1 0 1 0
      ^ 
    중앙 (루트 노드)

(0  1  0)   1   (0  1  0)
    ^               ^
   중앙            중앙   (각각 서브트리의 루트 노드가 됨)



이렇게 중앙의 각 서브트리의 루트노드가 된다. (재귀적으로 표현된다)

값이 0인 노드는 실제론 데이터 상에 존재하지 않는 더미노드를 뜻하므로 (원래는 없는 노드) 
0 노드 아래엔 1이 있을 수 없다. -> 0 아래에 1이 존재한다면 표현 불가능한 이진트리
*/

/*
재귀 dfs 이용
1. 현재 노드가 리프 노드라면 true 반환
2. 현재 노드가 0인데 자식 중 하나라도 1이면 false 반환
3. 서브트리 dfs 중 하나라도 false라면 현재 dfs도 false 반환
4. 위 조건에 걸리지 않고 탐색을 완료하면 true 반환
*/

bool dfs(string tree, int start, int end, int parent)
{
    //더 이상 볼 노드가 없으면 true 리턴
    if(start > end)
        return true;

    
    int mid = (start + end) / 2; //현재 (서브)트리의 루트 위치
    int curr = tree[mid] - '0'; //현재 노드 값


    //부모가 0인데 본인 값이 1이면 flase 리턴
    if(parent == 0 && curr == 1)
        return false;

    //왼쪽 서브트리 검사
    bool left = dfs(tree, start, mid - 1, curr);
    //오른쪽 서브트리 검사
    bool right = dfs(tree, mid + 1, end, curr);

    //둘 중 하나라도 false면 현재 트리도 false
    if(left && right)
        return true;
    else
        return false;
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;

    for(int i = 0; i < numbers.size(); i++){
        long long n = numbers[i];
        string binary = "";

        //n을 이진수로 변환
        while(n > 0){
            binary += (n % 2) + '0';
            n /= 2;
        }
        reverse(binary.begin(), binary.end());

        //포화 이진트리 길이로 맞추기 (1, 3, 7, 15, ...)
        int len = binary.size();
        int temp = 1; //포화 이진트리 길이 구하기
        while(temp < len)
            temp = temp*2 + 1;
        
        //부족한 길이만큼 0 붙이기
        while(binary.size() < temp)
            binary = "0" + binary;

        //dfs 돌리기
        if(dfs(binary, 0, binary.size() - 1, 1))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
    
}


int main(void)
{
    vector<long long> num1 = {7, 42, 5} , num2 = {63, 111, 95};
    vector<int> result1 = solution(num1), result2 = solution(num2);

    for (int i = 0; i < result1.size(); i++)
        cout << result1[i] << " ";
    cout << '\n';

    for (int i = 0; i < result2.size(); i++)
        cout << result2[i] << " ";
    cout << '\n';
}