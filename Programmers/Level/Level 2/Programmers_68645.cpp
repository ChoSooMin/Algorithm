//
//  Programmers_68645.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/04.
//  Copyright © 2021 조수민. All rights reserved.
//
//  삼각 달팽이(https://programmers.co.kr/learn/courses/30/lessons/68645)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer = { 0 };
    vector<int> isVisited;
    
    if (n == 1 || n == 2) {
        for (int i = 0; i < n; i++) {
            answer.push_back(i + 1);
        }
        
        return answer;
    }
    
    // answer의 사이즈는 n * (n + 1) / 2
    answer.resize(n * (n + 1) / 2);
    
    for (int i = 0; i < n; i++) { // cycle은 n번
        
    }
    
    return answer;
}

int main() {
    solution(4);
    
    return 0;
}
