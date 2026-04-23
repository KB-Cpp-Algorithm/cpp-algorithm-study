/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : d e q u e                               KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct Rail {
    int durability;
    bool hasPerson;
};

int N, K, answer;
deque<Rail> movingWork;

// 무빙 워크 레일 회전
void rotateMovingWork() {
    // 맨 뒤에 존재하는 레일. 즉, 곧 1번으로 변경되는 레일
    Rail rail = movingWork.back();
    // 덱에서 제거
    movingWork.pop_back();
    // 해당 레일 1번으로 변경
    movingWork.push_front(rail);
}

// 무빙 워크의 마지막 칸 사람 탑승 여부 체크 및 사람 내리기
void unloadPerson() {
    // 만약 마지막 칸에 사람이 있을 경우
    if (movingWork[N - 1].hasPerson) {
        // 마지막 칸에서 사람 제거
        movingWork[N - 1].hasPerson = false;
    }
}

// 무빙 워크의 사람들 한 칸씩 이동
void movePeople() {
    for (int i = N - 1; i >= 1; i--) {
        // 한 칸 뒤에 이동할 사람이 존재하며, 현재 칸의 안정성이 유효하고 사람이 존재하지 않을 경우
        if (movingWork[i - 1].hasPerson && 0 < movingWork[i].durability && !movingWork[i].hasPerson) {
            // 한 칸 뒤에 있는 사람을 현재 칸으로 이동
            // 현재 칸 안정성 감소
            movingWork[i].durability -= 1;
            // 사람 존재 여부 체크
            movingWork[i].hasPerson = true;
            // 한 칸 뒤 사람 제거
            movingWork[i - 1].hasPerson = false;
        }
    }
}

// 첫 번째 칸 사람 배치 가능 파악 후 사람 배치
void loadPerson() {
    // 첫 번째 칸의 안정성
    int& durability = movingWork[0].durability;
    // 첫 번째 칸의 사람 여부
    bool& hasPerson = movingWork[0].hasPerson;
    // 안정성이 유효하고 사람이 없을 경우
    if (0 < durability && !hasPerson) {
        // 안정성 감소
        durability -= 1;
        // 사람 존재
        hasPerson = true;
    }
}

// 전체 무빙 워크에서 안정성이 0인 칸 개수 체크
int getZeroDurability() {
    int result = 0;

    for (int i = 0; i < 2 * N; i++) {
        // 해당 칸의 안정성이 0일 경우, 카운트 증가
        if (movingWork[i].durability == 0) result++;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 무빙 워크의 길이 및 실험을 종료하는 안정성 0인 판의 개수 K 입력
    cin >> N >> K;

    // 길이가 N인 무빙 워크의 총 레일 길이는 (2 * N)
    for (int i = 0; i < 2 * N; i++) {
        // 해당 칸의 안정성 입력
        int durability;
        cin >> durability;
        movingWork.push_back({durability, false});
    }

    while (true) {
        answer++;
        rotateMovingWork();
        unloadPerson();
        movePeople();
        unloadPerson();
        loadPerson();
        if (getZeroDurability() >= K) break;
    }

    cout << answer << '\n';

    return 0;
}