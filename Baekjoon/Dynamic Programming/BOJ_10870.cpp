//
//  BOJ_10870.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/16.
//  Copyright © 2021 조수민. All rights reserved.
//
//  피보나치 수 5(https://www.acmicpc.net/problem/10870)

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[21];

int main() {
    dp[0] = 0; dp[1] = 1;
    
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    cout << dp[n];
    
    return 0;
}
