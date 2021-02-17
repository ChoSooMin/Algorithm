//
//  BOJ_2567.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/17.
//  Copyright © 2021 조수민. All rights reserved.
//
//  색종이 - 2(https://www.acmicpc.net/problem/2567)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    // answer에 40 * num을 넣어두고, 겹치는 부분의 둘레를 뺀다.
    int answer = 40 * num;
    vector<pair<int, int>> v;
    for (int i = 0; i < num; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }
    
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            pair<int, int> a = v.at(i);
            pair<int, int> b = v.at(j);
            
            int minus = 0;
            
            if (a.first == b.first && a.second == b.second) {
                minus += (a.first + a.second);
                minus *= 2;
                
                answer -= minus;
                continue;
            }
            
            if ((a.first <= b.first) && (b.first <= a.first + 10) && (a.first + 10 <= b.first + 10)) {
                
                if ((a.second <= b.second) && (b.second <= a.second + 10) && (a.second + 10 <= b.second + 10)) {
                    minus += ((a.first + 10) - b.first);
                    minus += ((a.second + 10) - b.second);
                }
                else if ((b.second <= a.second) && (a.second <= b.second + 10) && (b.second + 10 <= a.second + 10)) {
                    minus += ((a.first + 10) - b.first);
                    minus += ((b.second + 10) - a.second);
                }
            }
            else if ((b.first <= a.first) && (a.first <= b.first + 10) && (b.first + 10 <= a.first + 10)) {
                if ((a.second <= b.second) && (b.second <= a.second + 10) && (a.second + 10 <= b.second + 10)) {
                    minus += ((b.first + 10) - a.first);
                    minus += ((a.second + 10) - b.second);
                }
                else if ((b.second <= a.second) && (a.second <= b.second + 10) && (b.second + 10 <= a.second + 10)) {
                    minus += ((b.first + 10) - a.first);
                    minus += ((b.second + 10) - a.second);
                }
            }
            
            minus *= 2;
            answer -= minus;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
