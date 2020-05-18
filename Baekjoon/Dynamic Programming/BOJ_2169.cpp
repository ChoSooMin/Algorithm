//
//  BOJ_2169.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/05/18.
//  Copyright © 2020 조수민. All rights reserved.
//
//  로봇 조종하기(https://www.acmicpc.net/problem/2169)

#include <iostream>
#define MAX 1001 // 1 <= N, M <= 1000

using namespace std;

int n, m;
int mars[MAX][MAX] = { 0 };
int dp[MAX][MAX] = { 0 }; // (1, 1)에서부터 (i, j)까지 이동했을 때 합이 최대가 되는 값들을 저장
int leftRightCompare[2][MAX] = { 0 };

void input()
{
    cin >> n >> m; // n,m 입력받기
    
    // mars[i][j]를 입력받는다.
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mars[i][j];
    
    // (1, 1)에서 시작하므로 (1, 1)은 꼭 들어가야 하는 값
    dp[1][1] = mars[1][1]; // dp[1][1]은 mars[1][1]과 같은 값으로 초기화해둔다.
}

int getMax()
{
    // i = 1일 때
    for (int j = 2; j <= m; j++)
        dp[1][j] = mars[1][j] + dp[1][j - 1]; // += 안해줘도 되나?
    
    // i = 2~n일 때
    // leftRightCompare[0][j]는 왼쪽 -> 오른쪽으로 이동했을 때
    // leftRightCompare[1][j]는 오른쪽 -> 왼쪽으로 이동할 때
    for (int i = 2; i <= n; i++)
    {
        leftRightCompare[0][0] = dp[i - 1][1]; // ?
        
        for (int j = 1; j <= m; j++)
            leftRightCompare[0][j] = max(leftRightCompare[0][j - 1], dp[i - 1][j] + mars[i][j]);
        
        leftRightCompare[1][m + 1] = dp[i - 1][m];
        
        for (int j = m; j >= 1; j--)
            leftRightCompare[1][j] = max(leftRightCompare[1][j + 1], dp[i - 1][j] + mars[i][j]);
        
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(leftRightCompare[0][j], leftRightCompare[1][j]);
        
    }
        
    
    return dp[n][m];
}

int main()
{
    input();
    
    cout << getMax() << endl;
    
    return 0;
}

