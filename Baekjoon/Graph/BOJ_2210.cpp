//
//  BOJ_2210.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/14.
//  Copyright © 2021 조수민. All rights reserved.
//
//  숫자판 점프(https://www.acmicpc.net/problem/2210)

#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int digit[5][5];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
set<string> v;

void getAnswer(pair<int, int> cur, int n, string str) {
    if (n == 5) {
        v.insert(str);
        
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nextX = cur.first + dx[i];
        int nextY = cur.second + dy[i];
        
        if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5)
            continue;
        
        str += to_string(digit[cur.first][cur.second]);
        getAnswer({nextX, nextY}, n + 1, str);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> digit[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            getAnswer({ i, j }, 0, to_string(digit[i][j]));
        }
    }
    
    cout << v.size();
    
    return 0;
}
