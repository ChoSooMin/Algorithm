//
//  BOJ_7576_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  토마토(https://www.acmicpc.net/problem/7576)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int tomato[1002][1002];
int day[1002][1002];
queue<pair<int, int>> Q;
int maxDay;

void input() {
    cin >> N >> M;
    
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) {
            cin >> tomato[i][j];
            
            if (tomato[i][j] == 1) { // 토마토가 익은 곳은 큐에 위치를 넣어준다.
                Q.push({ i, j });
            }
            if (tomato[i][j] == 0) { // 토마토가 있는 위치이고, 아직 익지 않은 곳이라면
                day[i][j] = -1;
            }
        }
    }
}

void BFS() {
    while (!Q.empty()) {
        int curX = Q.front().first;
        int curY = Q.front().second;
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) // 범위를 벗어나면 넘어간다.
                continue;
            
            if (tomato[nextX][nextY] == -1) // 토마토가 없는 곳이면 넘어간다.
                continue;
            
            if (day[nextX][nextY] >= 0) // 이미 토마토가 익은 곳이라면 넘어간다.
                continue;
            
            day[nextX][nextY] = day[curX][curY] + 1;
            Q.push({ nextX, nextY });
            maxDay = max(maxDay, day[nextX][nextY]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    BFS();
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (day[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << maxDay << endl;
    return 0;
}
