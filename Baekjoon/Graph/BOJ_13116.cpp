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

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        
        vector<int> a;
        vector<int> b;
        
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
        }
        
        auto findA = b.end();
        for (int i = 0; i < a.size(); i++) {
            findA = find(b.begin(), b.end(), a.at(i));
            
            if (findA != b.end()) {
                break;
            }
        }
        
        cout << *findA * 10 << endl;
    }
    
    return 0;
}
