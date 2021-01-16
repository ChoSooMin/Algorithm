//
//  BOJ_14890.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/14.
//  Copyright © 2021 조수민. All rights reserved.
//
//  경사로(https://www.acmicpc.net/problem/14890)

#include <stdio.h>
#include <iostream>

using namespace std;

int N, L;
int map[100][100];

void input() {
    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
}

int main() {
    input();
    
    
    // 가로
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int prev = map[i][j];
            
            if (i == 0 && j == 0) // (0, 0)은 건너뛴다
                continue;
            
            
        }
    }
    
    // 세로
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int prev = map[j][i];
        }
    }
    
    return 0;
}
