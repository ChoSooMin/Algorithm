//
//  BOJ_14719.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/25.
//  Copyright © 2020 조수민. All rights reserved.
//
//  빗물(https://www.acmicpc.net/problem/14719)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    int answer = 0;
    
    cin >> H >> W;
    vector<int> v(W);
    
    // input
    for (int i = 0; i < W; i++) {
        cin >> v.at(i);
    }
    
    for (int i = 1; i < W - 1; i++) {
        int left = 0;
        int right = 0;
        
        // 왼쪽 최대
        for (int j = 0; j < i; j++) {
            left = max(left, v.at(j));
        }
        
        // 오른쪽 최대
        for (int j = W - 1; j > i; j--) {
            right = max(right, v.at(j));
        }
        
        answer += max(0, min(left, right) - v[i]);
    }
    
    cout << answer << endl;
    return 0;
}
