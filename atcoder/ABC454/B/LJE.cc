/********************************************************************************/
/* File Name         : B.cc */
/* By                : ubuntu                                  KK  KK   BBBBB */
/* Algorithm         :                                         KK KK    BB  BB
 */
/* Time Complexity   :                                         KKKKK    BBBBB */
/* Space Complexity  :                                         KK KK    BB  BB
 */
/* Note              :                                         KK  KK   BBBBB */
/*                                                                              */
/********************************************************************************/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// index 조심
int N;
int M;

bool Q1 = true;
bool Q2 = true;

unordered_set<int> F;

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int clothes;
    cin >> clothes;

    if (F.find(clothes) == F.end()) {
      F.insert(clothes);
    } else if (Q1 == true) {
      Q1 = false;
    }
  }

  // set의 사이즈가 M보다 작으면 2번 false
  if (F.size() < M) {
    Q2 = false;
  }

  if (Q1) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }

  if (Q2) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}
