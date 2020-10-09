//
//  Programmers_42586.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/09.
//  Copyright © 2020 조수민. All rights reserved.
//
//  기능개발(https://programmers.co.kr/learn/courses/30/lessons/42586)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    
    vector<int> time; // 각 작업이 끝나는 시간을 저장한 벡터
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int multi = remain / speeds[i];
        
        if (remain % speeds[i] != 0)
            multi += 1;
        
        time.push_back(multi);
    }
    
    int max = time[0];
    int count = 1;
    for (int i = 0; i < time.size(); i++)
    {
        if (time[i] > max)
        {
            max = time[i];
            answer.push_back(count);
            count = 1;
            
            if (i == time.size() - 1)
                answer.push_back(count);
        }
        else if (i == time.size() - 1)
        {
            answer.push_back(count);
        }
        else
        {
            count++;
        }
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
    
//    vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
//    vector<int> speeds2 = { 1, 1, 1, 1, 1, 1 };
//
//    vector<int> s2 = solution(progresses2, speeds2);
//
//    for (int elem : s2)
//        cout << elem << " " << endl;
    
    return 0;
}
