//
//  BOJ_1932.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/27.
//  Copyright © 2021 조수민. All rights reserved.
//
//  정수 삼각형(https://www.acmicpc.net/problem/1932)

#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX 501 // 삼각형의 최대 크기는 500이므로 500 * 501 / 2

using namespace std;

int triangle[MAX][MAX]; // i층에 있는 j번째 숫자
int dp[MAX][MAX];
int dy[2] = { 0, 1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    
    /**
     왼쪽 아래 : (i + 1, j)
     오른쪽 아래 : (i + 1, j + 1)
     */
    
    queue<pair<int, int>> Q;
    Q.push({ 1, 1 });
    dp[1][1] = triangle[1][1];
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        
        for (int dir = 0; dir < 2; dir++) {
            int nextI = cur.first + 1;
            int nextJ = cur.second + dy[dir];
            
            if (nextI > n || nextJ > nextI)
                continue;
            
            dp[nextI][nextJ] = max(dp[cur.first][cur.second] + triangle[nextI][nextJ], dp[nextI][nextJ]);
            Q.push({ nextI, nextJ });
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = max(ans, dp[n][j]);
    }
    
    cout << ans << "\n";
    
    
    return 0;
}
