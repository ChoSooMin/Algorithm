//
//  Programmers_42626.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/16.
//  Copyright © 2020 조수민. All rights reserved.
//
//  더 맵게(https://programmers.co.kr/learn/courses/30/lessons/42626)

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    
    /**
     priority_queue를 사용한다. 오름차순으로 해야함
     */
    priority_queue<int, vector<int>, greater<int>> scovilleNum;
    
    // scoville 벡터에 있는 값들을 우선순위 큐에 넣는다.
    for (int i = 0; i < scoville.size(); i++)
    {
        scovilleNum.push(scoville.at(i));
    }
    
    while (scovilleNum.top() <= K)
    {
        if (scovilleNum.size() >= 2)
        {
            int one = scovilleNum.top(); scovilleNum.pop();
            int two = scovilleNum.top(); scovilleNum.pop();
            
            int newScoville = one + 2 * two;
            scovilleNum.push(newScoville); // 생성한 새로운 스코빌 지수를 넣는다
            
            answer++;
        }
        
        if (scovilleNum.size() == 1 && scovilleNum.top() <= K)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}

int main()
{
    vector<int> scoville = { 12, 10, 9, 3, 2, 1 };
    cout << solution(scoville, 7) << endl;
    
    return 0;
}
