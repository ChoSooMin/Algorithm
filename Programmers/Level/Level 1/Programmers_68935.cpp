//
//  Programmers_68935.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/28.
//  Copyright © 2020 조수민. All rights reserved.
//
//  3진법 뒤집기(https://programmers.co.kr/learn/courses/30/lessons/68935)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }
    
    reverse(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++) {
        answer += pow(3, i) * v.at(i);
    }
    
    return answer;
}

int main() {
    cout << solution(3) << endl;
    
    return 0;
}
