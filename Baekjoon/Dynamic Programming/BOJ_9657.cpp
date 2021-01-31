//
//  BOJ_9657.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/31.
//  Copyright © 2021 조수민. All rights reserved.
//
//  돌 게임3(https://www.acmicpc.net/problem/9657)

#include <stdio.h>
#include <iostream>

#define MAX 1001

using namespace std;

int N;
int dp[MAX]; // 상근이 기준 N값일 때 이기는지(1), 지는지(0) 저장하는 배열

// dp 사용
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    // 1개, 3개, 4개씩 가져갈 수 있다.
    dp[0] = 0; dp[1] = 1; dp[2] = 0; dp[3] = 1; dp[4] = 1;
    
    // 현재 상태로부터 다음 상태를 결정한다.
    for (int i = 1; i <= N; i++) {
        if (dp[i] == 0) {
            if (i + 1 <= N)
                dp[i + 1] = 1;
            if (i + 3 <= N)
                dp[i + 3] = 1;
            if (i + 4 <= N)
                dp[i + 4] = 1;
        }
    }
    
    /**
    if (dp[N] == 1)
        cout << "SK" << "\n";
    else
        cout << "CY" << "\n";
    */
    cout << ((dp[N] == 1) ? "SK" : "CY") << "\n";
    
    return 0;
}
