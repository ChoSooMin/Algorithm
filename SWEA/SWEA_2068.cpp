//
//  SWEA_2068.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/28.
//  Copyright © 2021 조수민. All rights reserved.
//
//  최대수 구하기(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQhbqA4QDFAUq&categoryId=AV5QQhbqA4QDFAUq&categoryType=CODE)

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int maxNum = 0;
        
        for (int i = 0; i < 10; i++) {
            int num;
            cin >> num;
            
            maxNum = max(num, maxNum);
        }
        
        cout << "#" << test_case << " " << maxNum << endl;
    }
    
    return 0;
}
