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

#define MAX 100001

using namespace std;

bool visit[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({ 0, N });
    visit[N] = true;
    
    while (!Q.empty()) {
        int curTime = Q.top().first;
        int curLoc = Q.top().second;
        Q.pop();
        
        if (curLoc == K) {
            cout << curTime << "\n";
            break;
        }
        
        for (int next : { curLoc + 1, curLoc - 1, 2 * curLoc }) {
            if (0 <= next && next < MAX && visit[next] == false) {
                visit[next] = true;
                
                if (next == 2 * curLoc) {
                    Q.push({ curTime, next });
                }
                else {
                    Q.push({ curTime + 1, next });
                }
            }
        }
    }
    
    return 0;
}
