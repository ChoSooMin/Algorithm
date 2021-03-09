//
//  BOJ_10972.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  다음 순열(https://www.acmicpc.net/problem/10972)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v.at(i);
    }
    
    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < N; i++) {
            cout << v.at(i) << " ";
        }
    }
    else {
        cout << -1;
    }
    
    return 0;
}
