//
//  BOJ_11653.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/28.
//  Copyright © 2021 조수민. All rights reserved.
//
//  소인수분해(https://www.acmicpc.net/problem/11653)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 에라토스테네스의 체로 소수를 받아오고, 그걸 사용?
int a[10000001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    fill_n(a, 10000001, 1); // a 배열을 모두 1로 초기화한다.
    for (int i = 2; i <= N; i++) {
        if (a[i] == 0) // 이미 지워진 수라면 건너뛴다.
            continue;
        
        // 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 구하기
        for (int j = 2 * i; j <= N; j += i) {
            a[j] = 0;
        }
    }
    
    vector<int> v;
    while (N != 1) {
        for (int k = N; k >= 2; k--) {
            if (a[k] == 1 && N % k == 0) { // N보다 작은 소수이면서, N의 약수이면 소인수분해할 수 있다.
                v.push_back(k);
                N /= k;
            }
        }
    }
    
    sort(v.begin(), v.end(), less<int>());
    
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    
    
    return 0;
}
