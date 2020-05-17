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
int dp[MAX][MAX]; // dp 저장공간..

// 대나무 숲 입력받기
void input()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1; // dp를 1로 초기화해둔다.
            cin >> forest[i][j];
        }
}

int get_day(int x, int y)
{
    int &day = dp[x][y];
    
    if (day != 1)
        return day;
    
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // next_x와 next_y가 범위를 벗어난다면 continue문 수행
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
            continue;
        
        // 다음 위치의 대나무 양이 현재 위치의 대나무 양보다 클 떄만 다음을 수행한다.
        if (forest[next_x][next_y] > forest[x][y])
        {
            // 메모이제이션 사용!
            int next_dynamic = get_day(next_x, next_y) + 1; // 다음으로 이동해서 그 자리에서 또 get_day를 한다.
            day = max(day, next_dynamic); // day와 next_dynamic 중 더 큰 값을 day에 넣어준다.
        }
    }
    
    return day;
}

int get_answer()
{
    int answer = 0;
    
    // 각각의 위치에서 dynamic_programming을 다 해본다.
    // 그 중 제일 큰 값이 답
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            answer = max(answer, get_day(i, j)); // 매번 answer와 (i, j) 위치에서의 dynamic_programming 값을 비교하여 더 큰 값을 answer로 바꿔준다.
    
    return answer;
}

int main()
{
    input();
    
    cout << get_answer() << endl;
    
    return 0;
}
