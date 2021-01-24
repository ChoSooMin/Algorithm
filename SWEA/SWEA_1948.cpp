//
//  SWEA_1948.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/25.
//  Copyright © 2021 조수민. All rights reserved.
//
//  날짜 계산기(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PnnU6AOsDFAUq&categoryId=AV5PnnU6AOsDFAUq&categoryType=CODE&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int dates[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int T;
    cin >> T;
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        
        int firstMonth, firstDate;
        int secondMonth, secondDate;
        
        cin >> firstMonth >> firstDate >> secondMonth >> secondDate;
        
        int ans = 0;
        if (firstMonth == secondMonth) {
            ans += secondDate - firstDate + 1;
        }
        else {
            for (int i = firstMonth + 1; i < secondMonth; i++) {
                ans += dates[i];
            }
            
            ans += dates[firstMonth] - firstDate + 1;
            ans += secondDate;
        }
        
        cout << "#" << test_case << " ";
        cout << ans << endl;
    }
    
    return 0;
}
