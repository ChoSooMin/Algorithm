//
//  BOJ_11729.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/11.
//  Copyright © 2021 조수민. All rights reserved.
//
//  하노이 탑 이동 순서(https://www.acmicpc.net/problem/11729)

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n) {
    if (n == 1) {
        cout << a << ' ' << b << endl;
        return;
    }
    
    // 1. n - 1개의 원판을 기둥 a에서 기둥 6 - a - b로 옮긴다.
    func(a, 6 - a - b, n - 1);
    
    // 2. n번 원판을 기둥 a에서 기둥 b로 옮긴다.
    cout << a << ' ' << b << endl;
    
    // 3. n - 1개의 원판을 기둥 6 - a - b에서 기둥 b로 옮긴다.
    func(6 - a - b, b, n - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    
//    cout << pow(2, k) - 1 << endl;
    cout << (1<<k) - 1 << endl;
    func(1, 3, k);
    
    return 0;
}
