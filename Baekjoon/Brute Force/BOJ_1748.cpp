//
//  BOJ_1748.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/24.
//  Copyright © 2021 조수민. All rights reserved.
//
//  수 이어 쓰기 1

#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAX 100000001

using namespace std;

int dp[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int answer = 0;
    string str = to_string(N);
    for (int i = 1; i < str.length(); i++) {
        int num = pow(10, i) - pow(10, i - 1);
        
        answer += i * num;
    }
    
    int minus = pow(10, str.length() - 1) - 1;
    answer += str.length() * (N - minus);
    
    cout << answer << "\n";
    
    return 0;
}
