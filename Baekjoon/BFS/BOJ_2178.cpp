//
//  BOJ_2178.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/14.
//  Copyright © 2020 조수민. All rights reserved.
//
//  미로 탐색(https://www.acmicpc.net/problem/2178)

#include <stdio.h>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

string board[102]; // 각각의 수들은 붙어서
int dist[102][102];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> board[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = -1;
}

int main()
{
    input();
    
    queue<pair<int, int>> Q; // 큐를 이용하여 BFS 구현
    Q.push({ 0, 0 }); // (0, 0)부터 시작한다.
    dist[0][0] = 0; // dist는 (0, 0)부터 (i, j)까지의 최단 거리를 가진 배열이므로 dist[0][0]은 0이다.
    
    while(!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위에 벗어나는 경우 넘어간다.
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1') // 이미 방문한 곳이거나 길이 없는 곳이면 넘어간다.
                continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 새로운 칸의 dist는 전 칸 + 1이다. (인접한 곳)
            Q.push({ nx, ny });
        }
    }
    
    cout << dist[n - 1][m - 1] + 1; // 거리+1이 정답
    
    return 0;
}
