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
queue<pair<pair<int, int>, int>> bombQ; // 폭탄의 위치, 폭탄이 설치된 시간이 들어있는 큐 { {1, 0}, 2 }
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력받기
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        string str = "";
        
        cin >> str;
        for (int j = 0; j < C; j++) {
            a[i][j] = str[j];
            
            if (a[i][j] == '0') {
                bombQ.push({{ i, j }, 0}); // 초기에 폭탄이 설치된 곳은 bombQ에 {{i, j}, 0}을 넣어준다
            }
        }
    }
    
    int lastInstallTime = 0;
    for (int i = 0; i <= N; i++) {
        // 1. N이 폭탄을 설치하는 시간일 때(lastInstallTime으로부터 2초가 지났을 때)
        // 폭탄을 설치하고, lastInstallTime을 N으로 바꿔준다.
        // bombQ에 폭탄의 위치와 N을 쌍으로 넣어준다.
        if (N == lastInstallTime + 2) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (a[i][j] != '0') { // 폭탄이 설치되어 있지 않은 곳이라면
                        a[i][j] = '0'; // 폭탄을 설치한다.
                        bombQ.push({{i, j}, N});
                    }
                }
            }
            
            lastInstallTime = N;
        }
        
        // 2. N이 폭탄이 터지는 시간일 때(Q의 front.second가 N - 3일때)
        // dx, dy를 사용하여 폭탄이 있는 곳과, 인접한 곳을 모두 터뜨린다.
        if (!bombQ.empty() && bombQ.front().second == N - 3) {
            while (!bombQ.empty() && bombQ.front().second != N - 3) { // Q의 front.second가 N - 3일동안 반복문
                auto bomb = bombQ.front(); bombQ.pop();
                a[bomb.first.first][bomb.first.second] = '.';
                
                for (int i = 0; i < 4; i++) {
                    int nextX = bomb.first.first + dx[i];
                    int nextY = bomb.first.second + dy[i];
                    
                    if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) // 범위를 벗어나면 넘긴다.
                        continue;
                    
                    a[nextX][nextY] = '.';
                }
            }
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
