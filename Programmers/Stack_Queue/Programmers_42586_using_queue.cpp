//
//  Programmers_42586_using_queue.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/10.
//  Copyright © 2020 조수민. All rights reserved.
//  기능개발(https://programmers.co.kr/learn/courses/30/lessons/42586)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 내가 작성한 코드는 큐를 사용하지 않고, 벡터를 사용해 하나하나 다 비교하기 때문에
 if문이 너무 많다,, 게다가 매번 확인하면서 if문을 사용해 억지로 끼워맞춘 것이기 때문에
 이 코드가 더 정확한 것 같다,,
 */
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    queue<int> time; // 각 작업이 끝나는 시간을 저장한 큐!! 큐 사용
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int multi = remain / speeds[i];
        
        if (remain % speeds[i] != 0)
            multi += 1;
        
        time.push(multi);
    }
    
    while (!time.empty())
    {
        int count = 1;
        int current = time.front();
        time.pop();
        
        // 현재 값이 뒤의 값보다 크고 큐가 비어있지 않을 때(뒤에 하나라도 더 있을 때)
        while (current >= time.front() && !time.empty())
        {
            time.pop(); // 뒤의 값을 빼고
            count++; // count에 1을 더해준다.
        }
        
        answer.push_back(count);
    }
    
    return answer;
}

int main()
{
    vector<int> progresses1 = { 93, 30, 55 };
    vector<int> speeds1 = { 1, 30, 5 };
    
    vector<int> s1 = solution(progresses1, speeds1);
    
    for (int elem : s1)
        cout << elem << " " << endl;
    
    cout << endl;
    
    vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds2 = { 1, 1, 1, 1, 1, 1 };

    vector<int> s2 = solution(progresses2, speeds2);

    for (int elem : s2)
        cout << elem << " " << endl;
    
    return 0;
}
