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
     queue<pair<int, int>>를 만들어 (인덱스, 우선순위값) 짝을 갖는 큐를 만든다.
     */
    queue<pair<int, int>> pairQ;
    priority_queue<int> priorityQ;
    
    for (int i = 0; i < priorities.size(); i++)
    {
        pairQ.push(make_pair(i, priorities[i]));
        priorityQ.push(priorities[i]); // 이 큐에는 우선순위가 순서대로 있을 것ㅅ
    }
    
    while (!pairQ.empty())
    {
        int currentIndex = pairQ.front().first;
        int currentPriority = pairQ.front().second;
        pairQ.pop();
        
        // 현재 문서의 중요도가 가장 높은 중요도라면 인쇄
        if (currentPriority == priorityQ.top())
        {
            priorityQ.pop();
            answer += 1;
            
            // 현재 문서가 내가 인쇄를 요청한 문서이면 멈춘다
            if (currentIndex == location)
                break;
        }
        else // 아니라면 큐에 다시 넣는다
            pairQ.push(make_pair(currentIndex, currentPriority));
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
