//
//  BOJ_1018.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/05.
//  Copyright © 2021 조수민. All rights reserved.
//
//  체스판 다시 칠하기(https://www.acmicpc.net/problem/1018)

#include <stdio.h>
#include <iostream>

#define MAX 50

using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

char chess[MAX][MAX];

int WB_count(int x, int y) {
    int count = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[x + i][y + j] != WB[i][j])
                count++;
        }
    }
    
    return count;
}

int BW_count(int x, int y) {
    int count = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[x + i][y + j] != BW[i][j])
                count++;
        }
    }
    
    return count;
}

int main() {
    // input
    int M, N;
    cin >> M >> N;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chess[i][j];
        }
    }
    
    int answer = 0;
    for (int i = 0; i <= M - 8; i++) {
        for (int j = 0; j <= N - 8; j++) {
            answer = min(WB_count(i, j), BW_count(i, j));
        }
    }
    
    cout << answer << "\n";
    
    return 0;
}
