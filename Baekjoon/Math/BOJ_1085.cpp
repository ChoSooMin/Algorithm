//
//  BOJ_1085.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  직사각형에서 탈출

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    
    int answer = 0;
    answer = min(x, w - x);
    answer = min(answer, y);
    answer = min(answer, h - y);
    
    cout << answer << "\n";
    
    return 0;
}
