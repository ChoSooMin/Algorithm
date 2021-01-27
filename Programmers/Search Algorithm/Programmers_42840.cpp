//
//  Programmers_42840.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  모의고사(https://programmers.co.kr/learn/courses/30/lessons/42840)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int p1[5] = { 1, 2, 3, 4, 5 };
int p2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int p3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

/**
 각 수포자가 찍는 방식을 int형 배열에 각각 저장해두고,
 answers 인덱스를 각 수포자의 배열 크기로 나눠 나머지로 몇번째에 있는지 판별,,?
 */
bool isCorrect(int ansNum, int ansIndex, int personNum) {
    bool correct = false;
    
    switch (personNum) {
        case 1:
        {
            int index = ansIndex % 5;
            
            if (ansNum == p1[index])
                correct = true;
            break;
        }
        case 2:
        {
            int index = ansIndex % 8;
            
            if (ansNum == p2[index])
                correct = true;
            break;
        }
        case 3:
        {
            int index = ansIndex % 10;
            
            if (ansNum == p3[index])
                correct = true;
            break;
        }
        default:
            break;
    }
    
    return correct;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int p1CorrectCount = 0;
    int p2CorrectCount = 0;
    int p3CorrectCount = 0;
    
    for (int i = 0; i < answers.size(); i++) {
        int correct1 = isCorrect(answers.at(i), i, 1);
        int correct2 = isCorrect(answers.at(i), i, 2);
        int correct3 = isCorrect(answers.at(i), i, 3);
        
        if (correct1 == true)
            p1CorrectCount++;
        if (correct2 == true)
            p2CorrectCount++;
        if (correct3 == true)
            p3CorrectCount++;
    }
    
    vector<pair<int, int>> personalCorrectCount;
    personalCorrectCount.push_back(make_pair(p2CorrectCount, 2));
    personalCorrectCount.push_back(make_pair(p3CorrectCount, 3));
    personalCorrectCount.push_back(make_pair(p1CorrectCount, 1));
    
    sort(personalCorrectCount.begin(), personalCorrectCount.end(), greater<>()); // 내림차순 정렬
    
    int maxCount = personalCorrectCount.at(0).first;
    answer.push_back(personalCorrectCount.at(0).second);
    
    for (int i = 1; i < personalCorrectCount.size(); i++) {
        if (personalCorrectCount.at(i).first == maxCount) {
            answer.push_back(personalCorrectCount.at(i).second);
        }
    }
    
    sort(answer.begin(), answer.end(), less<>());
    
    return answer;
}

int main() {
    vector<int> ss = solution({ 1, 3, 2, 4, 2 });
    
    for (int i = 0; i < ss.size(); i++) {
        cout << ss.at(i) << " ";
    }
    return 0;
}
