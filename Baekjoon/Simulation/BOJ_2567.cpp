//
//  BOJ_2567.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  색종이 - 2(https://www.acmicpc.net/problem/2567)

#include <stdio.h>
#include <iostream>

int board[101][101]; // 도화지
// 인접한 부분이 비어있는 부분인지 확인하기 위한 변수
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

using namespace std;

/**
 1. 도화지에 색종이가 올려진 부분을 모두 1로 바꾼다.
 2. for문을 돌려서, 색종이가 올려진 부분이라면 인접한 곳이 비어있을 경우, answer + 1을 한다.
 */
void fillPaper(int x, int y) {
    for (int i = x; i < x + 10; i++) {
        for (int j = y; j < y + 10; j++) {
            board[i][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        fillPaper(x, y);
    }
    
    int answer = 0;
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if (board[i][j] == 1) { // 색종이가 올려진 부분이라면
                for (int dir = 0; dir < 4; dir++) { // 인접한 곳이 비었는지 확인
                    int nextX = i + dx[dir];
                    int nextY = j + dy[dir];
                    
                    if (board[nextX][nextY] == 0) // 인접한 곳이 비었다면
                        answer++; // answer + 1
                }
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
