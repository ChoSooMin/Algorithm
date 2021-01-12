//
//  BOJ_16918.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/12.
//  Copyright © 2021 조수민. All rights reserved.
//
//  봄버맨(https://www.acmicpc.net/problem/16918)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int R, C, N;
char a[201][201];
queue<pair<int, int>> bombQ; // 폭탄의 위치, 폭탄이 설치된 시간이 들어있는 큐 { {1, 0}, 2 }
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        string str = "";
        
        cin >> str;
        for (int j = 0; j < C; j++) {
            a[i][j] = str[j];
        }
    }
}

void output() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void queueing() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] == 'O')
                bombQ.push({ i, j });
        }
    }
}

void installBomb() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] != 'O') {
                a[i][j] = 'O';
            }
        }
    }
}

void boom() {
    while (!bombQ.empty()) {
        int bombX = bombQ.front().first;
        int bombY = bombQ.front().second;
        bombQ.pop();
        
        a[bombX][bombY] = '.';
        for (int i = 0; i < 4; i++) {
            int nextX = bombX + dx[i];
            int nextY = bombY + dy[i];
            
            if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C)
                continue;
            
            a[nextX][nextY] = '.';
        }
    }
}

void solve() {
    for (int curTime = 0; curTime < N; ) {
        queueing();
        curTime++;
        
        if (curTime == N)
            return;
        
        installBomb();
        curTime++;
        
        if (curTime == N)
            return;
        
        boom();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력받기
    input();
    
    // N이 짝수일 경우, 모든 값을 O으로 출력하고 return한다
    if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << endl;
        }
        
        return 0;
    }
    else {
        solve();
        
        // output
        output();
    }
    
    
    return 0;
}
