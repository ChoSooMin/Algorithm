//
//  SWEA_1859.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/19.
//  Copyright © 2021 조수민. All rights reserved.
//
//  백만장자 프로젝트(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE)

#include <stdio.h>
#include <iostream>

using namespace std;

int num[1000002] = { 0, };

int main(int argc, char** argv) {
    int T;
    
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N;
        long long ans = 0;
        
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> num[j];
        }
        
        int max_budget = num[N - 1];
        
        for (int j = N - 1; j >= 0; j--) {
            if (max_budget >= num[j]) {
                ans += (max_budget - num[j]);
            }
            else {
                max_budget = num[j];
            }
        }
        
        cout << "#" << i + 1 << " " << ans << endl;
        for (int j = 0; j < N; j++) {
            num[j] = 0;
        }
    }
    
    return 0;
}
