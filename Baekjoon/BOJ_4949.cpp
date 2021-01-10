//
//  BOJ_4949.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  균형잡힌 세상(https://www.acmicpc.net/problem/4949)

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    while (true) {
        string input;
        getline(cin, input); // string을 입력받아 input에 저장한다.
        if (input == ".")
            break;
        
        stack<char> S;
        
        bool isValid = true;
        
        for (auto c : input) {
            if (c == '(' || c == '[') {
                S.push(c);
            }
            else if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
            else if (c == ']') {
                if (S.empty() || S.top() != '[') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }
        
        if (!S.empty()) {
            isValid = false;
        }
        
        if (isValid)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
