//
//  SWEA_2070.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/14.
//  Copyright © 2021 조수민. All rights reserved.
//
//  큰 놈, 작은 놈, 같은 놈(https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=1&contestProbId=AV5QQ6qqA40DFAUq&categoryId=AV5QQ6qqA40DFAUq&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=1&pageSize=10&pageIndex=1&&&&&&&&&&)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        int a, b;
        cin >> a >> b;
        
        cout << "#" << test_case << " ";
        
        if (a > b)
            cout << ">" << endl;
        else if (a == b)
            cout << "=" << endl;
        else if (a < b)
            cout << "<" << endl;
    }
    
    return 0;
}
