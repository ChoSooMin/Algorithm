//
//  Programmers_42627.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/16.
//  Copyright © 2020 조수민. All rights reserved.
//
//  디스크 컨트롤러(https://programmers.co.kr/learn/courses/30/lessons/42627)

#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator() (vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0; // 평균을 구하기 위해 모든 작업들이 "요청부터 종료까지 걸린 시간"을 answer 값에 더해준다.
    int endTime = 0; // 진행중인 작업이 끝나는 시간
    int j = 0; // 인덱스 관리용
    
    // 먼저 들어온 순서대로 작업을 정렬해준다.
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; // 우선순위 큐
    
    // 대기열이 없고, 우선순위 큐가 빌 때까지 반복
    while (j < jobs.size() || !pq.empty()) {
        // 들어올 대기열이 남아있고, 들어올 대기열이 현재시간보다 작다면
        if (jobs.size() > j && endTime >= jobs.at(j).at(0)) {
            // 우선순위 큐에 추가한 후 인덱스 증가
            pq.push(jobs.at(j));
            j++;
            
            // 같은 시간대에 다른 작업이 더 들어왔을 수 있으므로 다시 확인
            continue;
        }
        
        // 큐가 비어있지 않다면
        if (!pq.empty()) {
            // endTime에 이 작업이 끝날때까지 걸리는 시간만큼 추가
            endTime += pq.top().at(1);
            
            // 작업 시간에 대기 시간만큼 추가 (현재시간 - 들어온 시간)
            answer += endTime - pq.top().at(0);
            
            // 작업이 끝났으므로 우선순위 큐에서 제거
            pq.pop();
        }
        // 큐가 비어있다면 다음 작업시간으로 넘긴다
        else {
            endTime = jobs.at(j).at(0);
        }
    }
    
    return answer / jobs.size();
}

int main() {
    vector<vector<int>> jobs = { { 0, 3 }, { 1, 9 }, { 2, 6 } };
    
    cout << solution(jobs) << endl;
    
    return 0;
}
