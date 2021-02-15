//
//  BOJ_3040.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/15.
//  Copyright © 2021 조수민. All rights reserved.
//
//  백설 공주와 일곱 난쟁이(https://www.acmicpc.net/problem/3040)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int sum = 0;
    
    // input
    num.resize(9);
    for (int i = 0; i < 9; i++) {
        cin >> num.at(i);
        sum += num.at(i);
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - num.at(i) - num.at(j) == 100) { // 두 명의 키를 뺐을 때의 합이 100이라면
                for (int k = 0; k < 9; k++) { // 출력
                    if (k != i && k != j)
                        cout << num.at(k) << "\n";
                }
                break;
            }
        }
    }
    
    return 0;
}
