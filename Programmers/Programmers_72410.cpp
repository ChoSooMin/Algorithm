//
//  Programmers_72410.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/01.
//  Copyright © 2021 조수민. All rights reserved.
//
//  신규 아이디 추천(https://programmers.co.kr/learn/courses/30/lessons/72410)

#include <stdio.h>
#include <iostream>

using namespace std;

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    
    return in;
}

string solution(string new_id) {
    string answer = "";
    string n = new_id;
    
    // 1단계) 대문자 -> 소문자 & 2단계) 소문자, 숫자, 빼기, 마침표만 가능
    for (int i = 0; i < new_id.length(); i++) {
        char c = new_id[i];
        
        // 대소문자 or '-', '_', '.'
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-' || c == '_' || c == '.' || (c >= '0' && c <= '9')) {
            if (c <= 'Z' && c >= 'A')
                c -= ('Z' - 'z');
            
            answer += c;
        }
    }
    
    // 3단계
    string after3 = "";
    for(int i = 0; i < answer.length(); i++){
        if(i && answer[i] == '.' && answer[i - 1] == '.')
            continue;
        after3 += answer[i];
    }
    
    // 4단계
    string after4 = "";
    for (int i = 0; i < after3.length(); i++) {
        if (i == 0 && after3[i] == '.')
            continue;
        if (i == after3.length() - 1 && after3[i] == '.')
            continue;
        
        after4 += after3[i];
    }
    
    // 5단계
    string after5 = "";
    if (after4 == "") {
        after5 += "a";
    }
    else {
        after5 = after4;
    }
    
    // 6단계
    string after6 = "";
    if (after5.length() >= 16) {
        for (int i = 0; i < 15; i++) {
            if (i == 14 && after5[i] == '.')
                continue;
            
            after6 += after5[i];
        }
    }
    else {
        after6 = after5;
    }
    
    // 7단계
    answer = after6;
    if (answer.length() <= 2) {
        while (answer.length() != 3) {
            answer += after6[after6.length() - 1];
        }
    }
    
    return answer;
}

int main() {
    cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("=.=") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;
    
    return 0;
}
