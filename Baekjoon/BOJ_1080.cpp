//
//  BOJ_1080.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  행렬(https://www.acmicpc.net/problem/1080)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> matrixA, matrixB;
int answer = 0;
int N, M;

void change(int y, int x) {
    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            matrixA.at(i).at(j) = 1 - matrixA.at(i).at(j);
        }
    }
}

void input() {
    // input
    cin >> N >> M;
    
    matrixA.resize(N);
    matrixB.resize(N);
    for (int i = 0; i < N; i++) {
        matrixA.at(i).resize(M);
        matrixB.at(i).resize(M);
    }
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++) {
            matrixA.at(i).at(j) = str[j] - '0'; // char 데이터형을 int형을 변환하는 간단한 방법 (숫자가 아스키 코드라는 것을 활용)
        }
    }
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++) {
            matrixB.at(i).at(j) = str[j] - '0';
        }
    }
}

int main() {
    input();
    
    // 3 * 3 행렬로 바뀌므로 i와 j는 각각 N - 3, M - 3까지
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (matrixA.at(i).at(j) != matrixB.at(i).at(j)) { // 다르면 연산을 해준다.
                answer++;
                change(i, j);
            }
        }
    }
    
    // 연산 이후
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrixA.at(i).at(j) != matrixB.at(i).at(j)) { // 다른 값이 나왔다면 연산을 아무리 해도 같아질 수 없으므로 -1을 출력
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << answer;
    
    return 0;
}
