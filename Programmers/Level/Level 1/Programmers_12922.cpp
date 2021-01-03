//
//  Programmers_12922.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/03.
//  Copyright © 2021 조수민. All rights reserved.
//
//  수박수박수박수박수박수?(https://programmers.co.kr/learn/courses/30/lessons/12922)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for (int i = 0; i < n / 2; i++) {
        answer += "수박";
    }
    
    if (n % 2 != 0) {
        answer += "수";
    }
    
    return answer;
}

int main() {
    cout << solution(5) << endl;
    
    return 0;
}
