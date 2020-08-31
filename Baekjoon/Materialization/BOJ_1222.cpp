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
// 이 문제는 벡터로 풀면 메모리가 터진다..!

void input()
{
    
    cin >> N;
    studentNumber.resize(N);
    
    for (int i = 0; i < N; i++)
        cin >> studentNumber[i];
}

int getMaxNum()
{
    int max = 0; // 본선에 참가할 수 있는 사람의 수의 최댓값
    
    // 벡터를 두 번 접근 -> 시간복잡도가 n의 제곱근 -> timeout이 난다.
    for (int i = 0; i < studentNumber.size(); i++)
    {
        int schoolNum = 0;
        int currentNum = studentNumber[i]; // 홍준이가 정한 팀원의 수
        
        // 벡터를 다시 접근하여 currentNum으로 나누어 떨어지는 학교의 수가 몇인지 센다.
        for (int j = 0; j < studentNumber.size(); j++)
        {
            if (studentNumber[j] % currentNum == 0)
                schoolNum += 1;
        }
        
        // 학교의 수가 1이라면 continue로 건너뛴다. (적어도 두 팀이 본선에 참가해야 하기 때문)
        if (schoolNum == 1)
            continue;
        
        int current = schoolNum * currentNum; // current는 currentNum이 studentNumber[i]일 때, 본선에 참가하는 사람의 수이다.
        
        if (max < current) // max보다 current값이 크다면
            max = current; // max를 current값으로 바꿔준다.
    }
    
    return max;
}

int main()
{
    input();
    
    cout << getMaxNum() << endl;
    
    return 0;
}
