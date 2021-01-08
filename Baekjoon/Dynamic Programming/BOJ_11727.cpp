//
//  BOJ_11727.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  2 x N 타일링 2(https://www.acmicpc.net/problem/11727)

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int dp[1001];

int main() {
    cin >> n;
    
    dp[1] = 1; dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
