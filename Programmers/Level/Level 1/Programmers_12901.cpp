//
//  Programmers_12901.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/20.
//  Copyright © 2020 조수민. All rights reserved.
//
//  2016년(https://programmers.co.kr/learn/courses/30/lessons/12901)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<int> monthDays = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int days = 0;
    for (int i = 1; i < a; i++) {
        days += monthDays.at(i);
    }
    days += b;
    days -= 1;
    
    int r = days % 7;
    
    switch (r) {
        case 0:
            answer = "FRI";
            break;
        case 1:
            answer = "SAT";
            break;
        case 2:
            answer = "SUN";
            break;
        case 3:
            answer = "MON";
            break;
        case 4:
            answer = "TUE";
            break;
        case 5:
            answer = "WED";
            break;
        case 6:
            answer = "THU";
            break;
        default:
            break;
    }
    
    return answer;
}

int main() {
    cout << solution(5, 24) << endl;
    
    return 0;
}
