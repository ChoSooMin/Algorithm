//
//  BOJ_1629.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/11.
//  Copyright © 2021 조수민. All rights reserved.
//
//  곱셈(https://www.acmicpc.net/problem/1629)

#include <stdio.h>
#include <iostream>

using namespace std;

using ll = long long;

ll pow(ll a, ll b, ll c) {
    if (b == 1)
        return a % c;
    
    ll val = pow(a, b / 2, c);
    val = val * val % c;
    
    if (b % 2 == 0)
        return val;
    
    return val * a % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);
    
    return 0;
}
