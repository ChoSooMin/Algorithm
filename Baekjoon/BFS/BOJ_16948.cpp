//
//  BOJ_16948.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/26.
//  Copyright © 2021 조수민. All rights reserved.
//
//  데스 나이트(https://www.acmicpc.net/problem/16948)

#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX 200

using namespace std;

int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };
int chess[MAX][MAX];
int visit[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            chess[i][j] = MAX;
        }
    }
    
    queue<pair<int, int>> Q;
    Q.push({ r1, c1 });
    chess[r1][c1] = 0;
    visit[r1][c1] = 1;
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        
        int curX = cur.first;
        int curY = cur.second;
        
        cout << "(curX, curY) = (" << curX << ", " << curY << ") || ";
        
        for (int dir = 0; dir < 6; dir++) {
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];
            
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
                continue;
            
            cout << "(nextX, nextY) = (" << nextX << ", " << nextY << ")" << "\n";
            
            chess[nextX][nextY] = min(chess[curX][curY] + 1, chess[nextX][nextY]);
            visit[nextX][nextY] = 1;
            
            if (nextX == r2 && nextY == c2)
                break;
            
            Q.push({ nextX, nextY });
        }
    }
    
    if (visit[r2][c2] == 0) {
        cout << "-1" << "\n";
    }
    else {
        cout << chess[r2][c2] << "\n";
    }
    
    return 0;
}
