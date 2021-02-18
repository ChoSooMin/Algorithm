//
//  BOJ_11727_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/19.
//  Copyright © 2021 조수민. All rights reserved.
//
//  2xn 타일링 2 (https://www.acmicpc.net/problem/11727)

#include <stdio.h>
#include <iostream>

#define MAX 1001

using namespace std;

int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    dp[0] = 0; dp[1] = 1; dp[2] = 3;
    
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
