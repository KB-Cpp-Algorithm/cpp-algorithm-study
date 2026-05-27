/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         :                                         KK KK    BB  BB  */
/* Time Complexity   :                                         KKKKK    BBBBB   */
/* Space Complexity  :                                         KK KK    BB  BB  */
/* Note              :                                         KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
1. 각 원자의 방향으로 속도만큼 이동 (배열 이탈 시, 반대편에서 등장하게)
2. 칸 검사 (모든 원자 구조체 x,y 검사)
3. 칸에 두 개 이상의 원자 존재 시 4개의 원자로 나뉨
    i) 방향 검사 (모두 상하좌우 or 대각선 -> 상하좌우 / else 대각선 네 방향)
    ii) 질량은 Σ질량 / 5
    iii) 속력은 Σ속력 / Σ원자
    iv) 질량 0이 되면 소멸함
k초 후 남아 있는 원자의 질량 합?
*/

void solve();
void moveAtom();
void calcAtom();

typedef struct{
    int posX;
    int posY;
    int mass;
    int speed;
    int dir; //0~7
}Atom;

vector<Atom> atom;
int n, m, k;

//dir: 12 - 1 - 3 - 5 - 6 - 7 - 9 - 11시 방향
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    //원자 정보를 구조체로 만들어 벡터 배열로 관리
    for(int i = 0; i < m; i++){
        //위치 정보 x, y, 질량 m, 속력 s, 방향 d
        Atom temp;
        cin >> temp.posX >> temp.posY >> temp.mass >> temp.speed >> temp.dir;

        //입력 행렬 기준은 1이라 0 기준으로 바꿔줌
        temp.posX--;
        temp.posY--;
        atom.push_back(temp);
    }

    solve();

    //남아있는 원자 질량 세기
    int answer = 0;
    for(int i = 0; i < atom.size(); i++)
        answer += atom[i].mass;
    
    cout << answer << '\n';
    return 0;
}


void solve()
{
    //k번 진행. 매 횟수마다 {이동 -> 분열} 연산 진행
    while(k != 0){
        moveAtom(); //이동
        calcAtom(); //분열
        k--;
    }
}


/*
사이즈가 n일 때, 이동 n번 하면 자기자신이 됨.
즉, 아무리 속도 s가 크더라도 s에서 n을 나눈 나머지만큼 이동한 좌표가 최종 좌표가 됨.
현재 좌표에 {방향 벡터 * 이동거리(나머지)}를 더해 이동한 좌표를 구한다.
이때, 좌표가 격자 밖으로 나갈 수 있으므로 모듈러 연산으로 좌표를 보정한다.
*/
void moveAtom()
{
    for(int i = 0; i < atom.size(); i++){
        //이동 횟수
        int move = atom[i].speed % n;

        // 격자 범위 밖으로 튀어나간 경우, 방향 벡터를 더한 좌표값이 음수인 경우 모두 고려하여 보정
        atom[i].posX = ((atom[i].posX + dx[atom[i].dir] * move) % n + n) % n;
        atom[i].posY = ((atom[i].posY + dy[atom[i].dir] * move) % n + n) % n;
    }
}


void calcAtom()
{
    //격자를 생성해서 원자들을 매번 넣고 탐색하는 방식도 고려했으나 map을 이용해 빈 공간 탐색 생략하는 방식으로 구현
    //key   : {x, y}
    //value : 해당 좌표에 있는 원자 리스트
    map<pair<int, int>, vector<Atom>> mp;

    //원자 리스트를 돌면서 좌표별로 나누어 맵에 등록
    for(int i = 0; i < atom.size(); i++)
        mp[{atom[i].posX, atom[i].posY}].push_back(atom[i]);

    //변환 후의 원자 정보를 담는 임시 배열. 나중에 원자 리스트를 next로 교체하게 된다
    vector<Atom> next;

    //맵에 등록된 좌표를 순회하면서 원자 변환 동작 수행
    for(auto it = mp.begin(); it != mp.end(); it++){
        pair<int, int> currPos = it->first; //현재 검사하는 좌표
        vector<Atom> currAtoms = it->second; //좌표에 존재하는 원자들

        //임의의 좌표에 존재하는 원자가 하나면 그대로 유지
        if(currAtoms.size() == 1){ 
            next.push_back(currAtoms[0]);
            continue;
        }

        //임의의 좌표에 존재하는 원자가 두 개 이상이면 합치고 분열
        
        /*
        dir이 (0,2,4,6) or (1,3,5,7)로만 이루어져 있으면 (0,2,4,6) 방향으로 분열
        섞여있으면 (1,3,5,7) 방향으로 분열함
        그래서 홀/짝 플레그를 두어서 하나라도 true면 (0,2,4,6) 방향으로 분열되게끔 함
        */
        bool EvenFlag = true, OddFlag = true;
        int sumMass = 0, sumSpeed = 0;

        for(int i = 0; i < currAtoms.size(); i++){
            sumMass += currAtoms[i].mass;
            sumSpeed += currAtoms[i].speed;

            if(currAtoms[i].dir % 2 == 0)
                OddFlag = false;
            else
                EvenFlag = false;
        }

        //새 질량. 0이면 소실(next에 추가 x)
        int newMass = sumMass / 5;
        if(newMass == 0)
            continue;

        int newSpeed = sumSpeed / currAtoms.size();
        int newDir;

        //둘 중 하나라도 true라면 (0,2,4,6) 분열
        if(EvenFlag || OddFlag)
            newDir = 0;
        else
            newDir = 1;

        //4개의 분열된 원자를 4방향으로 세팅 후 next 원자 리스트에 추가
        for(int i = newDir; i < 8; i += 2){
            next.push_back({currPos.first, currPos.second, newMass, newSpeed, i});
        }
    }
    //원자 리스트 갱신
    atom = next;
}