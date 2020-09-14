//
//  BOJ_1926.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/14.
//  Copyright © 2020 조수민. All rights reserved.
//
//  그림(https://www.acmicpc.net/problem/1926)

#include <stdio.h>
#include <iostream>
#include <queue>

#define X first
#define Y second // pair에서 first, second를 줄여 쓰기 위해 사용

using namespace std;

int board[502][502]; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n, m;
// 상하좌우 네 방향
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1 };

void input()
{
    cin >> n >> m; // n과 m을 입력받는다.
    
    // 칸을 입력받는다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
}

void getAnswer()
{
    int mx = 0; // 그림의 최댓값
    int num = 0; // 그림의 개수
    
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) // (i, j)를 시작점으로 한다.
        {
            if (board[i][j] == 0 or vis[i][j]) // 해당 칸이 색칠이 안된 부분이거나 이미 방문한 곳이라면 넘어간다.
                continue;
            // (i, j)는 새로운 그림에 속해있는 시작점이 된다.
            num++; // 그림의 수 1 증가
            
            queue<pair<int, int>> Q; // 큐를 사용해 BFS를 구현한다.
            vis[i][j] = 1; // (i, j)로 BFS를 시작하기 위한 준비
            Q.push({i, j}); // 큐에 넣는다.
            
            int area = 0; // 그림의 넓이
            while(!Q.empty()) // Q가 비어있지 않은 동안
            {
                area++; // 큐에 들어있는 원소를 하나 뺄 때마다 넓이를 1 증가시킨다.
                auto cur = Q.front(); // 큐에서 가장 앞에 있는 원소를 가져온다.
                Q.pop(); // 큐에서 원소를 하나 뺀다.
                
                for(int dir = 0; dir < 4; dir++) // 상하좌우 칸을 살핀다.
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) // 범위 밖일 경우 넘어간다.
                        continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1) // 이미 방문한 칸이거나 파란 칸이 아닐 경우 넘어간다.
                        continue;
                    
                    vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                    Q.push({ nx, ny });
                }
            }
            
            // (i, j)를 시작점으로 하는 BFS가 종료되었다.
            mx = max(mx, area); // area가 mx보다 클 경우 mx에 area를 대입한다.
        }
    
    cout << num << endl << mx;
}

int main()
{
    input();
    
    getAnswer();
    
    return 0;
}
