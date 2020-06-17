//
//  BOJ_1057.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/06/17.
//  Copyright © 2020 조수민. All rights reserved.
//
//  토너먼트(https://www.acmicpc.net/problem/1057)

#include <stdio.h>
#include <iostream>

using namespace std;

int N, x, y;

int getRoundNum()
{
    int roundNum = 0;
    
    while (N != 1)
    {
        if (N % 2 == 0) // N이 짝수일 때
        {
            N = N / 2;
        }
        else // N이 홀수일 때
        {
            N = (N + 1) / 2;
        }
        roundNum++;
    }
    
    return roundNum;
}

int main()
{
    // input
    cin >> N >> x >> y;
    cout << getRoundNum() << endl;
    
    return 0;
}
