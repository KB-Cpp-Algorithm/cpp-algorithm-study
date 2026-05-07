/********************************************************************************/
/* File Name         : LJE.cpp                                                  */
/* By                : Jieun                                    KK  KK   BBBBB  */
/* Algorithm         : Greedy, Map                              KK KK    BB  BB */
/* Time Complexity   : O(n)                                     KKKKK    BBBBB  */
/* Space Complexity  : O(1) (알파벳 26개 한정)                     KK KK    BB  BB */
/* Note              : 빈도수 기반 우선순뒤                          KK  KK   BBBBB  */
/*                                                                              */
/********************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 작업의 수를 세기 위한 map
    map<char, int> counts;

    int leastInterval(vector<char>& tasks, int n) {
        
        for (int i = 0; i < tasks.size(); i++) {
            // 값이 존재한다면 카운트 증가, 없으면 1로 초기화
            if (counts.find(tasks[i]) != counts.end()) {
                counts[tasks[i]]++;
            } else {
                counts[tasks[i]] = 1;
            }
        }

        // 1. 가장 높은 빈도수(max_freq) 찾기
        int max_freq = 0;
        for (auto const& [task, count] : counts) {
            max_freq = max(max_freq, count);
        }

        // 2. 최고 빈도수를 가진 작업의 개수(max_count) 세기
        int max_count = 0;
        for (auto const& [task, count] : counts) {
            if (count == max_freq) max_count++;
        }

        // 3. 공식 대입 (필요한 최소 슬롯의 크기 계산)
        // (가장 많이 등장하는 작업 사이의 간격 수) * (간격의 길이) + (마지막 남은 작업들)
        int part_count = max_freq - 1;
        int part_length = n + 1;
        int total_slots = part_count * part_length + max_count;

        // 4. 만약 작업의 총 개수가 계산된 슬롯보다 많으면 tasks.size()가 답이 됨
        return max((int)tasks.size(), total_slots);
    }
};
