//
//  Programmers_12947.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/05.
//  Copyright © 2021 조수민. All rights reserved.
//
//  하샤드 수(https://programmers.co.kr/learn/courses/30/lessons/12947)

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int sum = 0;
    string str = to_string(x);
    for (int i = 0; i < str.length(); i++) {
        sum += str[i] - '0';
    }
    
    if (x % sum != 0) {
        answer = false;
    }
    
    return answer;
}

int main() {
    cout << solution(10) << endl;
    
    return 0;
}
