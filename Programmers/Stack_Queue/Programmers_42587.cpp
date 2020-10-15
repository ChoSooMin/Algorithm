//
//  Programmers_42587.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/14.
//  Copyright © 2020 조수민. All rights reserved.
//
//  프린터(https://programmers.co.kr/learn/courses/30/lessons/42587)

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    
    /**
     priorityQ에는 priorities의 값이 들어가고,
     indexQ에는 해당 인덱스들이 들어간다.
     */
    queue<int> priorityQ;
    queue<int> indexQ;
    
    while(true)
    {
        
    }
    
    return answer;
}

int main()
{
    vector<int> priorities1 = { 2, 1, 3, 2 };
    int location1 = 2;
    
    vector<int> priorities2 = { 1, 1, 9, 1, 1, 1 };
    int location2 = 0;
    
    cout << solution(priorities1, location1) << solution(priorities2, location2) << endl;
    
    return 0;
}
