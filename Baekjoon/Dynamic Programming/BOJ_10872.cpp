//
//  BOJ_10872.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  팩토리얼(https://www.acmicpc.net/problem/10872)

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[11];

int main() {
    int N;
    cin >> N;
    
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = i * dp[i - 1];
    }
    
    cout << dp[N];
    
    return 0;
}
