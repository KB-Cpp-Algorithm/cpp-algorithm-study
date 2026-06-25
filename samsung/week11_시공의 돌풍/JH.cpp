/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Simulation                              KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int room[51][51], tempRoom[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> dust;

void moveDustStorm() {
    // 돌풍 윗 부분 방향 순서: 상 -> 우 -> 하 -> 좌
    int upperDir[4] = {0, 1, 2, 3};
    // 돌풍 윗 부분 시공의 돌풍 좌표
    int upperY = dust[0].first;
    int upperX = dust[0].second;
    // 돌풍 윗 공간
    int y = upperY - 1;
    int x = upperX;
    // 첫 방향 인덱스
    int dirIndex = 0;

    // 돌풍 위쪽 청소 시작
    while (true) {
        // 인덱스에 맞는 방향 조회
        int dir = upperDir[dirIndex];
        // 복사할 값을 가지는 다음 방의 좌표
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 영역을 벗어날 경우 방향 전환
        if (ny < 0 || ny > upperY || nx < 0 || nx >= m) {
            dirIndex++;
            dir = upperDir[dirIndex];
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        // 다음 칸이 시공의 돌풍이면 현재 칸을 0으로 만들고 종료
        if (room[ny][nx] == -1) {
            room[y][x] = 0;
            break;
        }

        // 다음 칸의 값을 현재 칸으로 당겨오기
        room[y][x] = room[ny][nx];

        // 현재 좌표 이동
        y = ny;
        x = nx;
    }

    // 하부분 방향 순서: 하 -> 우 -> 상 -> 좌
    int lowerDir[4] = {2, 1, 0, 3};
    // 하부분 시공의 돌풍 좌표
    int lowerY = dust[1].first;
    int lowerX = dust[1].second;
    // 
    y = lowerY + 1;
    x = lowerX;
    
    dirIndex = 0;

    // 돌풍 아래쪽 청소 시작
    while (true) {
        int dir = lowerDir[dirIndex];

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 범위를 벗어나면 방향 전환
        if (ny < lowerY || ny >= n || nx < 0 || nx >= m) {
            dirIndex++;
            dir = lowerDir[dirIndex];
            ny = y + dy[dir];
            nx = x + dx[dir];
        }

        // 다음 칸이 시공의 돌풍이면 현재 칸을 0으로 만들고 종료
        if (room[ny][nx] == -1) {
            room[y][x] = 0;
            break;
        }

        // 다음 칸의 값을 현재 칸으로 당겨오기
        room[y][x] = room[ny][nx];

        // 현재 좌표 이동
        y = ny;
        x = nx;
    }
}

// 방에 남아있는 먼지의 양 조사하기
int getDust() {
    int result = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (room[y][x] == -1) continue;
            result += room[y][x];
        }
    }

    return result;
}

// 방 내부 먼지 확산하기
void spreadDust() {
    // 확산 상태를 임시로 저장할 공간 0으로 세팅
    memset(tempRoom, 0, sizeof(tempRoom));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            // 시공의 돌풍일 경우
            if (room[y][x] == -1) {
                tempRoom[y][x] = -1;
                continue;
            }

            // 먼지가 없을 경우
            if (room[y][x] == 0) {
                continue;
            }

            // 확산할 수 있는 먼지 크기
            int spreadDustSize = room[y][x] / 5;
            // 확산한 방의 수
            int spreadCount = 0;

            // 상하좌우 인접 방 조사
            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                // 방이 아닌 영역일 경우
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                // 시공의 돌풍이 있는 영역일 경우
                if (room[ny][nx] == -1) continue;
                tempRoom[ny][nx] += spreadDustSize;
                spreadCount++;
            }

            // 확산하고 남은 먼지
            tempRoom[y][x] += room[y][x] - (spreadDustSize * spreadCount);
        }
    }

    // 원본에 복사
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            room[y][x] = tempRoom[y][x];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로의 크기, 가로의 크기, 시간 입력
    cin >> n >> m >> t;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> room[y][x];
            // 시공의 돌풍일 경우
            if (room[y][x] == -1) {
                // 해당 좌표 저장
                dust.push_back({y, x});
            }
        }
    }

    // t초 동안 반복 수행
    while (t--) {
        // 방 내부 먼지 확산 시작
        spreadDust();

        // 시공의 돌풍 작동
        moveDustStorm();
    }

    // 남아있는 먼지의 양 조사하고 출력
    cout << getDust() << '\n';

    return 0;
}
