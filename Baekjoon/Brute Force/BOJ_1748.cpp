//
//  BOJ_1748.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/24.
//  Copyright © 2021 조수민. All rights reserved.
//
//  수 이어 쓰기 1

#include <stdio.h>
#include <iostream>

#define MAX 100000001

using namespace std;

int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        string str = to_string(i);
        dp[i] = dp[i - 1] + str.length();
    }
    
    cout << dp[N] << "\n";
    
    return 0;
}
