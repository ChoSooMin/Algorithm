//
//  BOJ_1009.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/21.
//  Copyright © 2021 조수민. All rights reserved.
//
//  분산처리(https://www.acmicpc.net/problem/1009)

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int test_case = 0; test_case < T; test_case++) {
        int a, b;
        cin >> a >> b;
        
        int answer = a;
        
        // 모든 1의 자리는 지수 4를 주기로 순환한다.
        if (b % 4 == 0)
            b = 4;
        else
            b %= 4;
        
        answer = pow(a, b);
        
        if (answer % 10 == 0)
            cout << 10 << "\n";
        else
            cout << answer % 10 << "\n";
    }
    
    return 0;
}
