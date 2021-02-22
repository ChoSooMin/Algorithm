//
//  BOJ_17281.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/22.
//  Copyright © 2021 조수민. All rights reserved.
//
//  ⚾(https://www.acmicpc.net/problem/17281)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int batter[10];
int turn[10];

void play() {
    int score = 0;
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    int N;
    cin >> N;
    
    vector<int> order = { 1, 2, 3, 5, 6, 7, 8, 9 };
    sort(order.begin(), order.end());
    
    for (int inning = 0; inning < N; inning++) {
        for (int i = 1; i <= 9; i++) {
            cin >> batter[i];

            // 게임 진행
            // 1. next_permutation을 사용해서 순서를 정해준다.
            do {
                for (int index = 0; index < order.size(); index++) {
                    cout << order.at(index) << " ";
                }

                cout << "\n";
            } while (next_permutation(order.begin(), order.end()));

            // 2. 각 순서에 맞게 게임을 돌린다.
            // 3. 그 중 max 값을 출력?
        }
    }
    
    return 0;
}
