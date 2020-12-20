//
//  Programmers_12901_another_solution.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/20.
//  Copyright © 2020 조수민. All rights reserved.
//
//  2016년(https://programmers.co.kr/learn/courses/30/lessons/12901)

#include <stdio.h>
#include <string>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int month[12] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
    string date[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    
    for (int i = 1; i < a; i++) {
        b += month[i];
    }
    
    answer = date[(b + 4) % 7]; // 1월 1일이 금요일이므로 +4를 한 후, 7로 나눠줘야 한다.
    
    return answer;
}
