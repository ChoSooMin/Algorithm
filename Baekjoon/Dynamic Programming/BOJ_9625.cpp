//
//  BOJ_9625.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/16.
//  Copyright © 2021 조수민. All rights reserved.
//
//  BABBA(https://www.acmicpc.net/problem/9625)

#include <stdio.h>
#include <iostream>

using namespace std;

int dpA[46];
int dpB[46];

int main() {
    int K;
    cin >> K;

    dpA[0] = 1; dpA[1] = 0;
    dpB[0] = 0; dpB[1] = 1;
    
    for (int i = 2; i <= K; i++) {
        dpA[i] = dpA[i - 1] + dpA[i - 2];
        dpB[i] = dpB[i - 1] + dpB[i - 2];
    }
    
    cout << dpA[K] << " " << dpB[K];
}
