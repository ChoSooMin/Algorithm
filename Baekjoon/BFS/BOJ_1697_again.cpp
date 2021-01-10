//
//  BOJ_1697_again.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  숨바꼭질(https://www.acmicpc.net/problem/1697https://www.acmicpc.net/problem/1697)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int dist[100001];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    fill_n(dist, 100001, -1); // dist를 -1로 초기화
    
    Q.push(N);
    dist[N] = 0;
    
    while (dist[K] == -1) {
        int curPos = Q.front(); Q.pop();
        
        for (int next : {curPos - 1, curPos + 1, 2 * curPos}) { // for문!!
            if (next < 0 || next > 100000) // 0보다 작거나 100000보다 크면 갈 필요가 없다(가봤자 비효율적인 경우의 수만 나온다. 계속해서 -1을 할 것이기 때문에)
                continue;
            
            // 이미 방문한 곳이라면 다음으로 넘어간다.
            if (dist[next] != -1)
                continue;
            
            dist[next] = dist[curPos] + 1;
            Q.push(next);
        }
    }
    
    cout << dist[K];
    
    return 0;
}
