//
//  BOJ_17071.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/03.
//  Copyright © 2021 조수민. All rights reserved.
//
//  숨바꼭질 5(https://www.acmicpc.net/problem/17071)

#include <stdio.h>
#include <iostream>
#include <queue>

#define MAX 500001

using namespace std;

int dpK[MAX]; // index초 후 동생의 위치
int N, K;

void getDpK() {
    fill_n(dpK, MAX, -1);
    
    dpK[0] = K;
    
    int i = 1;
    while (true) {
        if(dpK[i - 1] + i > MAX)
            break;
        
        dpK[i] = dpK[i - 1] + i;
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    if (N == K) {
        cout << "0" << endl;
        return 0;
    }
    
    getDpK();
    
    queue<pair<int, int>> Q;
    Q.push({ N, 0 });
    while (!Q.empty()) {
        auto cur = Q.front().first;
        auto curTime = Q.front().second;
        Q.pop();
        
        for (int next : {cur + 1, cur - 1, 2 * cur}) {
            
            if (next < 0 || next >= MAX) // 해당 범위로 이동하는 것은 불가능
                continue;
            
            
            int nextTime = curTime + 1;
            
            if (dpK[nextTime] == next) {
                cout << nextTime << endl;
                return 0;
            }
            
            if (dpK[nextTime] > MAX || dpK[nextTime] == -1) {
                cout << -1 << endl;
                return 0;
            }
            
            Q.push({ next, nextTime });
        }
    }
    
    cout << -1 << endl;

    
    return 0;
}
