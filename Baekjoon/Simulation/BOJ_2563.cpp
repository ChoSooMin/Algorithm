//
//  BOJ_2563.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/09.
//  Copyright © 2021 조수민. All rights reserved.
//
//  색종이(https://www.acmicpc.net/problem/2563)

#include <stdio.h>
#include <iostream>

#define MAX 101

using namespace std;

int p[MAX][MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    int maxX = 0, maxY = 0; // 효율성을 위해 maxX, maxY를 사용한다.
    for (int test_case = 0; test_case < N; test_case++) {
        int x, y;
        cin >> x >> y;
        
        if (maxX < x)
            maxX = x;
        if (maxY < y)
            maxY = y;
        
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                p[i][j] = 1;
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < maxX + 10; i++) { // 100까지 다 확인할 필요 없이 maxX와 maxY를 사용한다.
        for (int j = 0; j < maxY + 10; j++) {
            if (p[i][j] == 1)
                answer++;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
