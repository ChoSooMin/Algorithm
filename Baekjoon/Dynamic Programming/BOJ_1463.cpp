//
//  BOJ_1463.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  1로 만들기(https://www.acmicpc.net/problem/1463)

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int dp[1000001]; // dp 사용

int main() {
    int N;
    cin >> N;
    
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    
    cout << dp[N] << endl;
    
    return 0;
}
