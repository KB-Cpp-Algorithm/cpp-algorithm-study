#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// //대각선으로 가면 dir = 1, 정방향이면 : dir = 0
int isDir(vector<int>& dir_vec){
    int first_parity = dir_vec[0] % 2;
    for(int i=1; i<dir_vec.size(); i++){
        if(first_parity != dir_vec[i] % 2) return 1;
    }
    return 0;
}

int main() {
    // Please write your code here.

    int n, m, k;
    vector<tuple<int, int, int, int, int>> atoms;
    
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    cin >> n >> m >> k; //격자의 크기, 원자의 개수, 실험 시간
    //map 정의 : 각 칸별 원자의 개수가 몇개인지 저장할거임
    vector<vector<vector<int>>> maps(n, vector<vector<int>>(n, vector<int>()));
    //x, y좌표, 원소 idx
    for(int i=0; i<m; i++){
        // x죄표, y좌표, 질량 m, 속력 s, 방향 d
        int x, y, mass, s, d;
        cin >> x >> y >> mass >> s >> d;
        x--;
        y--;

        atoms.push_back(make_tuple(x, y, mass, s, d));
        maps[x][y].push_back(i);

    }

    while(k--){ // 0~k초
        int idx = 0; //원자 번호
        //이동만 처리해서 담아둘 임시 맵
        vector<vector<vector<int>>> next_maps(n, vector<vector<int>>(n, vector<int>()));

        for(auto& atom: atoms){ // 원자가 이동

            int dir = get<4>(atom);
            int speed = get<3>(atom);

            int next_x = ((get<0>(atom) + dx[dir] * speed ) % n + n) % n ;
            int next_y = ((get<1>(atom) + dy[dir] * speed ) % n + n) %n;

            //원본 좌표 업데이트
            get<0>(atom)= next_x;
            get<1>(atom) = next_y;

            //이동한 위치를 next_map에 기록
            next_maps[next_x][next_y].push_back(idx);
            idx ++;
        }

        //충돌 처리
        vector<tuple<int, int, int, int, int>> new_atoms;
        vector<vector<vector<int>>> new_maps(n, vector<vector<int>>(n, vector<int>()));

        //이동을 다 하면 원자의 충돌을 이용해서 다시 원자를 배치하기
        //maps의 좌표에 여러개가 잇을 시에 계산을 하기
        //maps 벡터와 atom 벡터의 초기화가 필요해 보이며
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //좌표에 원자 가 없을 때
                if(next_maps[i][j].empty()) continue; 
                //좌표에 원자가 1개 있을 때
                if(next_maps[i][j].size() == 1) {
                    int idx = next_maps[i][j][0];
                    new_atoms.push_back(atoms[idx]);

                    //새 리스트에 들어간 위치를 새 맵에 기록 **
                    new_maps[i][j].push_back(new_atoms.size()-1);

                }
                else{
                    //원자가 존재할때 어떻게 할지 판단하기
                    //방향과 질량, 속력을 판단하기
                    // 방향 처리를 어떻게 해 줄 것인지
                    int sum_mass = 0;
                    int sum_speed = 0;
                    vector<int> dir_vec;
                    for(auto& idx : next_maps[i][j]){
                        sum_mass += get<2>(atoms[idx]);
                        sum_speed += get<3>(atoms[idx]);
                        int now_dir = get<4>(atoms[idx]);
                        dir_vec.push_back(now_dir);
                    }
                    int res_mass = sum_mass / 5;
                    if(res_mass == 0) continue;
                    int cnt = next_maps[i][j].size();
                    int res_speed = sum_speed / cnt;

                    //방향 처리 : 대각선으로 가면 dir = 1, 정방향이면 : dir = 0                    
                    int dir = isDir(dir_vec);
                    
                    for(;dir<8;){
                        new_atoms.push_back(make_tuple(i, j, res_mass, res_speed, dir));
                        new_maps[i][j].push_back(new_atoms.size()-1);
                        dir +=2;
                    }
                }
            }
        } // 이동 끝
        maps = new_maps;
        atoms = new_atoms;
    }
    // 값 접근 예시
    // int first_x = get<0>(atoms[0]);
    // int first_y = get<1>(atoms[0]);

    int result = 0;
    for(auto& atom: atoms){
        result += get<2>(atom);
    }

    cout << result;

    return 0;
}