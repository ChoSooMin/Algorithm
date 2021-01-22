//
//  SWEA_1966.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/23.
//  Copyright © 2021 조수민. All rights reserved.
//
//  숫자를 정렬하자(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PrmyKAWEDFAUq&categoryId=AV5PrmyKAWEDFAUq&categoryType=CODE&&&)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int n;
            cin >> n;
            
            v.push_back(n);
        }
        
        sort(v.begin(), v.end());
        
        cout << "#" << test_case << " ";
        for (int i = 0; i < v.size(); i++) {
            cout << v.at(i) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
