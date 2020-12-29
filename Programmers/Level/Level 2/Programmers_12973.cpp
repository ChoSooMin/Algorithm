//
//  Programmers_12973.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/29.
//  Copyright © 2020 조수민. All rights reserved.
//
//  짝지어 제거하기(https://programmers.co.kr/learn/courses/30/lessons/12973)

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    string origin = s;

    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] == s[i]) { // 같은 문자열일 경우
            s.erase(i - 1, i);
        }
        cout << s << endl;
    }
    
    if (origin == s) {
        answer = 0;
    }
    else {
        answer = 1;
    }

    return answer;
}

int main() {
    solution("baabaa");
    
    return 0;
}
