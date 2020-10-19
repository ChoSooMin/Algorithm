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
priority_queue<int, vector<int>, greater<int>> areaQ;

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
    int areaSize = 0;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            areaSize = 0;
            // 현재 위치가 0이거나 이미 접근한 곳이라면 넘어간다.
            if (matrix.at(i).at(j) == 0 || checkMatrix.at(i).at(j) == -1) {
                continue;
            }
            
            // 이미 접근하지 않았고, 영역에 속할 때 (1일 때)
            Q.push(make_pair(i, j));
            checkMatrix.at(i).at(j) == -1; // 방문했다는 표시를 남긴다.
            
            while (!Q.empty()) {
                auto current = Q.front(); Q.pop(); // 큐의 제일 앞에 있는 값을 가져온다.
                areaSize++; // 큐에서 원소를 하나씩 뺄때마다 영역크기 +1 해준다.
                
                for (int dir = 0; dir < 4; dir++) {
                    // 근접한 곳(다음)
                    int nx = current.first + dx[dir];
                    int ny = current.second + dy[dir];
                    
                    if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix.at(i).size()) { // 범위 밖일 경우 넘어간다.
                        continue;
                    }
                    if (checkMatrix.at(nx).at(ny) == -1 || matrix.at(nx).at(ny) != 1) { // 이미 방문한 곳이거나 영역에 속하지 않으면 넘어간다.
                        continue;
                    }
                    
                    checkMatrix.at(nx).at(ny) = -1; // 방문했다고 체크해준다.
                    Q.push(make_pair(nx, ny)); // 큐에 넣어준다.
                }
            }
            
            // (i, j)를 시작점으로 하는 BFS가 종료
            areaQ.push(areaSize); // areaSize를 영역 큐에 넣어준다.
        }
    }
    
    int sizeCount = areaQ.size();
    if (sizeCount == 0) {
        cout << sizeCount << endl;
        return;
    }
    else {
        cout << sizeCount << endl;
        while (!areaQ.empty()) {
            auto cur = areaQ.top(); areaQ.pop();
            cout << cur << " " ;
        }
        cout << endl;
    }
}

int main() {
    input();
    BFS();
    
    return 0;
}
