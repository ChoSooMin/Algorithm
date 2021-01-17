//
//  SWEA_1926.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  간단한 369게임(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PTeo6AHUDFAUq&categoryId=AV5PTeo6AHUDFAUq&categoryType=CODE)

#include <stdio.h>
#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        string str = to_string(i);
        
        int isClap = 0;
        for (int index = 0; index < str.length(); index++) {
            char curChar = str[index];
            
            if (curChar == '3' || curChar == '6' || curChar == '9') {
                isClap += 1;
            }
        }
        
        if (isClap == 0) {
            cout << str << " ";
        }
        else {
            string output = "";
            for (int j = 1; j <= isClap; j++) {
                output += '-';
            }
            
            cout << output << " ";
        }
    }
    
    return 0;
}
