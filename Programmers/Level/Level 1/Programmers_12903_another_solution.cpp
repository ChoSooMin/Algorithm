//
//  Programmers_12903_another_solution.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/01.
//  Copyright © 2020 조수민. All rights reserved.
//
//  가운데 글자 가져오기(https://programmers.co.kr/learn/courses/30/lessons/12903)

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int strLength = s.length();
    
    if (strLength % 2 == 0) { // 단어의 길이가 짝수
        answer = s.substr(strLength / 2 - 1, 2);
    }
    else {
        answer = s.substr(strLength / 2, 1);
    }
    
    return answer;
}

int main() {
    cout << solution("abcde") << endl;
    cout << solution("qwer") << endl;
    
    return 0;
}
