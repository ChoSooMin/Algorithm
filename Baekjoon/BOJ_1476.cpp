//
//  BOJ_1476.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/16.
//  Copyright © 2021 조수민. All rights reserved.
//
//  날짜 계산(https://www.acmicpc.net/problem/1476)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int E, S, M;
    cin >> E >> S >> M;
    
    int year = 1;
    while(true) {
        if (year % 15 == E && year % 28 == S && year % 19 == M)
            break;
        
        year++;
    }
    
    cout << year << "\n";
    
    return 0;
}
