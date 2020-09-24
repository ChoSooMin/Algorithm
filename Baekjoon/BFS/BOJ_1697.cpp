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

#define MAX 100000

using namespace std;

int n, k;
queue<int> Q;

void input()
{
    cin >> n >> k;
}

int main()
{
    input();
    
    Q.push(n);

    int time = 0;
    
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        
        if (cur == k)
        {
            cout << time;
            return 0;
        }
        
        else
        {
            if (cur + 1 > MAX || cur - 1 < 0 || 2 * cur > MAX)
                continue;
            
            
            Q.push(cur + 1);
            Q.push(cur - 1);
            Q.push(2 * cur);
        }
    }
    
    return 0;
}
