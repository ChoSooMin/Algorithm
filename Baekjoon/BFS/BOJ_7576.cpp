//
//  BOJ_7576.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/21.
//  Copyright © 2020 조수민. All rights reserved.
//
//  토마토(https://www.acmicpc.net/problem/7576)

#include <stdio.h>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int n, m;
int board[1002][1002]; // 토마토 정보 배열
int dist[1002][1002]; // 해당 위치의 토마토가 익으려면 얼마간의 시간이 필요한지 저장하는 배열
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Q;

void input()
{
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
}

void BFS()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1) // 익은 토마토가 있는 곳
                Q.push({ i, j });
            
            if (board[i][j] == 0) // 익지 않은 토마토가 있는 곳
                dist[i][j] = -1;
        }
    
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위를 벗어날 경우
                continue;
            if (dist[nx][ny] >= 0) // 이미 접근한 곳이거나 토마토가 없는 곳
                continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx, ny });
        }
    }
}

int main()
{
    input();
    BFS();
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            
            ans = max(ans, dist[i][j]);
        }
    
    cout << ans;
    
    return 0;
}
