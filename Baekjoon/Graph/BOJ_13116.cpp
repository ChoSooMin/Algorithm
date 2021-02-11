//
//  BOJ_13116.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/11.
//  Copyright © 2021 조수민. All rights reserved.
//
//  30번(https://www.acmicpc.net/problem/13116)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getAnswer(int A, int B) {
    vector<int> a;
    vector<int> b;
    
    vector<int>::iterator findA = b.end();
    vector<int>::iterator findB = a.end();
    while (A != B) {
        if (A % 2 == 0) {
            A /= 2;
        }
        else {
            A = (A - 1) / 2;
        }
        
        if (B % 2 == 0) {
            B /= 2;
        }
        else {
            B = (B - 1) / 2;
        }
        a.push_back(A);
        b.push_back(B);

        findA = find(b.begin(), b.end(), A);
        if (findA != b.end()) {
            cout << (*findA) * 10 << endl;
            break;
        }
        
        findB = find(a.begin(), a.end(), B);
        if (findB != a.end()) {
            cout << (*findB) * 10 << endl;
            break;
        }
    }
    
    
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        
        getAnswer(A, B);
    }
    
    return 0;
}
