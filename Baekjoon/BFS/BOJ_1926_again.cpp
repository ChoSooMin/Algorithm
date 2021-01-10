//
//  BOJ_1926_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  그림(https://www.acmicpc.net/problem/1926)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int vis[501][501]; // 방문하지 않은 곳은 0, 방문한 곳은 1 (초기화는 0)
int a[501][501];
int n, m;
int maxArea;
int areaNum;

void input() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

void BFS(int x, int y) {
    queue<pair<int, int>> Q;
    
    int curArea = 1;
    
    Q.push({x, y}); // 시작점을 먼저 넣는다.
    vis[x][y] = 1; // 시작점 방문 표시
    
    while(!Q.empty()) { // Q가 비어있지 않은 동안
        int curX = Q.front().first;
        int curY = Q.front().second;
        Q.pop();
        
        // 상하좌우
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            // 범위를 벗어나거나, 이미 방문한 곳이라면 넘어간다.
            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || vis[nextX][nextY] == 1)
                continue;
            
            if(a[nextX][nextY] != 1) { // 그림이 아닌 곳이라면 넘어감
                continue;
            }
            
            // 범위를 벗어나지 않고, 그림이 있는 곳
            curArea++; // 영역의 크기를 +1 해준다.
            vis[nextX][nextY] = 1; // 방문했다고 표시를 남겨준다.
            Q.push({nextX, nextY}); // Q에 push
        }
    }
    
    maxArea = max(maxArea, curArea);
}

int main() {
    input();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1 && vis[i][j] != 1) {
                BFS(i, j);
                areaNum++;
            }
        }
    }
    
    cout << areaNum << endl;
    cout << maxArea << endl;
    
    return 0;
}
