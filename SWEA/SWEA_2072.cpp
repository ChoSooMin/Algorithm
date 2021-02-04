//
//  SWEA_2072.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/04.
//  Copyright © 2021 조수민. All rights reserved.
//
//  홀수만 더하기(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&contestProbId=AV5QSEhaA5sDFAUq&categoryId=AV5QSEhaA5sDFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=1&pageSize=10&pageIndex=1&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int T;
    
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int a[10];
        
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            cin >> a[i];
            
            if (a[i] % 2 == 1)
                ans += a[i];
        }
        
        cout << "#" << test_case << " " << ans << endl;
    }
    
    return 0;
}
