//
//  recurrence_prac.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  재귀로 1부터 n까지 합 구하기 연습

#include <stdio.h>
#include <iostream>

using namespace std;

int recur(int n) {
    if (n == 1)
        return 1;
    
    return n + recur(n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << recur(4) << endl;
    
    return 0;
}
