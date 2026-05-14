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

int K, M;
vector<vector<int>> Arr(5, vector<int>(5, 0));
queue<int> q;

typedef struct{
    vector<vector<int>> grid; //배열 형태
    int score; //BFS로 구한 유물 점수
    int angle; //회전 각도
    int center_i; //중심 좌표
    int center_j;
}Node;

bool isBetter(const Node& a, const Node& b); //우선순위 비교함수
Node bfs(vector<vector<int>>& arr, int center_i, int center_j, int angle); //bfs를 진행한 뒤, 결과들과 정보를 구조체에 저장 후 리턴
void rotate(vector<vector<int>>& arr, int center_i, int center_j, int n); //시계방향 회전. n = 2/4/6 -> 90/180/270 회전
void findRelic(vector<vector<int>>& arr);


int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
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

    for(auto i : arr){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << '\n';
    }
        */

    K = 2;
    M = 20;
    Arr[0][0] = 7; Arr[0][1] = 6; Arr[0][2] = 7; Arr[0][3] = 6; Arr[0][4] = 7;
    Arr[1][0] = 6; Arr[1][1] = 7; Arr[1][2] = 6; Arr[1][3] = 7; Arr[1][4] = 6;
    Arr[2][0] = 6; Arr[2][1] = 7; Arr[2][2] = 1; Arr[2][3] = 5; Arr[2][4] = 4;
    Arr[3][0] = 7; Arr[3][1] = 6; Arr[3][2] = 3; Arr[3][3] = 2; Arr[3][4] = 1;
    Arr[4][0] = 5; Arr[4][1] = 4; Arr[4][2] = 3; Arr[4][3] = 2; Arr[4][4] = 7;
        
    q.push(3); q.push(2); q.push(3); q.push(5); q.push(2);
    q.push(4); q.push(6); q.push(1); q.push(3); q.push(2);
    q.push(5); q.push(6); q.push(2); q.push(1); q.push(5);
    q.push(6); q.push(7); q.push(1); q.push(2); q.push(3);

    solve(Arr);
    for(int i = 0; i < K; i++){
        int score = findRelic(Arr);
        if(score == 0)
            break;
        else
            cout << score << ' '; 
        
        //배열에서 삭제

        //배열에 큐 값 넣기
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

    //유물이 아예 완성되지 않았으면 종료돼야 하므로 false 리턴
    if(best.score == 0)
        return 0;

    //완성됐으면 격자 모양 바꾼 후 true리턴
    arr = best.grid;
    return best.score;
}