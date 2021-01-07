//
//  BOJ_9095.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/07.
//  Copyright © 2021 조수민. All rights reserved.
//
//  1, 2, 3 더하기(https://www.acmicpc.net/problem/9095)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int t;
vector<int> nums;
int dp[12]; // 메모이제이션 사용

void input() {
    cin >> t;
    
    nums.resize(t);
    for(int i = 0; i < nums.size(); i++) {
        cin >> nums.at(i);
    }
}

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int i = 4; i < 12; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main() {
    input();
    
    solve();
    
    for (int i = 0; i < nums.size(); i++) {
        cout << dp[nums.at(i)] << endl;
    }
    
    return 0;
}
