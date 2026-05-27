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

/*
사이즈가 n일 때, 이동 n번 하면 자기자신이 됨.
속도 s에서 n을 나눈 나머지만큼 이동한 것 -> 그 좌표가 최종 좌표
*/
typedef struct{
    int mass;
    int direction; //0~7. 12 - 1 - 3 - 5 - 6 - 7 - 9 - 11
    int speed;
    int posX;
    int posY;
}Node;

//좌표 저장 맵. 만약 값이 2 이상이면 해당 좌표에 원자가 두 개 이상 존재
map<pair<int, int>> m;
vector<Node> atom;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //배열 크기 , 원자 개수 , 시간
    int n, m, k;
    cin >> n >> m >> k;

    //원자 정보를 구조체로 만들어 벡터 배열로 관리
    atom.resize(n);
    for(int i = 0; i < n; i++){
        //위치 정보 x, y, 질량 m, 속력 s, 방향 d
        Node temp;
        cin >> temp.posX >> temp.posY >> temp.mass >> temp.speed >> temp.direction;
        atom.push_back(temp);
    }



    return 0;
}