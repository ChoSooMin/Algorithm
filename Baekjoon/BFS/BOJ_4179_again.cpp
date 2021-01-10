//
//  BOJ_4179_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  불!(https://www.acmicpc.net/problem/4179)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int R, C;
char m[1001][1001];
int jh[1001][1001];
int fire[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> jhQ;
queue<pair<int, int>> fireQ;

void input() {
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            m[i][j] = str[j];
            // 지훈이와 불의 BFS를 담은 배열은 모두 -1로 초기화한다.
            jh[i][j] = -1;
            fire[i][j] = -1;
            
            if (m[i][j] == 'J') {
                jhQ.push({ i, j });
                jh[i][j] = 0;
            }
            if (m[i][j] == 'F') {
                fireQ.push({ i, j });
                fire[i][j] = 0;
            }
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    
    while (!fireQ.empty()) {
        int curX = fireQ.front().first;
        int curY = fireQ.front().second;
        fireQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) // 범위를 벗어남
                continue;
            
            if (fire[nx][ny] >= 0 || m[nx][ny] == '#') // 이미 불이 번진 곳이거나 벽일 경우
                continue;
            
            fire[nx][ny] = fire[curX][curY] + 1;
            fireQ.push({ nx, ny }); // fireQ에 위치를 넣는다.
        }
    }
    
    while (!jhQ.empty()) {
        int curJhX = jhQ.front().first;
        int curJhY = jhQ.front().second;
        jhQ.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextJhX = curJhX + dx[i];
            int nextJhY = curJhY + dy[i];
            
            if (nextJhX < 0 || nextJhX >= R || nextJhY < 0 || nextJhY >= C) {
                cout << jh[curJhX][curJhY] + 1;;
                return 0;
            }
            
            if (jh[nextJhX][nextJhY] >= 0 || m[nextJhX][nextJhY] == '#')
                continue;
            
            if (fire[nextJhX][nextJhY] != -1 && fire[nextJhX][nextJhY] <= jh[curJhX][curJhY] + 1)
                continue;
            
            jh[nextJhX][nextJhY] = jh[curJhX][curJhY] + 1;
            jhQ.push({ nextJhX, nextJhY });
        }
    }
    
    cout << "IMPOSSIBLE";
    
    return 0;
}
