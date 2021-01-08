//
//  BOJ_11053.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  가장 긴 증가하는 부분 수열(https://www.acmicpc.net/problem/11053)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N;
int a[1000];
int dp[1000];

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // dp
    // dp[i]에는 i까지의 증가하는 부분 수열이 가장 긴 값을 담고 있다.
    // 처음부터 i - 1까지의 a[n]중, a[i]보다 작은 값들 중, dp의 max값에서 +1(현재 값 추가) 하면 될듯?
    dp[0] = 1;
    int ans = -1;
    
    if (a[0] < a[1]) {
        dp[1] = 2;
    }
    else {
        dp[1] = 1;
    }
    
    for (int i = 2; i < N; i++) {
        int maxDp = 0;
        int curData = a[i];
        
        for (int j = 0; j < i - 1; j++) {
            if (a[j] < curData) {
                maxDp = max(maxDp, dp[j]);
            }
        }
        
        dp[i] = maxDp + 1;
        ans = max(ans, dp[i]);
    }
    
//    for (int i = 0; i < N; i++) {
//        cout << dp[i] << " ";
//    }
//    cout << endl;
    
    cout << ans << endl;
    
    return 0;
}
