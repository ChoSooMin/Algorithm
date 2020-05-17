//
//  BOJ_1937.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/05/17.
//  Copyright © 2020 조수민. All rights reserved.
//
//  욕심쟁이 판다(https://www.acmicpc.net/problem/1937)

#include <iostream>
#include <vector>
#define MAX 500 // 대나무 숲 크기는 최대 500
#define BAMBOO 1000000 // 대나무 양은 최대 1,000,000

using namespace std;

int n; // 대나무 숲 크기
int forest[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dy[4] = { 0, 0, -1, 1}; // 상, 하, 좌, 우
//int min_num, min_x, min_y;
//int min_x = 0, min_y = 0;

// 대나무 숲 입력받기
void input()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
        }
}

int dp(int x, int y)
{
    int answer = 1; // 1일부터 시작
    int next_x = -1;
    int next_y = -1;
    int min = BAMBOO + 1;
    int min_x = -1, min_y = -1;
    
    // (상, 하, 좌, 우)에서 현재 대나무 양보다 크고, 제일 적은 곳으로..? 이동할 곳을 찾는다.
    for (int i = 0; i < 4; i++)
    {
        // (상, 하, 좌, 우)로 이동할 좌표 구하기
        next_x = x + dx[i];
        next_y = y + dy[i];
        
        // 1. 이동할 좌표가 범위를 벗어나거나
        // 2. 현재 좌표의 대나무 양보다 이동할 좌표의 대나무 양이 작으면
        // 다음으로 넘어간다.
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || (forest[next_x][next_y] < forest[x][y]))
            continue;
        
        if (min > forest[next_x][next_y])
        {
            min = forest[next_x][next_y];
            min_x = next_x;
            min_y = next_y;
        }
    }
    
    // 끝났을 때 min_x랑 min_y가 -1이라면 이동할 곳이 없다는 것 ..
    if (min_x == -1 && min_y == -1)
    {
        int nextnext_x = -1, nextnext_y = -1;
        
        if (x == 3 && y == 3)
        {
            cout << "모르게따";
        }
        else if (y == 3)
        {
            nextnext_x = x + 1;
            nextnext_y = 0;
        }
        else
        {
            nextnext_x = x + 1;
            nextnext_y = y + 1;
        }
        dp(nextnext_x, nextnext_y);
    }
    else
    {
        answer++;
        dp(min_x, min_y);
    }
    
    
    return answer;
}

int get_answer()
{
    int answer = 0;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, dp(i, j));
    
    return answer;
}

int main()
{
    input();
    
    cout << get_answer() << endl;
    
    return 0;
}
