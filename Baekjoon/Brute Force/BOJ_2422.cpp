//
//  BOJ_2422.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/25.
//  Copyright © 2021 조수민. All rights reserved.
//
//  한윤정이 이탈리아에 가서 아이스크림을 사먹는데(https://www.acmicpc.net/problem/2422)

#include <stdio.h>
#include <iostream>

using namespace std;

int cantMix[205][205];

int main() {
    int N, M;
    int answer = 0;
    
    // input
    cin >> N >> M;
    for (int i = 0; i < M ; i++) {
        int first, second;

        cin >> first >> second;
        cantMix[first][second] = 1;
        cantMix[second][first] = 1;
    }
    
    // 조합 구하기
    for (int x = 1; x <= N - 2; x++) { // 조합의 첫번째 수는 N - 2 인덱스까지 가능
        for (int y = x + 1; y <= N - 1; y++) {
            if (cantMix[x][y] == 1 || cantMix[y][x] == 1) // x와 y가 조합이 불가능하면 다음으로 넘긴다
                continue;
            
            for (int z = y + 1; z <= N; z++) {
                if (cantMix[x][z] == 1 || cantMix[y][z] == 1)
                    continue;
                
                answer++;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
