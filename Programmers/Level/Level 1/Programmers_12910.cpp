//
//  Programmers_12910.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/22.
//  Copyright © 2020 조수민. All rights reserved.
//
//  나누어 떨어지는 숫자 배열(https://programmers.co.kr/learn/courses/30/lessons/12910)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) % divisor == 0)
            answer.push_back(arr.at(i));
    }
    
    if (answer.size() == 0)
        answer.push_back(-1);
    
    return answer;
}

int main() {
    vector<int> sol1 = solution({ 5, 9, 7, 10 }, 5);
    for (int i = 0; i < sol1.size(); i++) {
        cout << sol1.at(i) << " ";
    }
    cout << endl;
    
    vector<int> sol2 = solution({ 2, 36, 1, 3 }, 1);
    for (int i = 0; i < sol2.size(); i++) {
        cout << sol2.at(i) << " ";
    }
    cout << endl;
    
    vector<int> sol3 = solution({ 3, 2, 6 }, 10);
    for (int i = 0; i < sol3.size(); i++) {
        cout << sol3.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
