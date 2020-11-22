//
//  BOJ_2667.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/18.
//  Copyright © 2020 조수민. All rights reserved.
//
//  단지번호붙이기(https://www.acmicpc.net/problem/2667)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int N;
int map[25][25]; // 지도
bool visit[25][25]; // 방문 여부를 저장하는 배열
int cnt; // 단지내 집 수를 저장
// 위치 이동
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<int> vec;

// DFS
void getHouseCount(int curX, int curY) {
    cnt++;
    
    visit[curX][curY] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = curX + dx[i];
        int ny = curY + dy[i];
        
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (map[nx][ny] == 1 && visit[nx][ny] == false)
            getHouseCount(nx, ny); // 다음 이동할 곳이 아직 방문하지 않은 곳이고, 집이 있는 곳이면 다시 getHouseCount
    }
}

int main() {
    cin >> N;
    
    // input
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        
        for (int j = 0; j < N; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 방문하지 않았고, 집이 있는 곳이라면
            if (map[i][j] == 1 && visit[i][j] == false) {
                cnt = 0; // 한 단지 시작
                getHouseCount(i, j); // 단지 내에 집이 몇 가구 있는가?를 계산해준다.
                vec.push_back(cnt); // getHouseCount를 한 후 cnt는 한 단지에 몇 가구의 집이 있는지를 저장하고 있다.
            }
        }
    }
    
    sort(vec.begin(), vec.end()); // 오름차순 정렬
    
    cout << vec.size() << endl;
    
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    
    return 0;
}
