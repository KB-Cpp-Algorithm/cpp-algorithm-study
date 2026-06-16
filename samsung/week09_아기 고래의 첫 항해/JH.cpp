/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : BFS, Simulation                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              : 방향의 우선 순위 설정이 까다로운 문제   KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct Whale {
    int y;
    int x;
    int dir;
    int moving;
};

int N, r, c, d;
int sea[51][51];
bool visited[51][51];
// 기본 방향: 상, 우, 하, 좌
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
// 1단계 방향 우선 순위: [현재 방향][우선 순위 방향] = { 인덱스 }
int dirIndex[4][4] = {{0, 3, 1, 2}, {1, 0, 2, 3}, {2, 1, 3, 0}, {3, 2, 0, 1}};
// 2단계 방향 우선 순위: 좌, 하, 우, 상
int dir[4] = {3, 2, 1, 0};

// 아기 고래의 방문지 추적
vector<Whale> answer;

// 후보군 정렬 함수(이동거리 -> 행 -> 열)
bool compare(const Whale& l, const Whale& r) {
    if (l.moving != r.moving) return l.moving < r.moving;
    if (l.y != r.y) return l.y < r.y;
    return l.x < r.x;
}

// 초기 입력 방향을 내부 기준으로 변환
void initDir() {
    if (d == 1)
        d = 0;
    else if (d == 2)
        d = 2;
    else if (d == 3)
        d = 3;
    else if (d == 4)
        d = 1;
}

Whale searchNearSea(Whale& whale) {
    // 최단 거리 기록
    int minDist = INT_MAX;

    queue<Whale> q;
    vector<vector<bool>> newVisited(51, vector<bool>(51, false));
    vector<Whale> candidates;

    // 아기 고래 큐에 삽입
    q.push({whale.y, whale.x, whale.dir, 0});
    newVisited[whale.y][whale.x] = true;

    while (!q.empty()) {
        Whale w = q.front();
        q.pop();

        // 이미 찾은 최단 거리보다 멀어지면 불필요한 탐색
        if (w.moving > minDist) break;

        for (int i = 0; i < 4; i++) {
            // 우선 순위에 따른 방향 인덱스 값
            int nd = dir[i];
            int ny = w.y + dy[nd];
            int nx = w.x + dx[nd];
            // 바다를 벗어난 영역일 경우
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            // 이미 방문한 바다이거나 암초일 경우
            if (newVisited[ny][nx] || sea[ny][nx] == 1) continue;

            Whale nextWhale = {ny, nx, nd, w.moving + 1};
            q.push(nextWhale);
            // 새로운 방문 배열에 방문 처리
            newVisited[ny][nx] = true;
            // 아직 한 번도 방문하지 않은 바다를 발견한 경우
            if (!visited[ny][nx]) {
                if (candidates.empty()) {
                    // 처음 발견한 곳의 거리를 최소 거리로 저장
                    minDist = nextWhale.moving;
                }
                // 후보군에 저장
                candidates.push_back(nextWhale);
            }
        }
    }
    // 더 이상 이동할 수 있는 가장 가까운 바다가 없을 경우
    if (candidates.empty()) return {-1, -1, -1, -1};
    // 기준에 따라 정렬
    sort(candidates.begin(), candidates.end(), compare);
    return candidates.front();
}

bool searchAdjSea(Whale& whale) {
    for (int i = 0; i < 4; i++) {
        // 다음 탐색 방향 인덱스
        int nd = dirIndex[whale.dir][i];
        // 아기 고래의 다음 위치
        int ny = whale.y + dy[nd];
        int nx = whale.x + dx[nd];
        // 바다를 벗어난 영역일 경우
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        // 이미 방문한 바다이거나 암초일 경우
        if (visited[ny][nx] || sea[ny][nx] == 1) continue;
        // 아기 고래가 이동 갱신
        whale = {ny, nx, nd, whale.moving + 1};
        // 방문 처리
        visited[ny][nx] = true;
        // 정답에 추가
        answer.push_back(whale);
        // 하나 찾았으니 바로 종료
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> r >> c >> d;

    // 아기 고래의 초기 방향 조정
    initDir();

    // 아기 고래의 초기 위치 조정(0 Based)
    r--, c--;

    // 바다의 초기 정보 입력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> sea[y][x];
        }
    }

    queue<Whale> q;

    Whale currentWhale = {r, c, d, 0};

    q.push(currentWhale);
    visited[r][c] = true;

    // 시작 위치를 정답 배열에 먼저 기록
    answer.push_back(currentWhale);

    while (true) {
        // 1단계: 인접 탐험
        if (searchAdjSea(currentWhale)) continue;

        // 2단계: 가장 가까운 바다로 이동
        Whale nextWhale = searchNearSea(currentWhale);

        // 이동할 수 있는 가까운 바다가 있다면 고래 상태를 갱신하고 계속 진행
        if (nextWhale.y != -1) {
            currentWhale = nextWhale;
            visited[currentWhale.y][currentWhale.x] = true;
            answer.push_back(currentWhale);
            continue;
        }

        // 모든 단계가 불가능할 경우 루프 탈출
        break;
    }

    // 방문한 모든 바다 위치 출력
    for (const auto& whale : answer) {
        // 1 Based
        cout << whale.y + 1 << ' ' << whale.x + 1 << '\n';
    }

    return 0;
}