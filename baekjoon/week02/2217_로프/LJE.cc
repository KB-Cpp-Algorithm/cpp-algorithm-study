// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// int N;
// vector<int> rope;

// bool compare(const int& a, const int& b) { return a > b; }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);

//   cin >> N;

//   int w;
//   for (int i = 0; i < N; i++) {
//     cin >> w;
//     rope.push_back(w);
//   }

//   sort(rope.begin(), rope.end(), compare);

//   int min_rope = 0;
//   int cnt = 0;
//   for (int i = 0; i < N; i++) {
//     if (i == 0) {
//       min_rope = rope[i];
//       cnt++;
//     } else {
//       // 중량이 더 높아지려면
//       if ((rope[i] * (cnt + 1)) >= (min_rope * cnt)) {
//         min_rope = rope[i];
//         cnt++;
//       }
//     }
//   }

//   cout << (min_rope * cnt) << "\n";
// }
/*
중간 중간 손해를 보더라도, 로프의 개수가 많아지면
최댓값이 늘어난다
 */

/********************************************************************************/
/* File Name         : 2217.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         :                                         KK KK    BB  BB
 */
/* Time Complexity   :                                         KKKKK    BBBBB */
/* Space Complexity  :                                         KK KK    BB  BB
 */
/* Note              :                                         KK  KK   BBBBB */
/*                                                                              */
/********************************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> rope;

bool compare(const int& a, const int& b) { return a > b; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    int w;
    cin >> w;
    rope.push_back(w);
  }

  // 1. 정렬
  sort(rope.begin(), rope.end(), compare);

  int max_weight = 0;

  // 2. i번째 로프까지 사용했을 때의 중량을 구하고 최댓값 갱신
  for (int i = 0; i < N; i++) {
    // i+1은 현재 사용 중인 로프의 개수
    // rope[i]는 가장 약한 로프의 무게
    int current_weight = rope[i] * (i + 1);

    if (current_weight > max_weight) {
      max_weight = current_weight;
    }
  }

  cout << max_weight << "\n";
}
