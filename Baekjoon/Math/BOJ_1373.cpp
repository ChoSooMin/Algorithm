//
//  BOJ_1373.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  2진수 8진수(https://www.acmicpc.net/problem/1373)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string str;
    cin >> str;
    
    int leng = str.length();
    
    if (leng % 3 == 1) {
        cout << str[0];
    }
    else if (leng % 3 == 2) {
        cout << (str[0] - '0') * 2 + (str[1] - '0');
    }
    
    for (int i = leng % 3; i < leng; i+= 3) {
        cout << (str[i] - '0') * 4 + (str[i + 1] - '0') * 2 + (str[i + 2] - '0');
    }
    cout << "\n";
    
    return 0;
}
