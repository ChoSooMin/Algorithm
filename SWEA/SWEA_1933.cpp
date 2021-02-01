//
//  SWEA_1933.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/02.
//  Copyright © 2021 조수민. All rights reserved.
//
//  간단한 N의 약수(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&contestProbId=AV5PhcWaAKIDFAUq&categoryId=AV5PhcWaAKIDFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=1&pageSize=10&pageIndex=2&&&&&&&&&&)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (N % i != 0)
            continue;
        
        v.push_back(i);
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    
    return 0;
}
