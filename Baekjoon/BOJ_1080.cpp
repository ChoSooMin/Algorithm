//
//  BOJ_1080.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  행렬(https://www.acmicpc.net/problem/1080)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> matrixA, matrixB;

void input() {
    // input
    int N, M;
    
    cin >> N >> M;
    
    matrixA.resize(N);
    matrixB.resize(N);
    for (int i = 0; i < N; i++) {
        matrixA.at(i).resize(M);
        matrixB.at(i).resize(M);
    }
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++) {
            matrixA.at(i).at(j) = str[j] - '0'; // char 데이터형을 int형을 변환하는 간단한 방법 (숫자가 아스키 코드라는 것을 활용)
        }
    }
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++) {
            matrixB.at(i).at(j) = str[j] - '0';
        }
    }
}

int main() {
    
    
    return 0;
}
