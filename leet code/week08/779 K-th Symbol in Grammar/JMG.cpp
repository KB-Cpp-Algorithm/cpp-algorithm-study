#include <bits/stdc++.h>
// 0 시작
// 0 -> 01, 1-> 10 무한반복 -> 재귀 반복
// 문자열은 정해진 규칙대로 바뀜
// n번째 행의 k번째 값 반환
// 0
// 01 
// 0110
// 01101001
// 0110100110010110
// 01101001100101101001011001101001

// 시간초과 15/55
// 시간복잡도 2^29?
class Solution {
public:
    int kthGrammar(int n, int k) {
        string s = "0";

        // 1행은 이미 만들어져 있으니까 2행부터 n행까지 생성
        for(int i = 2; i <= n; i++) {
            string next = "";
            for(int j = 0; j < s.length(); j++) {
                if(s[j] == '0') next += "01";

                else next += "10";
            }
            s = next;
        }
        // k 시작 1부터라서
        return s[k - 1] - '0';
    }
};