#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 부모 노드가 0이면 자식에 1 존재하면 안됨
bool dfs(string& binary, int left, int right, bool zero) {
    int mid = (left + right) / 2;
    // 현재 노드까지 0인 노드가 있었는지
    bool next_zero = zero;

    if(left > right) return true;
    // 부모가 없는 노드인데 현재 노드가 존재허면
    if(zero && binary[mid] == '1') return false;

    if(binary[mid] == '0') {
        next_zero = true;
    }
    if(!dfs(binary, left, mid - 1, next_zero)) {
        return false;
    }

    if(!dfs(binary, mid + 1, right, next_zero)) {
        return false;
    }

    return true;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long num : numbers) {
        string binary = "";

        // 이진수로 변경 - ai 도움
        while(num > 0) {
            binary += to_string(num % 2);
            num /= 2;
        }

        if(binary.empty()) binary = "0";
        reverse(binary.begin(), binary.end());
        // 크기 계산
        int size = 1;




        while(size < binary.size()) {
            size = size * 2 + 1;
        }

        // 앞에 더미 노드 추가
        while(binary.size() < size) {
            binary = "0" + binary;
        }

        if(dfs(binary, 0, binary.size() - 1, false)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
    }



    
    return answer;
}