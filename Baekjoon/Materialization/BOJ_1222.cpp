//
//  BOJ_1222.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/07/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  홍준 프로그래밍 대회(https://www.acmicpc.net/problem/1222)

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2000000

int N; // 대회에 참가하는 학교의 수
long long schoolArray[MAX + 1];

void input()
{
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        schoolArray[number]++;
    }
}

long getMaxNum()
{
    long maxNum = 0;
    
    for (int i = 1; i <= MAX; i++)
    {
        int count = 0; // 참가하는 학교의 수
        
        /**
         schoolArray[i] + schoolArray[2 * i] + schoolArray[3 * i] + ... 를 구할 수 있다.
         즉, i를 약수로 갖는 값들이 몇 개인지 알 수 있다.
         */
        for (int j = i; j <= MAX; j += i)
            count += schoolArray[j];
        
        if (count < 2) // 본선에는 적어도 2팀이 참가해야 한다.
            continue;
        
        maxNum = max(maxNum, (long)count * (long) i); // 학생수 = 각 팀을 구성하는 학생 수 * 대회 참여가 가능한 학교 수
    }
    
    return maxNum;
}

int main()
{
    input();
    
    cout << getMaxNum() << endl;
    
    return 0;
}
