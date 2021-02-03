//
//  BOJ_11048.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/03.
//  Copyright © 2021 조수민. All rights reserved.
//
//  이동하기(https://www.acmicpc.net/problem/11048)

#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int dp[MAX][MAX];
int a[MAX][MAX];
int N, M;
int dx[3] = { 1, 0, 1 };
int dy[3] = { 0, 1, 1 };

int main() {
    cin >> N >> M;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
        }
    }
    
    queue<pair<int, int>> Q;
    dp[1][1] = a[1][1];
    Q.push({ 1, 1 });
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        
        for (int dist = 0; dist < 3; dist++) {
            int nextX = cur.first + dx[dist];
            int nextY = cur.second + dy[dist];
            
            if (nextX < 1 || nextX > N || nextY < 1 || nextY > M)
                continue;
            
            dp[nextX][nextY] = max(dp[cur.first][cur.second] + a[nextX][nextY], dp[nextX][nextY]);
            Q.push({ nextX, nextY });
        }
    }
    
    cout << dp[N][M] << "\n";
    
    return 0;
}
