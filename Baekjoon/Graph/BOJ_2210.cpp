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
set<int> v;

void getAnswer(pair<int, int> cur, int n, int sum) {
    if (n == 5) {
        v.insert(sum);
        
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int nextX = cur.first + dx[i];
        int nextY = cur.second + dy[i];
        
        if (nextX < 0 || nextX >= 5 || nextY < 0 || nextY >= 5)
            continue;
        
        getAnswer({ nextX, nextY }, n + 1, sum * 10 + digit[nextX][nextY]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> digit[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            getAnswer({ i, j }, 0, digit[i][j]);
        }
    }
    
    cout << v.size();
    
    return 0;
}
