//
//  BOJ_1670.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/06/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  정상 회담 2(https://www.acmicpc.net/problem/1670)

#include <stdio.h>
#include <iostream>

using namespace std;

int dp[91];

int solution(int N)
{
    int answer = 0;
    
    dp[0] = dp[2] = 1; // 0명일 때와 2명일 때 악수하는 경우의 수는 1번
    
    for (int i = 4; i <= 2 * N; i+=2) // 2씩 증가해야 한다. (홀수면 악수하는 인원이 딱 나누어 떨어지지 않는다.)
        for (int j = 0; j <= i - 2; j+= 2) // dp값 구하기
        {
            dp[i] += dp[j] * dp[i - j - 2];
        }
    
    int ans = dp[2 * N];
    if (ans % 2 == 0)
        answer =  ans / 2;
    else
        answer = (ans + 1) / 2;
    
    return answer;
}

int main()
{
    int N;
    cin >> N; // N 입력 받기
    
    int ans = solution(N);
    
//    if (ans % 2 == 0)
//        cout << ans / 2 << endl;
//    else
//        cout << (ans + 1) / 2 << endl;
    
    cout << ans << endl; // 출력
    
    return 0;
}
