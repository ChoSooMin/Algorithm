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

#define MAX 501

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
     (i, j) 기준
     왼쪽 아래 : (i + 1, j)
     오른쪽 아래 : (i + 1, j + 1)
     
     (i, j) 기준
     왼쪽 위 : (i - 1, j - 1)
     오른쪽 위 : (i - 1, j)
     */
    int i = 1, j = 1;
    dp[i][j] = triangle[i][j];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j - 1 > i - 1) { // 오른쪽 위가 범위를 벗어날 경우
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + triangle[i][j]);
            }
            else if (i - 1 <= 0) { // 왼쪽 위가 범위를 벗어날 경우
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }
    }
    
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        ans = max(ans, dp[n][j]);
    }
    
    cout << ans << "\n";
    
    
    return 0;
}
