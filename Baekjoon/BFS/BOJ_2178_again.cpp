//
//  BOJ_2178_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  미로 탐색(https://www.acmicpc.net/problem/2178)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int m[101][101];
int dist[101][101]; // 방문했는지 확인 & (1, 1)부터 현재 위치까지 오는데 얼마나 걸리는지 저장
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++) {
            int cur = str[j - 1] - '0';
            m[i][j] = cur;
            
//            dist[i][j] = -1;
        }
    }
}

void BFS() {
    queue<pair<int, int>> Q;
    
    Q.push({ 1, 1 }); // 시작점은 (1, 1)
    dist[1][1] = 1;
    
    while(!Q.empty()) {
        int curX = Q.front().first;
        int curY = Q.front().second;
        Q.pop();
        
        for (int dir = 0; dir < 4; dir++) {
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];
            
            
            // 범위 넘김
            if (nextX < 1 || nextX > N || nextY < 1 || nextY > M)
                continue;
            
            if (m[nextX][nextY] != 1 || dist[nextX][nextY] != 0) // 비어있는 공간이라면 continue
                continue;
            
            if (dist[nextX][nextY] != 0) // 이미 방문한 곳이라면?
                continue;
            
            dist[nextX][nextY] = dist[curX][curY] + 1;
            Q.push({nextX, nextY});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    BFS();
    
    cout << dist[N][M] << endl;
    
    return 0;
}
