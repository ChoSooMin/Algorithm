//
//  BOJ_15649.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/29.
//  Copyright © 2021 조수민. All rights reserved.
//
//  N과 M (1) (https://www.acmicpc.net/problem/15649)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 9

using namespace std;

int N, M;
int visit[MAX];
vector<int> selected;

void print_permutation() {
    for (int i = 0; i < selected.size(); i++) {
        cout << selected.at(i) << " ";
    }
    
    cout << "\n";
}

void getPermutation(int count) {
    if (count == M) {
        print_permutation();
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1) // 이미 쓰여진 숫자면 다음으로 넘어감
            continue;
        
        visit[i] = 1; // 숫자가 쓰여졌다고 체크해주고
        selected.push_back(i);
        getPermutation(count + 1);
        selected.pop_back();
        visit[i] = 0;
    }
}

// 순열 구하기
int main() {
    cin >> N >> M;
    
    getPermutation(0);
    
    return 0;
}
