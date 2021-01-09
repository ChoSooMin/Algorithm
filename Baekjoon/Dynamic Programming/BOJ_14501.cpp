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
int dp[16];

int main() {
    // input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    
    // getAnswer
    // dp 배열을 P[i]와 같이 초기화?
    for (int i = 1; i <= N; i++) {
        dp[i] = P[i];
    }
    
    int ans = 1;
    // dp배열에는 현재 위치 i의 상담을 포함했을 때의 얻을 수 있는 최대 금액을 담고 있다.
    for (int i = 1; i <= N; i++) {
        if (i + (T[i] - 1) > N) { // 만약, 현재 날짜의 상담이 끝났을 때의 날짜가 N을 넘으면 상담할 수 없다는 뜻이므로 다음으로 넘긴다.
            continue;
        }
        
        // dp값 구하기
        for (int j = 1; j < i; j++) {
            if (j + (T[j] - 1) >= i) {
                continue;
            }

            dp[i] = max(dp[i], dp[j] + P[i]);
        }
        
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}
