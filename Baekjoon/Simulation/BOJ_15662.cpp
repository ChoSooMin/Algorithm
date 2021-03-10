//
//  BOJ_15662.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/03/10.
//  Copyright © 2021 조수민. All rights reserved.
//
//  톱니바퀴 (2) (https://www.acmicpc.net/problem/15662)

#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX 1001

using namespace std;

int T, K;
int wheels[MAX][8];
vector<pair<int, int>> v;

void input() {
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        string str;
        cin >> str;
        
        for (int j = 0; j < str.length(); j++) {
            wheels[i][j] = str[j] - '0';
        }
    }
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        int wheelNum, location;
        cin >> wheelNum >> location;
        
        v.push_back({ wheelNum, location });
    }
}

// wheelNum번 바퀴를 direction 방향으로 회전시킨다.
void rotate(int wheelNum, int direction) {
    int temp[8];
    
    if (direction == 1) { // 시계 방향으로 회전
        // index + 1로 이동하고, 7 인덱스가 0 인덱스로 이동한다.
        for (int i = 0; i <= 6; i++) {
            temp[i + 1] = wheels[wheelNum][i];
        }
        temp[0] = wheels[wheelNum][7];
    }
    else { // 반시계 방향으로 회전
        // index - 1로 이동하고, 0 인덱스가 7 인덱스로 이동한다.
        for (int i = 7; i >= 1; i--) {
            temp[i - 1] = wheels[wheelNum][i];
        }
        temp[7] = wheels[wheelNum][0];
    }
    
    for (int i = 0; i <= 7; i++) {
        wheels[wheelNum][i] = temp[i];
    }
}

void rotateWheels(int standard, int direction) { // 톱니는 2번과 6번이 맞닿아있다
    // wheelNum 톱니 기준 오른쪽 톱니들을 돌려준다.
    int before = standard;
    int beforeDirection = direction;
    for (int i = standard + 1; i <= T; i++) { // 이전의 2번과 현재의 6번을 비교한다.
        if (beforeDirection != 0) { // 이전의 톱니가 회전할 경우
            if (wheels[before][2] == wheels[i][6]) { // 맞닿은 극이 같다면 회전하지 않는다.
                beforeDirection = 0;
            }
            else { // 맞닿은 극이 다르다면 회전한다. (이전의 방향과 다른 방향으로 회전)
                if (beforeDirection == 1) {
                    beforeDirection = -1;
                }
                else {
                    beforeDirection = 1;
                }
                rotate(i, beforeDirection); // 현재 바퀴를 회전시킨다.
            }
            
            before = i; // 다음 톱니바퀴와 비교하기 위해 before을 현재 톱니바퀴로 바꿔준다.
        }
    }
    
    // wheelNum 톱니 기준 왼쪽 톱니들을 돌려준다.
    before = standard;
    beforeDirection = direction;
    for (int i = standard - 1; i >= 1; i--) { // 이전의 6번과 현재의 2번을 비교한다.
        if (beforeDirection != 0) { // 이전의 톱니가 회전할 경우
            if (wheels[before][6] == wheels[i][2]) { // 맞닿은 극이 같다면 회전하지 않는다.
                beforeDirection = 0;
            }
            else { // 맞닿은 극이 다르다면 회전한다. (이전의 방향과 다른 방향으로 회전)
                if (beforeDirection == 1) {
                    beforeDirection = -1;
                }
                else {
                    beforeDirection = 1;
                }
                rotate(i, beforeDirection); // 현재 바퀴를 회전시킨다.
            }
            
            before = i; // 다음 톱니바퀴와 비교하기 위해 before을 현재 톱니바퀴로 바꿔준다.
        }
    }
    
    rotate(standard, direction);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    
    for (int i = 0; i < v.size(); i++) {
        int wheelNum = v.at(i).first; // 회전시킬 톱니바퀴 번호
        int location = v.at(i).second; // 회전시킬 방향
        
        rotateWheels(wheelNum, location);
    }
    
    int answer = 0;
    for (int i = 1; i <= T; i++) {
        if (wheels[i][0] == 1)
            answer++;
    }
    
    cout << answer << "\n";
    
    return 0;
}
