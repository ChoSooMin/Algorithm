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

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string third = "";
    
    int division = 100; // 몫
    int remainder = -1; // 나머지
    
    while (division >= 3) { // 몫이 3보다 크거나 같은 동안 계속 반복
        division = n / 3; // 3으로 나눈 몫
        remainder = n % 3; // 3으로 나눈 나머지
        
        third += to_string(remainder); // 이렇게 넣으면 뒤집을 필요 없음 (애초에 반전이 되어서 들어간다)
        n = division;
    }
    
    third += to_string(division); // 마지막 몫도 추가해준다
    
    for (int i = 0; i < third.length(); i++) {
        int curNum = third[i] - '0';
        int powNum = third.length() - i - 1;
        
        answer += curNum * pow(3, powNum);
    }
    
    
    return answer;
}

int main() {
    cout << solution(45) << endl;
    
    return 0;
}
