//
//  Nhn_Pre_Test_sample.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/19.
//  Copyright © 2020 조수민. All rights reserved.
//
//  NHN Pre-Test 1차 기출문제(https://recruit.nhn.com/pdf/%ED%94%84%EB%A6%AC%ED%85%8C%EC%8A%A4%ED%8A%B8_1%EC%B0%A8_%EA%B8%B0%EC%B6%9C%EB%AC%B8%EC%A0%9C.pdf)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N;
vector<vector<int>> matrix;
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> checkMatrix;
queue<int> areaQ;

/**
 BFS 사용.
 
 */
void input() {
    cin >> N;
    
    matrix.resize(N);
    for (int i = 0; i < N; i++) {
        matrix.at(i).resize(N);
        
        for (int j = 0; j < N; j++) {
            cin >> matrix.at(i).at(j);
        }
    }
    
    checkMatrix.resize(N);
    for (int i = 0; i < N; i++) {
        checkMatrix.at(i).resize(N);
        
        for (int j = 0; j < N; j++) {
            checkMatrix.at(i).at(j) = 0;
        }
    }
}

void BFS() {
    queue<pair<int, int>> Q;
    
    Q.push(make_pair(0, 0));
    checkMatrix.at(0).at(0) = -1; // 지나온 곳을 체크해주기 위해 checkMatrix의 값을 -1로 바꿔준다.
    int areaSize = 0;
    
    while (true) {
        pair<int, int> cur = Q.front(); Q.pop(); // 현재 위치 (cur.first, cur.second)
        
        for (int i = 0; i < 4; i++) {
            // 근접한 위치 = (nextX, nextY)
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
            
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N || checkMatrix.at(nextX).at(nextY) == -1) { // 범위를 벗어났을 경우 & 이미 들른 곳이라면
                continue; // 건너뛴다.
            }
            
            if (matrix.at(nextX).at(nextY) == 1) { // 영역이라면
                areaSize++;
                Q.push(make_pair(nextX, nextY)); // 큐에 넣는다.
            }
            else if (matrix.at(nextX).at(nextY) == 0) {
                
            }
            
            checkMatrix.at(nextX).at(nextY) = -1; // 들렀다고 표시
        }
    }
}

int main() {
    input();
    
    
    return 0;
}
