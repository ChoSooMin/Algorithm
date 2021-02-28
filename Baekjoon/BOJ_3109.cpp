//
//  BOJ_3109.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/28.
//  Copyright © 2021 조수민. All rights reserved.
//
//  빵집(https://www.acmicpc.net/problem/3109)

#include <stdio.h>
#include <iostream>

using namespace std;

// 오른쪽 : (0, 1), 오른쪽 위 : (-1, 1), 오른쪽 아래 : (1, 1)
int R, C, answer;
int dx[3] = { -1, 0, 1 };
char map[10000][500]; // 지도
int visit[10000][500]; // 0이면 파이프라인이 없는 곳, 1이면 있는 곳
bool ans;

void DFS(int x, int y) {
    visit[x][y] = 1; // 파이프라인 놓았다고 표시
    
    if (y == C - 1) { // 파이프라인을 끝까지 놓았음
        ans = true;
        answer++;
        return;
    }
    
    for (int dir = 0; dir < 3; dir++) {
        int nextX = x + dx[dir];
        int nextY = y + 1; // 모두 오른쪽으로 이동하는 것이므로, 무조건 + 1
        
        if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C)
            continue;
        
        if (map[nextX][nextY] == '.' && visit[nextX][nextY] == 0) { // 건물이 없는 곳이고, 파이프라인을 놓을 수 있는 곳이라면
            DFS(nextX, nextY);
            
            if (ans == true)
                return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < R; i++) {
        ans = false;
        DFS(i, 0);
    }
    
    cout << answer << "\n";
    
    return 0;
}
