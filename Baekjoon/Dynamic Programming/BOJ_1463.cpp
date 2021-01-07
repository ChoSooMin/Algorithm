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

void getDp() {
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    
    for (int i = 3; i < 1000001; i++) {
        // 1. /3
        int first = 1000;
        int second = 1000;
        int third = 1000;
        if (i % 3 == 0) {
            first = 1 + dp[i / 3];
        }
        
        // 2. /2
        if (i % 2 == 0) {
            second = 1 + dp[i / 2];
        }
        
        // 3. -1
        third = 1 + dp[i - 1];
        
        int min1 = min(first, second);
        int min2 = min(min1, third);
        
        dp[i] = min2;
    }
}

int main() {
    int N;
    cin >> N;
    getDp();
    
    cout << dp[N] << endl;
    
    return 0;
}
