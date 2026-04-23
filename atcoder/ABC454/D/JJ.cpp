/********************************************************************************/
/* File Name         : D.cpp                                                    */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 자료구조, 구현                          KK KK    BB  BB  */
/* Time Complexity   : O(N)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(N)                                    KK KK    BB  BB  */
/* Note              : 두 문자열을 정규화하여 같은지 확인      KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/


#include <bits/stdc++.h>

using namespace std;

string normalize(string s){
    string st;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        //문자열을 스택처럼 사용
        st.push_back(ch);

        while(st.size() >= 4){
            //문자열 끝의 형태가 (xx) 인지 확인 
            int n = st.size();
            if (st[n - 4] == '(' && st[n - 3] == 'x' && st[n - 2] == 'x' && st[n - 1] == ')'){
                st.pop_back(); // ')'
                st.pop_back(); // 'x'
                st.pop_back(); // 'x'
                st.pop_back(); // '('
                st.push_back('x');
                st.push_back('x'); // 'xx' push
            } 
            else //끝 형태가 치환할 수 있는 형태가 아니면 반복문 탈출 후 st에 새 문자 추가
                break;
        }
    }

    return st;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string A, B;
        cin >> A >> B;

        if(normalize(A) == normalize(B))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}