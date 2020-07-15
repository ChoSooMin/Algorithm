//
//  BOJ_10709.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/07/14.
//  Copyright © 2020 조수민. All rights reserved.
//
//  기상캐스터(https://www.acmicpc.net/problem/10709)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> JOI;
vector<vector<int>> cloud;

void input()
{
    int H, W;
    
    // input H, W
    cin >> H >> W;
    
    // resizing vector
    JOI.resize(H);
    cloud.resize(H);
    for (int i = 0; i < H; i++)
    {
        JOI[i].resize(W);
        cloud[i].resize(W);
        cloud[i].assign(cloud[i].size(), -1); // cloud 벡터를 -1로 초기화
    }
    
    // input JOI vector
    for (int i = 0; i < JOI.size(); i++)
        for (int j = 0; j < JOI[i].size(); j++)
            cin >> JOI[i][j];
}

void getCloudTime()
{
    for (int i = 0; i < JOI.size(); i++)
        for (int j = 0; j < JOI[i].size(); j++)
        {
            if (JOI[i][j] == 'c') // JOI[i][j]가 c라면
                cloud[i][j] = 0; // cloud[i][j]를 0으로 바꾼다.
            else if (j >= 1 && (cloud[i][j - 1] >= 0)) // cloud[i][j - 1]이 0보다 크거나 같으면
                cloud[i][j] = cloud[i][j - 1] + 1; // cloud[i][j]를 그 전 값에 +1한다.
        }
}

void output()
{
    for (int i = 0; i < cloud.size(); i++)
    {
        for (int j = 0; j < cloud[i].size(); j++)
            cout << cloud[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    input(); // input
    
    getCloudTime(); // cloud vector 구하기
    
    output(); // output
    
    return 0;
}
