//
//  BOJ_17413.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/23.
//  Copyright © 2021 조수민. All rights reserved.
//
//  단어 뒤집기 2(https://www.acmicpc.net/problem/17413)

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

void popStack() {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    // 공백을 포함한 문자열을 입력받을 때
    string S;
    getline(cin, S); // getline 함수를 사용한다.
    
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '<') {
            popStack();
            
            while (S[i] != '>') {
                cout << S[i];
                i++;
            }
        }
        
        if (S[i] == '>') {
            cout << S[i];
            continue;
        }
        
        if (S[i] == ' ') {
            popStack();
            
            cout << S[i];
            continue;
        }
        
        s.push(S[i]);
        
        if (i == S.length() - 1) {
            popStack();
        }
    }
    
    return 0;
}
