//
//  SWEA_1989.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/11.
//  Copyright © 2021 조수민. All rights reserved.
//
//  초심자의 회문 검사(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV5PyTLqAf4DFAUq&categoryId=AV5PyTLqAf4DFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=2&pageSize=10&pageIndex=1&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        string word;
        cin >> word;
        
        int isTrue = 1;
        
        for (int i = 0; i < word.length() / 2; i++) {
            if (word[i] != word[word.length() - 1 - i]) {
                isTrue = 0;
                break;
            }
        }
        
        cout << "#" << test_case << " " << isTrue << endl;
    }
    
    return 0;
}
