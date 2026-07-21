#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> jobs) {
    
    int n = jobs.size();
    
    //jobs를 요청 시각 기준으로 오름차순 정렬
    sort(jobs.begin(), jobs.end());
    
    //직업의 소요 시간, 작업의 요청 시각, 작업의 번호 순으로 pq
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    
    //현재 시각
    int cur_time = 0;
    
    //job의 현재 인덱스
    int job_idx = 0;
    
    //turn around 시간의 총 합
    int answer = 0;
    
    //완료된 작업 수
    int completed_jobs = 0;
    
    //모든 job들을 완료할 때까지 반복
    while(completed_jobs < n){
        
        //현재 시간보다 전에 요청을 했을 때 pq에 넣음
        //앞의 작업 수행으로 인해 시간이 지나 
        //pq에 넣지 않았을 때를 고려해서 while로
        while(job_idx < n && cur_time >= jobs[job_idx][0]){
            
            //소요 시간
            int a = jobs[job_idx][1];
            
            //요청 시각
            int b = jobs[job_idx][0];
            
            //번호
            int c = job_idx;
            
            pq.push({a,b,c});
            
            job_idx++;
        }
        
        //만약 현재 시각에 pq가 비어 있지 않다면 수행할 작업이 있음
        if(!pq.empty()){
            auto [time_taken, request_time, idx] = pq.top();
            pq.pop();
            
            cur_time += time_taken;
            answer += cur_time - request_time;
            completed_jobs++;
        }
        
        //pq가 비어 있다면 다음으로 요청 시각이 빠른 job의 요청 시각으로
        else{
            cur_time = jobs[job_idx][0];
        }
        
    }
    
    return answer / n;
}
