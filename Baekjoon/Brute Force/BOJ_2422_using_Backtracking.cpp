//
//  BOJ_2422_using_Backtracking.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/29.
//  Copyright © 2021 조수민. All rights reserved.
//
//  한윤정이 이탈리아에 가서 아이스크림을 사먹는데(https://www.acmicpc.net/problem/2422)

#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX 201

using namespace std;

int N, M, answer;
int visited[MAX]; // Backtracking 사용하기 위한 배열(체크 배열)
int bad[MAX][MAX]; // 섞을 수 없는 조합

vector<int> selected; // 조합을 넣어놓는 배열

void DFS(int index, int count) {
    if (count == 3) { // 조합을 찾은 경우
        // 섞을 수 없는 조합이 존재하는지 검사
        for (int i = 0; i < selected.size(); i++) {
            for (int j = 0; j < selected.size(); j++) {
                if (i == j)
                    continue;
                
                if (bad[selected[i]][selected[j]] == 1) // 섞을 수 없는 조합
                    return;
            }
        }
        
        answer++; // 조합이 정상적이라면 경우의 수 + 1
        
        return;
    }
    
    for (int i = index; i <= N; i++) {
        if (visited[i] == 1)
            continue;
        
        visited[i] = 1;
        selected.push_back(i);
        DFS(i, count + 1);
        visited[i] = 0;
        selected.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        bad[a][b] = 1;
        bad[b][a] = 1;
    }
    
    DFS(1, 0);
    cout << answer << endl;
    
    return 0;
}
