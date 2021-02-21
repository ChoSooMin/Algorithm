//
//  SWEA_2025.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/22.
//  Copyright © 2021 조수민. All rights reserved.
//
//  N줄덧셈(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&contestProbId=AV5QFZtaAscDFAUq&categoryId=AV5QFZtaAscDFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=1&pageSize=10&pageIndex=2&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + i;
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
