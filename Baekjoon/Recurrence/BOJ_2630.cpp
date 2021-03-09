//
//  BOJ_2630.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  색종이 만들기(https://www.acmicpc.net/problem/2630)

#include <stdio.h>
#include <iostream>

#define MAX 128

using namespace std;

int wCount, bCount;
int paper[MAX][MAX];

void getAnswer(int x, int y, int N) {
    int count = 0;
    
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (paper[i][j]) { // 파란색일 때 count값을 늘린다
                count++;
            }
        }
    }
    
    if (!count) // 범위 내의 색이 모두 흰색일 때
        wCount++;
    else if (count == N * N) // 범위 내의 색이 모두 파란색일 때
        bCount++;
    else { // 색이 하나라도 다를 경우, 종이를 반으로 자른다
        getAnswer(x, y, N / 2);
        getAnswer(x, y + N / 2, N / 2);
        getAnswer(x + N / 2, y, N / 2);
        getAnswer(x + N / 2, y + N / 2, N / 2);
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }
    
    getAnswer(0, 0, N);

    cout << wCount << "\n" << bCount << "\n";
    
    return 0;
}
