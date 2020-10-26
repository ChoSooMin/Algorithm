//
//  Programmers_42840_using_max_element().cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  모의고사(https://programmers.co.kr/learn/courses/30/lessons/42840)

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = { 1, 2, 3, 4, 5 };
vector<int> two = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> thr = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correctCount(3);
    
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == one[i % one.size()])
            correctCount[0]++;
        if(answers[i] == two[i % two.size()])
            correctCount[1]++;
        if(answers[i] == thr[i % thr.size()])
            correctCount[2]++;
    }
    
    int they_max = *max_element(correctCount.begin(),correctCount.end());
    
    for(int i = 0; i < 3; i++) {
        if(correctCount[i] == they_max)
            answer.push_back(i + 1);
    }
    return answer;
}
