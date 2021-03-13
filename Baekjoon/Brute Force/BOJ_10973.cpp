//
//  BOJ_10973.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/14.
//  Copyright © 2021 조수민. All rights reserved.
//
//  이전 순열(https://www.acmicpc.net/problem/10973)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    if (next_permutation(v.begin(), v.end(), greater<int>())) {
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << " ";
        }
    }
    else {
        cout << -1;
    }
    
    return 0;
}
