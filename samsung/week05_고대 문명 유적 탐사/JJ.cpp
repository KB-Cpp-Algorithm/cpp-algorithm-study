/********************************************************************************/
/* File Name         : JJ.cpp                                                   */
/* By                : Jun Jeong                               KK  KK   BBBBB   */
/* Algorithm         : BFS + 시뮬레이션                        KK KK    BB  BB  */
/* Time Complexity   : O(K * (27*25 + R*25))                   KKKKK    BBBBB   */
/* Space Complexity  : O(25 + M)                               KK KK    BB  BB  */
/* Note              : K:탐사횟수, R:연쇄 횟수, M: 벽면 숫자   KK  KK   BBBBB   */
/*                                                                              */
/********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int K, M;
vector<vector<int>> arr(5, vector<int>(5, 0));
queue<int> q;

typedef struct{
    vector<vector<int>> grid; //배열 형태
    int score; //BFS로 구한 유물 점수
    int angle; //회전 각도
    int center_i; //중심 좌표
    int center_j;
}Node;

bool isBetter(const Node& a, const Node& b); //우선순위 비교함수
void fill(vector<vector<int>>& arr); //빈칸 채우기 함수
Node bfs(vector<vector<int>>& arr, int center_i, int center_j, int angle); //bfs를 진행한 뒤, 결과들과 정보를 구조체에 저장 후 리턴
void rotate(vector<vector<int>>& arr, int center_i, int center_j, int n); //시계방향 회전. n = 2/4/6 -> 90/180/270 회전
int findRelic(vector<vector<int>>& arr); //최적 회전 찾은 후 유물 제거 -> 빈칸 채우기 반복(연쇄). 이후 총 점수 반환
int removeRelic(vector<vector<int>>& arr);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> K >> M;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }

    int temp;
    for(int i = 0; i < M; i++){
        cin >> temp;
        q.push(temp);
    }

    //K번 탐사 진행
    for(int i = 0; i < K; i++){
        int score = findRelic(arr);
        if(score == 0)
            break;
        else
            cout << score << ' '; 
    }
    return 0;
}

//비교함수
bool isBetter(const Node& a, const Node& b)
{
    //점수 비교
    if(a.score != b.score)
        return a.score > b.score;
    //점수가 같다면 각도가 작은 방법 선택
    if(a.angle != b.angle)
        return a.angle < b.angle;
    //각도마저 같다면 열이 작은 방법 선택
    if(a.center_j != b.center_j)
        return a.center_j < b.center_j;
    //열마저 같다면 행이 작은 방법 선택
    return a.center_i < b.center_i;
}

void fill(vector<vector<int>>& arr) //빈칸 채우기 함수
{
    //열 번호가 작은 순 -> 행 번호 큰 순으로 빈칸 채움
    for(int j = 0; j < 5; j++){
        for(int i = 4; i >= 0; i--){
            if(arr[i][j] == 0){
                arr[i][j] = q.front();
                q.pop();
            }
        }
    }
}

//bfs 리턴 값을 구조체로
//bfs 함수는 bfs를 진행한 뒤, 결과들과 정보를 구조체에 저장 후 리턴
Node bfs(vector<vector<int>>& arr, int center_i, int center_j, int angle)
{
    //리턴을 위한 리턴 구조체 초기화
    Node node;
    node.grid = arr; node.score = 0; node.angle = angle; node.center_i = center_i; node.center_j = center_j;

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            //방문x. bfs 진행
            if(visited[i][j])
                continue;
            
            //시작점과 같은 유물 종류
            int target = arr[i][j];
            queue<pair<int, int>> q; //bfs를 위한 큐
            vector<pair<int, int>> cells; //넓이 검사를 위한 좌표 저장 벡터

            //bfs
            q.push({i, j});
            visited[i][j] = true;

            while(!q.empty()){
                int curr_i = q.front().first, curr_j = q.front().second;
                q.pop();
                //target과 같은 번호를 가진 칸의 정보 저장
                cells.push_back({curr_i, curr_j});

                for(int dir = 0; dir < 4; dir++){
                    int ni = curr_i + di[dir], nj = curr_j + dj[dir];

                    if(ni < 0 || ni >= 5 || nj < 0 || nj >= 5)
                        continue;

                    if(arr[ni][nj] != target)
                        continue;
                    
                    if(!visited[ni][nj]){
                        q.push({ni, nj});
                        visited[ni][nj] = true;
                    }
                }
            }

            //유물 크기가 3 이상이면 점수에 더해줌
            if(cells.size() >= 3)
                node.score += cells.size();
        }
    }
    return node;
}

//center_i,j를 중심으로 n번 밀면 회전 됨
//시계방향 회전. n = 2/4/6 -> 90/180/270 회전
void rotate(vector<vector<int>>& arr, int center_i, int center_j, int n)
{
    //2차원 배열의 값(arr)들을 1차원 배열로 전환
    vector<int> oneDimensionalArray(8,0);
    oneDimensionalArray[0] = arr[center_i - 1][center_j - 1];
    oneDimensionalArray[1] = arr[center_i - 1][center_j];
    oneDimensionalArray[2] = arr[center_i - 1][center_j + 1];
    oneDimensionalArray[3] = arr[center_i][center_j + 1];
    oneDimensionalArray[4] = arr[center_i + 1][center_j + 1];
    oneDimensionalArray[5] = arr[center_i + 1][center_j];
    oneDimensionalArray[6] = arr[center_i + 1][center_j - 1];
    oneDimensionalArray[7] = arr[center_i][center_j - 1];

    //temp에 rotate한 값들을 넣기 (밀어내는 방식 사용)
    vector<int> temp(8,0);
    for(int i = 0; i < 8; i++){
        temp[i] = oneDimensionalArray[(i - n + 8) % 8];
    }

    //원본 배열에 적용 (1차원 -> 2차원)
    arr[center_i - 1][center_j - 1] = temp[0];
    arr[center_i - 1][center_j] = temp[1];
    arr[center_i - 1][center_j + 1] = temp[2];
    arr[center_i][center_j + 1] = temp[3];
    arr[center_i + 1][center_j + 1] = temp[4];
    arr[center_i + 1][center_j] = temp[5];
    arr[center_i + 1][center_j - 1] = temp[6];
    arr[center_i][center_j - 1] = temp[7];
}

//최적 회전 찾은 후 유물 제거 -> 빈칸 채우기 반복(연쇄). 이후 총 점수 반환
int findRelic(vector<vector<int>>& arr)
{
    Node best;
    best.score = -1;
    vector<int> shift = {2, 4, 6};
    //중심 9개에 대한 반복문
    for(int center_i = 1; center_i <= 3; center_i++){
        for(int center_j = 1; center_j <= 3; center_j++){
            //각 회전에 대한 반복문
            for(auto k : shift){
                vector<vector<int>> copy = arr;
                //복사 후 회전
                rotate(copy, center_i, center_j, k);
                //회전 된 격자에서 bfs를 통해 유물 점수 찾기
                Node temp = bfs(copy, center_i, center_j, k);
                //비교 함수를 이용해 더 좋은 상황의 격자 모양을 채택
                if(isBetter(temp, best))
                    best = temp;
            }
        }
    }

    //유물이 아예 완성되지 않았으면 종료돼야 하므로 false(0) 리턴
    if(best.score == 0)
        return 0;

    //최적 회전 결과를 arr에 반영
    arr = best.grid;

    //연쇄 진행
    int totalScore = 0;
    while(true){
        int score = removeRelic(arr);

        //더 이상 제거할 유물 없으면 탈출 후 총점수 리턴
        if(score == 0)
            break;
        totalScore += score;

        //빈칸 큐에서 채우기
        fill(arr);
        
    }
    return totalScore;
}

//유물 제거. 기본적으로 BFS 함수와 흐름 같음
//제거한 유물 총점 리턴
int removeRelic(vector<vector<int>>& arr)
{
    int score = 0;
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    //상하좌우
    vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(visited[i][j] || arr[i][j] == 0)
                continue;

            int target = arr[i][j];
            queue<pair<int, int>> q;
            vector<pair<int, int>> cells; //넓이 검사를 위한 좌표 저장 벡터

            q.push({i, j});
            visited[i][j] = true;

            while(!q.empty()){
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();

                cells.push_back({curr_i, curr_j}); 

                for(int dir = 0; dir < 4; dir++){
                    int next_i = curr_i + di[dir];
                    int next_j = curr_j + dj[dir];

                    if(next_i < 0 || next_i >= 5 || next_j < 0 || next_j >= 5)
                        continue;

                    if(visited[next_i][next_j])
                        continue;

                    if(arr[next_i][next_j] != target)
                        continue;

                    visited[next_i][next_j] = true;
                    q.push({next_i, next_j});
                }
            }

            // 크기 3 이상이면 유물 획득
            if(cells.size() >= 3){
                score += cells.size();

                // 이후 해당 칸 0으로 삭제
                for(int idx = 0; idx < cells.size(); idx++){
                    int i = cells[idx].first;
                    int j = cells[idx].second;

                    arr[i][j] = 0;
                }
            }
        }
    }
    return score;
}

    // for(auto i : arr){
    //     for(auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }