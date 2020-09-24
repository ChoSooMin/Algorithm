//
//  BOJ_1697.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/24.
//  Copyright © 2020 조수민. All rights reserved.
//
//  숨바꼭질(https://www.acmicpc.net/problem/1697)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> Q;
int dist[100002]; // n번째에서 몇번만에 갈 수 있는지 저장하는 배열

void input()
{
    cin >> n >> k;
    
    fill(dist, dist + 100001, -1);
    dist[n] = 0;
}

void getBFS()
{
    Q.push(n);
    
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        
        
        for (int next : { cur - 1, cur + 1, 2 * cur }) // 이렇게 for문을 돌리면 next에는 각각 cur - 1, cur + 1, 2 * cur이 차례대로 들어온다!
        {
            if (next < 0 || next > 100000)
                continue;
            
            if (dist[next] != -1)
                continue; // 이미 방문했던 곳
            
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    
    cout << dist[k];
}

int main()
{
    input();
    
    getBFS();
    
    return 0;
}
