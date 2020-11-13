//
//  Programmers_42883.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/12.
//  Copyright © 2020 조수민. All rights reserved.
//
//  큰 수 만들기(https://programmers.co.kr/learn/courses/30/lessons/42883)

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int start = 0, maxIndex = 0;
    char maxNum = NULL;
    
    /**
     num : 4 1 7 7 2 5 || 2 8 4 1
     ind : 0 1 2 3 4 5 || 6 7 8 9
     ind1: 1 2 3 4 5 6 || 7 8 9 10
     number.size() - k = 6 (6개 선택할 수 있다.)
     */
    for (int i = 0; i < number.size() - k; i++) {
        maxNum = number[start];
        maxIndex = start;
        
        for (int j = start; j <= i + k; j++) {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIndex = j;
            }
        }
        
        start = maxIndex + 1;
        answer += maxNum;
    }
    
    return answer;
}

int main() {
    cout << solution("4177252841", 4) << endl;
    
    return 0;
}
