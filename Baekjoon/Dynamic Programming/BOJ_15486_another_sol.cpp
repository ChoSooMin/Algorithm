//
//  BOJ_15486.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/09.
//  Copyright © 2021 조수민. All rights reserved.
//
//  퇴사 2(https://www.acmicpc.net/problem/15486)

#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int T[1500001];
int P[1500001];
int dp[1500001]; // dp는 0으로 초기화한다.

int main() {
    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // getAnswer
    // 앞에서부터 접근(BOJ_15486은 뒤에서부터 접근했을 때)
    for (int i = 1; i <= N; i++) {
        // 1. i날에 일을 할 때
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        
        // 2. i날에 일을 안 할 때
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }
    
    cout << dp[N + 1] << endl;
    
    return 0;
}
