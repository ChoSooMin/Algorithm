//
//  BOJ_2169.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/05/18.
//  Copyright © 2020 조수민. All rights reserved.
//
//  로봇 조종하기(https://www.acmicpc.net/problem/2169)

#include <stdio.h>
#include <iostream>
#define MAX 1000 // 1 <= N, M <= 1000

using namespace std;

int n, m;
int mars[MAX][MAX];
int dp[MAX][MAX];
int dx[3] = { 0, 0, 1 }; // (왼쪽, 오른쪽, 아래쪽)
int dy[3] = { -1, 1, 0 }; // (왼쪽, 오른쪽, 아래쪽)

void input()
{
    cin >> n >> m;
    
    for (int i = 0; i <=n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                mars[i][j] = 0;
            else
                cin >> mars[i][j];
        }
}

int dynamic_programming(int x, int y, int now_answer)
{
    // 오른족 아래(n, m)에 도착하면 (n, m)위치의 값을 더해 그 값을 return 한다.
    if (x == n && y == m)
        return now_answer + mars[x][y];
    
    for (int i = 0; i < 3; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // 범위를 벗어나면 아래 구문을 수행하지 않고 다음번으로 넘어간다.
        if (next_x <= 0 || next_x > n || next_y <= 0 || next_y > m)
            continue;
        
        // 오른족 아래(n, m)에 도착하면 (n, m)위치의 값을 더해 그 값을 return 한다.
        if (next_x == n && next_y == m)
            return now_answer + mars[next_x][next_y];
        
        int next_dynamic = dynamic_programming(next_x, next_y, now_answer);
        now_answer = max(now_answer, next_dynamic);
    }
    
    return now_answer;
}

int max_answer()
{
    int now = mars[1][1];
    
    int answer = dynamic_programming(1, 1, now);
    
    return answer;
}

int main()
{
    input();
    
    cout << max_answer() << endl;
    
    return 0;
}
