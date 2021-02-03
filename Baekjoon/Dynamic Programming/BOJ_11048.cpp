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
    
    // Queue를 사용하면 메모리 초과가 발생한다.
    // 이유) 같은 위치를 큐에 여러번 넣고 있기 때문에, 큐의 크기가 거의 지수함수를 따라 커진다.
    dp[1][1] = a[1][1];
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= M; y++) {
            if (x == N && y == M)
                break;
            
            for (int dist = 0; dist < 3; dist++) {
                int nextX = x + dx[dist];
                int nextY = y + dy[dist];
                
                if (nextX < 1 || nextX > N || nextY < 1 || nextY > M)
                    continue;
                
                dp[nextX][nextY] = max(dp[nextX][nextY], dp[x][y] + a[nextX][nextY]);
            }
        }
    }
    
    cout << dp[N][M] << "\n";
    
    return 0;
}
