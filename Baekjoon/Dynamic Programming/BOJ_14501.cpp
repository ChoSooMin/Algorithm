//
//  BOJ_14501.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/09.
//  Copyright © 2021 조수민. All rights reserved.
//
//  퇴사(https://www.acmicpc.net/problem/14501)

#include <stdio.h>
#include <iostream>

using namespace std;

int N;
int T[16];
int P[16];
int dp[16]; // dp는 0으로 초기화한다.

int main() {
    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // getAnswer
    // N에서부터 1까지 (뒤에서 앞으로) 접근하여 dp값을 구한다.
    for (int i = N; i >= 1; i--) {
        if (i + T[i] - 1 > N) { // 끝나는 날이 N을 넘으면 일을 할 수 없다.
            dp[i] = dp[i + 1]; // 현재 날짜에는 일을 안한다는 뜻이므로, dp[i]에 dp[i + 1]을 넣는다. (뒤에서부터 접근했기 때문에 이전 값이 dp[i + 1]이다)
            continue;
        }
        
        // dp[i]는 두가지 경우로 나뉠 수 있다.
        // 1. i 날짜에 일을 하는 경우
        // -> 이 경우는 i + T[i]일 전까지는 일을 할 수 없고, i + T[i]일부터 일을 할 수 있다. 그러므로, 이 때의 dp는 dp[i + T[i]] + P[i](현재 날짜에 일을 했을때 얻을 수 있는 금액)이다.
        // 2. i 날짜에 일을 하지 않는 경우
        // -> 이 경우는 뒤에서부터 접근했기 때문에 이전 값이 dp[i + 1]이고, 이걸 dp[i]에 넣어준다.
        // 이 두 가지 경우에서 더 큰 값을 dp[i]값으로 하면 된다.
        dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
    }
    
    // 결국, dp[1]에 있는 값이 정답이 된다.
    cout << dp[1] << endl;
    
    return 0;
}
