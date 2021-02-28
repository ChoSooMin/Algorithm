//
//  BOJ_2309.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/28.
//  Copyright © 2021 조수민. All rights reserved.
//
//  일곱 난쟁이(https://www.acmicpc.net/problem/2309)

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> height;
int getCombi[9] = { 0, 0, 1, 1, 1, 1, 1, 1, 1 };

int main() {
    height.resize(9);
    // input
    for (int i = 0; i < 9; i++) {
        cin >> height.at(i);
    }
    
    sort(height.begin(), height.end());
    
    do {
        int sum = 0;
        
        for (int i = 0; i < 9; i++) {
            if (getCombi[i] == 1)
                sum += height[i];
        }
        
        if (sum == 100) {
            for (int i = 0; i < 9; i++) {
                if (getCombi[i] == 1)
                    cout << height[i] << "\n";
            }
            
            return 0;
        }
    } while(next_permutation(getCombi, getCombi + 9));
    
    return 0;
}
