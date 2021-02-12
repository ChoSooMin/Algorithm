//
//  SWEA_2047.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/12.
//  Copyright © 2021 조수민. All rights reserved.
//
//  신문 헤드라인(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&contestProbId=AV5QKsLaAy0DFAUq&categoryId=AV5QKsLaAy0DFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=1&pageSize=10&pageIndex=1&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        char c = word[i];

        if (97 <= c && c <= 122)
            cout << char(c - 32); // 아스키코드를 char로 출력
        else
            cout << c;
    }
    
    return 0;
}
