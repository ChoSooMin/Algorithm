//
//  BOJ_1058.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/07.
//  Copyright © 2020 조수민. All rights reserved.
//
//  친구(https://www.acmicpc.net/problem/1058)

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 51;

int N;
int friendsList[MAX][MAX];

void floyd()
{
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (i == j || j == k || i == k) // 자기 자신일 경우 다음으로 넘어간다.
                    continue;
                else if (friendsList[i][j] > friendsList[i][k] + friendsList[k][j]) // 
                    friendsList[i][j] = friendsList[i][k] + friendsList[k][j];
            }
}

int main()
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string temp;
        cin >> temp;
        
        for (int j = 0; j < temp.size(); j++)
        {
            if (i == j)
                friendsList[i][j] = 0;
            else
                friendsList[i][j] = temp[j] == 'Y' ? 1 : INF;
        }
    }
    
    floyd();
    
    int result = 0;
    
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            else if (friendsList[i][j] <= 2)
                cnt++;
        }
        
        result = max(result, cnt);
    }
    
    cout << result << endl;
    
    return 0;
}
