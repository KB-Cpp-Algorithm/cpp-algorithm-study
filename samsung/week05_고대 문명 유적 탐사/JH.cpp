#include <bits/stdc++.h>

using namespace std;

struct Artifact {
    int y;
    int x;
    int degree;
    int value;
};

int K, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<vector<int>> board(5, vector<int>(5, 0));
queue<int> wall;

bool compare(const Artifact& l, const Artifact& r) {
    if (l.value != r.value) return l.value > r.value;
    if (l.degree != r.degree) return l.degree < r.degree;
    if (l.x != r.x) return l.x < r.x;
    return l.y < r.y;
}

// 시계 방향 90도 회전 함수
vector<vector<int>> rotate90(const int& y, const int& x, const vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();

    // 원본 복사 2차원 벡터
    vector<vector<int>> temp = v;
    // 1행
    temp[y - 1][x - 1] = v[y + 1][x - 1];
    temp[y - 1][x] = v[y][x - 1];
    temp[y - 1][x + 1] = v[y - 1][x - 1];
    // 2행
    temp[y][x - 1] = v[y + 1][x];
    temp[y][x] = v[y][x];
    temp[y][x + 1] = v[y - 1][x];
    // 3행
    temp[y + 1][x - 1] = v[y + 1][x + 1];
    temp[y + 1][x] = v[y][x + 1];
    temp[y + 1][x + 1] = v[y - 1][x + 1];

    return temp;
}

// 획득할 수 있는 유물 가치 조사
vector<pair<int, int>> getRemoveArtifactPositions(const vector<vector<int>>& v) {
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<pair<int, int>> removePositions;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // 이미 조사한 유물 좌표일 경우
            if (visited[i][j]) continue;

            // 유물의 번호
            int num = v[i][j];
            queue<pair<int, int>> q;
            vector<pair<int, int>> candidates;

            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty()) {
                auto [y, x] = q.front();
                q.pop();

                candidates.push_back({y, x});

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
                    if (v[ny][nx] != num || visited[ny][nx]) continue;

                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }

            // 삭제할 유물이 3개 이상 연결된 경우
            if (candidates.size() >= 3) {
                // 삭제할 좌표 저장
                for (const auto& candidate : candidates) {
                    removePositions.push_back(candidate);
                }
            }
        }
    }

    return removePositions;
}

void fillBoard() {
    for (int x = 0; x < 5; x++) {
        for (int y = 4; y >= 0; y--) {
            if (board[y][x] == 0) {
                board[y][x] = wall.front();
                wall.pop();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 탐사의 반복 횟수 K
    // 벽면에 적힌 유물의 개수 M
    cin >> K >> M;

    // 초기 유적지 정보 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    // 유적 벽면에 적힌 숫자 입력
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        // 적힌 수는 큐에 저장
        wall.push(num);
    }

    // 턴 진행
    while (K--) {
        // 조사 가능한 모든 경우의 수 저장 벡터
        vector<Artifact> artifacts;

        // 모든 가능한 중심 좌표와 회전 각도 조회
        for (int y = 1; y <= 3; y++) {
            for (int x = 1; x <= 3; x++) {
                vector<vector<int>> temp = board;

                // 회전 각도 결정
                for (int d = 1; d <= 3; d++) {
                    temp = rotate90(y, x, temp);

                    // 제거 가능한 유물의 좌표
                    vector<pair<int, int>> removePos = getRemoveArtifactPositions(temp);
                    int size = removePos.size();

                    // 획득할 수 있는 유물 조각 수 저장
                    artifacts.push_back({y, x, d, size});
                }
            }
        }

        // 우선순위에 따라 정렬
        sort(artifacts.begin(), artifacts.end(), compare);

        // 최적의 유물 선택 방법
        Artifact best = artifacts[0];

        // 제거할 유물이 없을 경우
        if(best.value == 0) break;

        // 실제로 회전 적용
        for (int i = 0; i < best.degree; i++) {
            board = rotate90(best.y, best.x, board);
        }

        // 유물 제거 수
        int total = 0;

        while (true) {
            // 실제로 제거할 유물들의 좌표
            vector<pair<int, int>> removePos = getRemoveArtifactPositions(board);

            // 제거할 유물이 없을 경우
            if (removePos.empty()) break;

            // 해당 좌표 유물 제거
            for (const auto& pos : removePos) {
                board[pos.first][pos.second] = 0;
                total++;
            }

            // 빈공간 유물 채우기
            fillBoard();
        }

        cout << total << ' ';
    }

    return 0;
}