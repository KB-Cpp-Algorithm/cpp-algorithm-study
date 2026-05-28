/********************************************************************************/
/* File Name         : JH.cpp                                                   */
/* By                : jaehoon                                 KK  KK   BBBBB   */
/* Algorithm         : Implementation, Simulation              KK KK    BB  BB  */
/* Time Complexity   : O(K * N^2)                              KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct Atom {
    int y;
    int x;
    int mass;
    int speed;
    int dir;
};

int N, M, K, answer;
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<Atom> atoms;

// 전체 원자 이동 진행
void moveAtoms() {
    for (Atom& atom : atoms) {
        // 음수가 나올 수 있기 때문에, 좌표 보정
        atom.y = (atom.y + (atom.speed * dy[atom.dir]) % N + N) % N;
        atom.x = (atom.x + (atom.speed * dx[atom.dir]) % N + N) % N;
    }
}

// 전체 원자 합성 진행
void composeAtoms() {
    // [y좌표][x좌표][원자]
    vector<vector<vector<Atom>>> matrix(N, vector<vector<Atom>>(N));
    // 새로 만들어지는 원자들
    vector<Atom> newAtoms;

    // 해당 좌표에 원자 정보 저장
    for (const Atom& atom : atoms) {
        matrix[atom.y][atom.x].push_back(atom);
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            // 해당 위치에 원자가 없을 경우
            if (matrix[y][x].empty()) continue;
            // 해당 위치에 원자가 1개만 있을 경우
            if (matrix[y][x].size() == 1) {
                // 해당 원자는 합성 불가, 상태 유지
                newAtoms.push_back(matrix[y][x][0]);
                continue;
            }
            // 해당 위치에 있는 원자들
            vector<Atom> currentAtoms = matrix[y][x];
            // 질량 합과 속력 합
            int totalMass = 0, totalSpeed = 0;
            // 모두 대각선 방향만 등장 여부
            bool hasAllDiagonalDir = true;
            // 모두 상하좌우 방향만 등장 여부
            bool hasAllStraightDir = true;

            // 모든 원자 순회
            for (const Atom& atom : currentAtoms) {
                totalMass += atom.mass;
                totalSpeed += atom.speed;
                // 짝수 방향은 상하좌우 방향
                if (atom.dir % 2 == 0) {
                    // 상하좌우가 한번이라도 등장했기에 모두 대각선은 아님
                    hasAllDiagonalDir = false;
                } else {
                    // 대각선이 한번이라도 등장했기에 모두 상하좌우는 아님
                    hasAllStraightDir = false;
                }
            }
            // 합쳐지고 새로운 질량
            int newMass = totalMass / 5;
            // 새로운 속력
            int newSpeed = totalSpeed / currentAtoms.size();
            // 질량이 0일 경우 소멸
            if (newMass == 0) continue;
            // 4개의 원자들로 쪼개기
            for (int i = 0; i < 4; i++) {
                // 모두 대각선 방향 또는 상하좌우 방향을 가진 원자일 경우
                if (hasAllDiagonalDir || hasAllStraightDir) {
                    // 상하좌우로 뻗어나가는 원자들
                    newAtoms.push_back({y, x, newMass, newSpeed, (2 * i)});
                }
                // 대각선과 상하좌우 방향이 섞인 원자일 경우
                else {
                    // 대각선으로 뻗어나가는 원자들
                    newAtoms.push_back({y, x, newMass, newSpeed, (2 * i + 1)});
                }
            }
        }
    }

    // 새롭게 만들어진 원자들로 재구성
    atoms = newAtoms;
}

// 전체 원자의 질량 합 계산
int calculateAtomsMass() {
    int totalMass = 0;

    for (const Atom& atom : atoms) {
        totalMass += atom.mass;
    }

    return totalMass;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 격자의 크기, 원자의 수, 실험 시간
    cin >> N >> M >> K;

    // 전체 원자의 정보를 담은 벡터
    atoms.resize(M);

    // 전체 원자의 정보 입력
    // 초기 원자는 서로 겹치지 않음
    for (int i = 0; i < M; i++) {
        //  y좌표, x좌표, 질량, 속력, 방향
        cin >> atoms[i].y >> atoms[i].x >> atoms[i].mass >> atoms[i].speed >> atoms[i].dir;
        // 좌표 보정(1이 아닌 0부터)
        atoms[i].y--;
        atoms[i].x--;
    }

    // K번 충돌 실험 진행
    while (K--) {
        moveAtoms();
        composeAtoms();
    }

    // 남아있는 원자들의 질량의 합 계산
    answer = calculateAtomsMass();

    // 정답 출력
    cout << answer << '\n';

    return 0;
}