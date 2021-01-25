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
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    vector<pair<int, int>> cantMix;
    
    // input
    cin >> N >> M;
    for (int i = 0; i < M ; i++) {
        int first, second;

        cin >> first >> second;
        cantMix.push_back({ first, second }); // 섞으면 안되는 조합의 번호쌍을 저장하는 벡터 (1, 2) (3, 4) (1, 3) 저장
    }
    
    // getAnswer
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        v.push_back(i);
    }
    
    // 조합 구하기
    vector<int> intd;
    for (int i = 0; i < 3; i++) {
        intd.push_back(1);
    }
    for (int i = 0; i < N - 3; i++) {
        intd.push_back(0);
    }
    
    sort(intd.begin(), intd.end());
    
    int answer = 0;
    do {
        vector<int> combiV;
        
        for (int i = 0; i < intd.size(); i++) {
            if (intd.at(i) == 1) {
                combiV.push_back(v.at(i));
            }
        }
        // -- combiV에는 조합의 경우가 들어간다.
        
        bool canCombi = true;
        for (int i = 0; i < cantMix.size(); i++) {
            int first = cantMix.at(i).first;
            int second = cantMix.at(i).second;
            
            if ((find(combiV.begin(), combiV.end(), first) != combiV.end()) && (find(combiV.begin(), combiV.end(), second) != combiV.end())) {
                canCombi = false; // 조합 불가능
                break;
            }
        }
        
        if (canCombi)
            answer++;
    } while(next_permutation(intd.begin(), intd.end()));
    
    cout << answer << endl;
    
    return 0;
}
