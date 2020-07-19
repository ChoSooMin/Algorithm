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
vector<string> daegeun; // 대근이가 적은 차량 번호 목록
vector<string> yeongsik; // 영식이가 적은 차량 번호 목록

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

int getOvertakeCar()
{
    int overtakeCar = 0;
    
    /**
     daegeun 벡터와 yeongsik 벡터의 값들의 순서를 비교해서 순서가 다른 차가 몇 개인지 구하면 되지 않을까?
     ex)
     daegeun = [ A, B, C, D ]
     yeongsik = [ B, C, D, A ] 일 때
     daegeun = [ 1, 2, 3, 4 ]
     yeongsik = [ 2, 3, 4, 1 ] 로 바꿔서 .. 비교..?
     */
    
    return overtakeCar;
}

int main()
{
    input();

    cout << getOvertakeCar() << endl; // output
    
    return 0;
}
