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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        
        while (A != B) { // 같으면 끝난다.
            if (A > B) { // A가 더 클 경우
                A /= 2;
            }
            else { // B가 더 클 경우
                B /= 2;
            }
        }
        
        cout << A * 10 << "\n";
    }
    
    return 0;
}
