//
//  BOJ_1244.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/08.
//  Copyright © 2021 조수민. All rights reserved.
//
//  스위치 켜고 끄기(https://www.acmicpc.net/problem/1244)

#include <stdio.h>
#include <iostream>

#define MAX 101
#define MAX_INDEX 20

using namespace std;

int N;
bool switches[MAX];

void pressSwitch(int idx) { // 스위치 누르기
    switches[idx] = 1 - switches[idx];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> switches[i];
    }
    
    int students;
    cin >> students;
    for (int i = 0; i < students; i++) {
        int gender, num;
        cin >> gender >> num;
        
        if (gender == 1) { // 남학생일 경우
            for (int j = num; j <= N; j+= num) { // 배수마다 스위치를 누른다
                pressSwitch(j);
            }
            
            continue;
        }
        
        pressSwitch(num);
        
        // 여학생일 경우
        for (int j = num - 1, k = num + 1; (j >= 1 && k <= N && switches[j] == switches[k]); j--, k++) {
            pressSwitch(j);
            pressSwitch(k);
        }
    }
    
    // 출력 형식
    for (int i = 1; i <= N; i++) {
        cout << switches[i] << " ";
        
        if (i % 20 == 0 || i == N) {
            cout << endl;
            continue;
        }
    }
    
    return 0;
}
