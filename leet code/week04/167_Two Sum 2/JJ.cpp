/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : 투포인터                                KK KK    BB  BB  */
/* Time Complexity   : O(n)                                    KKKKK    BBBBB   */
/* Space Complexity  : O(1)                                    KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int size;

    vector<int> twoSum(vector<int>& numbers, int target) {
        size = numbers.size();
        vector<int> result(2, 0);

        //각각 시작·끝 포인터
        int low = 0, high = size - 1;

        while(low <= high){

            //이분탐색처럼 안될 부분은 미리 가지를 쳐 시간 줄임
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                result[0] = low + 1;
                result[1] = high + 1;
                break;
            }
                
            else if(sum > target)
                high--;
            
            else if(sum < target)
                low++;
        }

        cout << result[0] << ' ' << result[1] << '\n';
        return result;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<int> numbers = {2, 7, 11, 15};
    vector<int> numbers2 = {2, 3, 4};
    vector<int> numbers3 = {-1, 0};
    sol.twoSum(numbers, 9);
    sol.twoSum(numbers2, 6);
    sol.twoSum(numbers3, -1);
}
