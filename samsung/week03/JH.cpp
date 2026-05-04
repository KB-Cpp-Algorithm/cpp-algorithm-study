/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Simulation                              KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 아이디어 생각이 어려운 문제             KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

// 택배 구조체
struct Box {
    int id;
    int minY;
    int maxY;
    int minX;
    int maxX;
    bool isDrop;
};

int N, M, maxId;
int board[51][51];
Box boxes[101];

// 택배 아래로 쌓기
void moveDown(const int& id) {
    // 쌓을 택배 고유 번호
    Box& box = boxes[id];
    // 아래로 이동한 횟수
    int moveCnt = 0;

    // 기존 좌표 지우고 시작
    for (int y = box.minY; y <= box.maxY; y++) {
        for (int x = box.minX; x <= box.maxX; x++) {
            // 해당 택배 영역일 경우
            if (board[y][x] == box.id) {
                board[y][x] = 0;
            }
        }
    }

    // 아래로 이동 시작
    while (true) {
        // 다음 행 좌표
        int ny = (box.maxY + moveCnt) + 1;
        // 움직임 여부
        bool canMove = true;

        // 다음 행 좌표가 영역을 벗어난 경우
        if (ny > N) {
            canMove = false;
            break;
        }

        // 다음 행의 모든 열도 체크
        for (int x = box.minX; x <= box.maxX; x++) {
            // 다른 택배가 존재하는 열일 경우
            if (board[ny][x] != 0) {
                // 이동 불가 판단
                canMove = false;
                break;
            }
        }

        // 더 아래로 움직일 수 있는 경우
        if (canMove) {
            moveCnt++;
        }
        // 더 아래로 움직일 수 없는 경우
        else {
            break;
        }
    }

    // 해당 택배의 좌표 갱신
    box.minY += moveCnt;
    box.maxY += moveCnt;

    // 해당 택배 영역 표시
    for (int y = box.minY; y <= box.maxY; y++) {
        for (int x = box.minX; x <= box.maxX; x++) {
            board[y][x] = box.id;
        }
    }
}

// 좌측에서 택배 꺼내기
int moveLeft() {
    // 꺼낼 후보
    int candidate = INT_MAX;

    for (int i = 1; i <= maxId; i++) {
        Box& box = boxes[i];
        // 남아있는 택배일 경우
        if (box.id != 0 && !box.isDrop) {
            bool canDrop = true;

            // 왼쪽 영역이 모두 비어있어야 꺼낼 수 있음
            for (int y = box.minY; y <= box.maxY; y++) {
                for (int x = 1; x <= box.minX - 1; x++) {
                    // 다른 택배가 있어 막고 있을 경우
                    if (board[y][x] != 0) {
                        canDrop = false;
                        break;
                    }
                }
                if (!canDrop) break;
            }

            // 꺼낼 수 있으면 후보로
            if (canDrop) {
                // 가장 낮은 번호를 가지는 후보
                candidate = min(candidate, box.id);
            }
        }
    }

    return candidate;
}

// 좌측에서 택배 꺼내기
int moveRight() {
    int candidate = INT_MAX;

    for (int i = 1; i <= maxId; i++) {
        Box& box = boxes[i];
        // 남아있는 택배일 경우
        if (box.id != 0 && !box.isDrop) {
            bool canDrop = true;

            // 오른쪽 영역이 모두 비어있어야 꺼낼 수 있음
            for (int y = box.minY; y <= box.maxY; y++) {
                for (int x = box.maxX + 1; x <= N; x++) {
                    // 다른 택배가 있어 막고 있을 경우
                    if (board[y][x] != 0) {
                        canDrop = false;
                        break;
                    }
                }
                if (!canDrop) break;
            }

            // 꺼낼 수 있으면 후보로
            if (canDrop) {
                // 가장 낮은 번호를 가지는 후보
                candidate = min(candidate, box.id);
            }
        }
    }

    return candidate;
}

// 해당 번호 택배 하차
void dropBox(const int& id) {
    Box& box = boxes[id];

    // 해당 택배가 차지하는 영역 제거
    for (int y = box.minY; y <= box.maxY; y++) {
        for (int x = box.minX; x <= box.maxX; x++) {
            board[y][x] = 0;
        }
    }

    // 상태 갱신
    box.isDrop = true;

    // 하차하는 택배 번호 출력
    cout << id << '\n';
}

// 가장 아래에 깔려있는 택배부터 내림차순 정렬
bool compare(const int& a, const int& b) {
    // 가장 아래는 maxY
    return boxes[a].maxY > boxes[b].maxY;
}

// 택배 재정렬
void realignBox() {
    vector<int> index;

    // 남아있는 택배의 번호만 가져오기
    for (int i = 1; i <= maxId; i++) {
        if (!boxes[i].isDrop) {
            index.push_back(i);
        }
    }

    // 아래 깔린 택배를 기준으로 정렬
    sort(index.begin(), index.end(), compare);

    for (int i : index) {
        moveDown(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정사각형 크기 N
    // 택배의 위치 정보 M
    cin >> N >> M;

    // 택배 정보 입력
    for (int i = 0; i < M; i++) {
        int k, h, w, c;
        // 택배 번호 k, 세로 크기 h, 가로 크기 w, 좌측 좌표(열 번호) c
        cin >> k >> h >> w >> c;
        // 택배 정보 저장
        boxes[k] = {k, 1, 1 + h - 1, c, c + w - 1, false};
        maxId = max(maxId, k);
        // 택배 쌓기
        moveDown(k);
    }

    // 택배 하차 작업 시작
    while (true) {
        int id;
        // 택배 하차 작업 수행 여부
        bool removed = false;

        id = moveLeft();
        if (id != INT_MAX) {
            removed = true;
            dropBox(id);
            realignBox();
        }

        id = moveRight();
        if (id != INT_MAX) {
            removed = true;
            dropBox(id);
            realignBox();
        }

        // 하차할 택배가 없을 경우
        if (!removed) break;
    }

    return 0;
}