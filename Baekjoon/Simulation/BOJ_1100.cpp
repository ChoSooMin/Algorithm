//
//  BOJ_1100.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/03.
//  Copyright © 2021 조수민. All rights reserved.
//
//  하얀 칸(https://www.acmicpc.net/problem/1100)

#include <stdio.h>
#include <iostream>

using namespace std;

char chess[8][8];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> chess[i][j];
        }
    }
    
    int answer = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                if (chess[i][j] == 'F') {
                    answer++;
                }  
            }
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
