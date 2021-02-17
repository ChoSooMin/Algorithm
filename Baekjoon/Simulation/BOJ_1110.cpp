//
//  BOJ_1110.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  더하기 사이클(https://www.acmicpc.net/problem/1110)

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string newNum = to_string(N);
    
    int answer = 0;
    while (true) {
        int addN = 0;
        for (int i = 0; i < newNum.length(); i++) {
            addN += newNum[i] - '0';
        }
        
        newNum = newNum[newNum.length() - 1]; // 주어진 수의 가장 오른쪽 수
        string addNtoStr = to_string(addN);
        newNum += addNtoStr[addNtoStr.length() - 1]; // 각 자리의 숫자를 더한 후, 가장 오른쪽 수
        answer++;
        
        if (stoi(newNum) == N)
            break;
    }
    
    cout << answer << "\n";
    
    return 0;
}
