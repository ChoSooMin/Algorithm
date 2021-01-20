//
//  SWEA_1983.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/20.
//  Copyright © 2021 조수민. All rights reserved.
//
//  조교의 성적 매기기(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PwGK6AcIDFAUq&categoryId=AV5PwGK6AcIDFAUq&categoryType=CODE)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int T;
    cin >> T;
    
    string ans[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
    for (int i = 1; i <= T; i++) {
        int N, K;
        cin >> N >> K;
        
        vector<pair<double, int>> v;
        for (int j = 1; j <= N; j++) {
            int first, last, hw;
            double total;
            
            cin >> first >> last >> hw;
            total = first * 0.35 + last * 0.45 + hw * 0.2;
            v.push_back({ total, j });
        }
        
        sort(v.begin(), v.end(), greater<pair<double, int>>());
        
        for (int j = 0; j < v.size(); j++) {
            if (v.at(j).second == K) {
                cout << "#" << i << " " << ans[(j * 10) / N] << endl;
                break;
            }
        }
    }
    
    return 0;
}
