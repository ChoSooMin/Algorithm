//
//  BOJ_2002.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/07/19.
//  Copyright © 2020 조수민. All rights reserved.
//
//  추월(https://www.acmicpc.net/problem/2002)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int N; // 차의 대수
vector<string> daegeun; // 대근이가 적은 차량 목록
vector<string> yeongsik; // 영식이가 적은 차량 목록
vector<string> overtakeCars; // 추월한 차량 목록

void input()
{
    // input
    cin >> N;
    daegeun.resize(N); // resizing vector
    yeongsik.resize(N); // resizing vector
    
    // input vector
    for (int i = 0; i < daegeun.size(); i++)
        cin >> daegeun[i];
    for (int i = 0; i < yeongsik.size(); i++)
        cin >> yeongsik[i];
}

bool isInOvertakeVector(string s, vector<string> &v)
{
    // 추월한 차량 목록에 있는 차인지 확인
    for (int i = 0; i < v.size(); i++)
        if (s == v[i])
            return true; // 목록에 있다면 true를
    
    return false; // 없다면 false를 반환한다.
}

int getOvertakesNumber()
{
    // daegeun 벡터와 yeongsik 벡터를 0부터 접근, 비교한다.
    int daegeunIndex = 0;
    int yeongsikIndex = 0;
    
    while (daegeunIndex < daegeun.size() && yeongsikIndex < yeongsik.size())
    {
        if (daegeun[daegeunIndex] == yeongsik[yeongsikIndex]) // 차량의 순서가 같으면 index를 1 증가시킨다.
        {
            daegeunIndex++;
            yeongsikIndex++;
        }
        else // 순서가 같지 않으면
        {
            if (isInOvertakeVector(daegeun[daegeunIndex], overtakeCars)) // daegeun 벡터의 daegeunIndex 위치에 있는 차가 overtakeCars에 들어있다면
                daegeunIndex++; // daegeunIndex를 1 증가시킨다.
            else // 아니라면
            {
                overtakeCars.push_back(yeongsik[yeongsikIndex]); // overtakeCars 벡터에 yeongsik 벡터의 yeongsikIndex 위치에 있는 차를 넣고
                yeongsikIndex++; // yeongsikIndex를 1 증가시킨다.
            }
        }
    }
    
    // daegeun 벡터와 yeongsik 벡터를 모두 돌았다면
    return (int)overtakeCars.size(); // overtakeCars 벡터의 size를 반환해주면 답이 된다.
}

int main()
{
    input();

    cout << getOvertakesNumber() << endl;
    
    return 0;
}
