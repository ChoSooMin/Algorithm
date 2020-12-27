//
//  Programmers_12912.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/27.
//  Copyright © 2020 조수민. All rights reserved.
//
//  두 정수 사이의 합(https://programmers.co.kr/learn/courses/30/lessons/12912)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if (a > b) {
        for (b; b <= a; b++) {
            answer += b;
        }
    }
    else {
        for (a; a <= b; a++) {
            answer += a;
        }
    }
    
    
    return answer;
}

int main() {
    cout << solution(3, 5) << endl;
    
    return 0;
}
