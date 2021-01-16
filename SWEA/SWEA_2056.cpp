//
//  SWEA_2056.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/16.
//  Copyright © 2021 조수민. All rights reserved.
//
//  연월일 달력(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    vector<string> dates;
    for (int i = 0; i < T; i++) {
        string date;
        cin >> date;
        dates.push_back(date);
    }
    
    for (int i = 0; i < dates.size(); i++) {
        cout << "#" << i + 1 << " ";
        string cur = dates.at(i);
        
        string year = (cur.substr(0, 4));
        string month = (cur.substr(4, 2));
        string day = (cur.substr(6, 2));
        
        if (stoi(month) <= 0 || stoi(month) >= 12 || stoi(day) <= 0 || stoi(day) >= 32) {
            cout << -1 << endl;
            continue;
        }
        
        if (stoi(month) == 2) {
            if (stoi(day) >= 29) {
                cout << -1 << endl;
                continue;
            }
        }
        
        if (stoi(month) == 4 || stoi(month) == 6 || stoi(month) == 9 || stoi(month) == 11) {
            if (stoi(day) >= 31) {
                cout << -1 << endl;
                continue;
            }
        }
        
        cout << year << "/" << month << "/" << day << endl;
    }
    
    return 0;
}
