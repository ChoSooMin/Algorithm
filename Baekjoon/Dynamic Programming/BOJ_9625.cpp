//
//  BOJ_9625.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/16.
//  Copyright © 2021 조수민. All rights reserved.
//
//  BABBA(https://www.acmicpc.net/problem/9625)

#include <stdio.h>
#include <iostream>

using namespace std;

string dp[46];

int main() {
    int K;
    cin >> K;
    
    dp[0] = "A"; dp[1] = "B";
    for (int i = 2; i <= K; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    int a = 0, b = 0;
    for (int index = 0; index < dp[K].length(); index++) {
        if (dp[K][index] == 'A')
            a++;
        else
            b++;
    }
    
    cout << a << " " << b;
}
