//
//  BOJ_2563.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/09.
//  Copyright © 2021 조수민. All rights reserved.
//
//  색종이(https://www.acmicpc.net/problem/2563)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> v;
    
    int answer = 100 * N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    
    vector<pair<int, int>> already;
    for (int i = 0; i < v.size() - 1; i++) {
        int aX = v.at(i).first;
        int aY = v.at(i).second;
        
        for (int j = i + 1; j < v.size(); j++) {
            int bX = v.at(j).first;
            int bY = v.at(j).second;
            
            if (aX == bX && aY == bY) {
                auto p = make_pair(bX, bY);
                auto f = find(already.begin(), already.end(), p);
                
                if (f != already.end()) {
                    continue;
                }
                else {
                    answer -= 100;
                    already.push_back(p);
                }
            }
            
            int absX = 0;
            int absY = 0;
            if (bX <= aX && aX <= bX + 10 && bX + 10 <= aX + 10) {
                absX = abs((bX + 10) - aX);
            }
            if (aX <= bX && bX <= aX + 10 && aX + 10 <= bX + 10) {
                absX = abs((aX + 10) - bX);
            }
            
            if (bY <= aY && aY <= bY + 10 && bY + 10 <= aY + 10) {
                absY = abs((bY + 10) - aY);
            }
            if (aY <= bY && bY <= aY + 10 && aY + 10 <= bY + 10) {
                absY = abs((aY + 10) - bY);
            }
        
            
            
            if (absX != 0 && absY != 0) {
                answer -= absX * absY;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
