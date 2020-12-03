//
//  Programmers_12917.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/03.
//  Copyright © 2020 조수민. All rights reserved.
//
//  문자열 내림차순으로 배치하기(https://programmers.co.kr/learn/courses/30/lessons/12917)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    
    return s;
}

int main() {
    cout << solution("Zbcdefg") << endl;
    
    return 0;
}
