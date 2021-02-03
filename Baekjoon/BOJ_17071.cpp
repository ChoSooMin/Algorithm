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

int dpN[MAX]; // 수빈이가 index위치까지 도달하는데 걸리는 시간
int dpK[MAX]; // index초 후 동생의 위치
int N, K;

void getDpK() {
    dpK[0] = K;
    for (int i = 1; i <= MAX; i++) {
        if (dpK[i - 1] + i > MAX)
            return;
        dpK[i] = dpK[i - 1] + i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    getDpK();
    
    queue<int> Q;
    Q.push(N);
    dpN[N] = 0;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        
        for (int next : {cur + 1, cur - 1, 2 * cur}) {
//            cout << next << endl;
            
            if (next < 0 || next >= MAX) // 해당 범위로 이동하는 것은 불가능
                continue;
            
            dpN[next] = dpN[cur] + 1; //
            
            if (dpK[dpN[next]] == next) {
                cout << dpN[next] << endl;
                return 0;
            }
            
            if (dpK[dpN[next]] > MAX) {
                cout << -1 << endl;
                return 0;
            }
            
            Q.push(next);
        }
    }
    
    cout << -1 << endl;
    
    return 0;
}
