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
    int round = 1;
    
    while (1)
    {
        // 인접해있고, 더 작은 숫자를 2로 나눈 나머지가 1일 때 break
        if (x > y && (x == y + 1) && (y % 2 == 1))
        {
            break;
        }
        else if (y > x && (y == x + 1) && (x % 2 == 1))
        {
            break;
        }
        
        // 다음 라운드로 진행될 때마다 현재 index의 /2 값으로 바뀐다..
        if (x % 2 == 0)
            x = x / 2;
        else
            x = (x + 1) / 2;

        if (y % 2 == 0)
            y = y / 2;
        else
            y = (y + 1) / 2;
        
        // round + 1 해준다.
        round += 1;
    }
    
    return round;
}

int main()
{
    // input
    cin >> N;
    cin >> x >> y;
    
    // output
    cout << getRoundNum() << endl;
    
    return 0;
}
