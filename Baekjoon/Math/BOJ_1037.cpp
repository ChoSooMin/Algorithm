//
//  BOJ_1037.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/05/29.
//  Copyright © 2020 조수민. All rights reserved.
//
//  약수(https://www.acmicpc.net/problem/1037)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> aliquot;

int getNumber()
{
    if (aliquot.size() % 2 == 0) // 진짜 약수의 개수가 짝수일 때
    {
        int num1Index = aliquot.size() / 2 - 1;
        int num2Index = num1Index + 1;
        int num1 = aliquot[num1Index];
        int num2 = aliquot[num2Index];
        
        return num1 * num2;
    }
    else // 진짜 약수의 개수가 홀수일 때
    {
        int mediumIndex = aliquot.size() / 2;
        int squareNum = aliquot[mediumIndex];
        
        return squareNum * squareNum;
    }
}


int main(void)
{
    // 입력 받기
    cin >> n;
    aliquot.resize(n);
    
    for (int i = 0; i < aliquot.size(); i++)
        cin >> aliquot[i];
    // 입력 받기 끝
    // 벡터 정렬
    sort(aliquot.begin(), aliquot.end());

    // 출력
    cout << getNumber() << endl;
    
    return 0;
}
