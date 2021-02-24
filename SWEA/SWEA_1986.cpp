//
//  SWEA_1986.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/25.
//  Copyright © 2021 조수민. All rights reserved.
//
//  지그재그 숫자(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV5PxmBqAe8DFAUq&categoryId=AV5PxmBqAe8DFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=2&pageSize=10&pageIndex=1&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    dp[1] = 1;
    for (int i = 1; i < 11; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i - 1] - i;
        }
        else {
            dp[i] = dp[i - 1] + i;
        }
    }
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        
        cout << "#" << test_case << " " << dp[N] << "\n";
    }
    
    return 0;
}
