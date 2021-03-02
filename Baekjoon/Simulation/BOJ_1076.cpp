//
//  BOJ_1076.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/02.
//  Copyright © 2021 조수민. All rights reserved.
//
//  저항(https://www.acmicpc.net/problem/1076)

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

string color[10] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    string first, second, third;
    cin >> first >> second >> third;
    
    string ans = "";
    string f, s;
    int t;
    for (int i = 0; i < 10; i++) {
        if (color[i] == first) {
            f = to_string(i);
        }
        if (color[i] == second) {
            s = to_string(i);
        }
        if (color[i] == third) {
            t = i;
        }
    }
    
    ans += (f + s);
    int answer = stoi(ans) * pow(10, t);
    cout << answer << "\n";
    
    return 0;
}
