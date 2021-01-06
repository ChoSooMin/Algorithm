//
//  Programmers_1829.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/06.
//  Copyright © 2021 조수민. All rights reserved.
//
//  카카오프렌즈 컬러링북(https://programmers.co.kr/learn/courses/30/lessons/1829)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방문했는지 체크하는 벡터
vector<vector<bool>> isVisited;
// 상하좌우 움직이기 위한 배열
int dx[4];
int dy[4];


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // init
    isVisited.resize(m);
    for (int i = 0; i < isVisited.size(); i++) {
        isVisited.at(i).assign(n, false);
    }
    
    dx[0] = 0; dy[0] = -1; // 상
    dx[1] = 0; dy[1] = 1; // 하
    dx[2] = -1; dy[2] = 0; // 좌
    dx[3] = 1; dy[3] = 0; // 우
    
    //
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    while (!Q.empty()) {
        int curX = Q.front().first;
        int curY = Q.front().second;
        
        for (int i = 0; i < 4; i++) { // 움직이기
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n) // 범위를 벗어나면 다음으로
                continue;
            
            if (isVisited.at(nextX).at(nextY)) // 이미 방문한 곳이라면 다음으로
                continue;
            
            // 범위를 벗어나지 않고, 이미 방문한 곳이 아니라면?
            Q.push(make_pair(nextX, nextY)); // 큐에 (nextX, nextY)를 넣는다.
            isVisited.at(nextX).at(nextY) = true; // 방문했다고 표시 남기기
            
            if (picture.at(nextX).at(nextY) != 0) {
                max_size_of_one_area++;
            }
        }
        
        Q.pop();
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area; // 몇 개의 영역이 있는지
    answer[1] = max_size_of_one_area; // 가장 큰 영역의 크기
    return answer;
}

int main() {
    vector<int> sol = solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    cout << sol.at(1) << endl;
    
    return 0;
}
