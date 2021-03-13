//
//  BOJ_2636.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/12.
//  Copyright © 2021 조수민. All rights reserved.
//
//  치즈(https://www.acmicpc.net/problem/2636)

#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX 100

using namespace std;

int rectangle[MAX][MAX];

// 위, 오른쪽, 아래, 왼쪽
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Q;
int H, W;

void getEdgeCheese() {
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            bool isEdge = false;
            
            if (rectangle[i][j] == 1) { // 현재 위치가 치즈가 있는 부분이고
                for (int dir = 0; dir < 4; dir++) { // 인접한 곳 중 한 부분이라도 치즈가 없다면 바깥쪽에 있다는 뜻,,
                    
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    cin >> H >> W;
        
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> rectangle[i][j];
        }
    }
    
    return 0;
}
