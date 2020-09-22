//
//  BOJ_4179.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/21.
//  Copyright © 2020 조수민. All rights reserved.
//
//  불!(https://www.acmicpc.net/problem/4179)

#include <stdio.h>
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int r, c;
string board[1002];
int fireDist[1002][1002];
int jDist[1002][1002];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> Qfire;
queue<pair<int, int>> Qj;

void input()
{
    cin >> r >> c;
    
    for (int i = 0; i < r; i++)
        cin >> board[i];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            fireDist[i][j] = -1;
            jDist[i][j] = -1;
        }
}

void fireBFS()
{
    while(!Qfire.empty())
    {
        auto cur = Qfire.front();
        Qfire.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (board[nx][ny] == '#' || fireDist[nx][ny] >= 0) // 벽이거나 이미 방문한 곳이라면
                continue;
            
            fireDist[nx][ny] = fireDist[cur.X][cur.Y] + 1;
            Qfire.push({ nx, ny });
        }
    }
}

int jBFS()
{
    while(!Qj.empty())
    {
        auto cur = Qj.front();
        Qj.pop();
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) // 범위를 벗어남 = 탈출에 성공했다.
            {
                cout << jDist[cur.X][cur.Y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || jDist[nx][ny] >= 0) // 벽이거나 이미 방문한 곳이라면
                continue;
            if (fireDist[nx][ny] != -1 && (fireDist[nx][ny] <= jDist[cur.X][cur.Y] + 1)) // 불의 전파시간을 조건에 추가
                continue;
            
            jDist[nx][ny] = jDist[cur.X][cur.Y] + 1;
            Qj.push({ nx, ny });
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}


int main()
{
    input();
    
    // 각 큐에 시작점을 넣는다.
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'F')
            {
                Qfire.push({ i, j });
                fireDist[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                Qj.push({ i, j });
                jDist[i][j] = 0;
            }
        }
    
    fireBFS();
    jBFS();
    
    return 0;
}
