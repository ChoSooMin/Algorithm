//
//  BOJ_11726.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  2 x n 타일링(https://www.acmicpc.net/problem/11726)

#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int dp[1001];

int main() {
    cin >> n;
    
    dp[0] = 1; dp[1] = 1;
    dp[2] = 2; dp[3] = 3;
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
