//
//  BOJ_11651.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  좌표 정렬하기 2(https://www.acmicpc.net/problem/11651)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<pair<int, int>> v;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        v.push_back({ y, x });
    }
    
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i).second << " " << v.at(i).first << "\n";
    }
    
    return 0;
}
