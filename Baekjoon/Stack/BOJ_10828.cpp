//
//  BOJ_10828.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/11.
//  Copyright © 2021 조수민. All rights reserved.
//
//  스택(https://www.acmicpc.net/problem/10828)

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    stack<int> s;
    
    while (N--) {
        string str;
        cin >> str;
        
        if (str == "push") {
            int t;
            cin >> t;
            s.push(t);
        }
        else if (str == "pop") {
            if (s.empty())
                cout << -1 << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (str == "size")
            cout << s.size() << endl;
        else if (str == "empty")
            cout << (int)s.empty() << endl;
        else {
            if (s.empty())
                cout << -1 << endl;
            else
                cout << s.top() << endl;
        }
    }
    
    return 0;
}
