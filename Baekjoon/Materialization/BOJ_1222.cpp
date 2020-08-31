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
#include <vector>

using namespace std;

int N; // 대회에 참가하는 학교의 수
vector<int> studentNumber; // 각 학교의 학생 수 벡터

void input()
{
    
    cin >> N;
    studentNumber.resize(N);
    
    for (int i = 0; i < N; i++)
        cin >> studentNumber[i];
}

int getMaxNum()
{
    int max = 0;
    
    for (int i = 0; i < studentNumber.size(); i++)
    {
        int schoolNum = 0;
        int currentNum = studentNumber[i];
        
        for (int j = 0; j < studentNumber.size(); j++)
        {
            if (studentNumber[j] % currentNum == 0)
            {
                schoolNum += 1;
            }
        }
        
        if (schoolNum == 1)
            continue;
        
        int current = schoolNum * currentNum;
        
        if (max < current)
            max = current;
    }
    
    return max;
}

int main()
{
    input();
    
    cout << getMaxNum() << endl;
    
    return 0;
}
