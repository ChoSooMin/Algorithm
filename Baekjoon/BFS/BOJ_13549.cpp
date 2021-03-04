//
//  BOJ_13549.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/04.
//  Copyright © 2021 조수민. All rights reserved.
//
//  숨바꼭질 3(https://www.acmicpc.net/problem/13549)

#include <stdio.h>
#include <iostream>
#include <queue>
#include <deque>

#define MAX 100001

using namespace std;

bool visit[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    deque<pair<int, int>> Q;
    Q.push_front({ N, 0 });
    
    
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop_front();
        int curN = cur.first;
        int curTime = cur.second;
        
        if (curN == K) {
            cout << cur.second << "\n";
            break;
        }
        
        for (int next : { curN + 1, curN - 1, 2 * curN }) {
            visit[next] = true;
            
            if (next == 2 * curN) {
                Q.push_front({ next, curTime });
            }
            else {
                Q.push_back({ next, curTime + 1 });
            }
        }
    }
    
    return 0;
}
