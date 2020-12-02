//
//  Programmers_12906.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/02.
//  Copyright © 2020 조수민. All rights reserved.
//
//  같은 숫자는 싫어(https://programmers.co.kr/learn/courses/30/lessons/12906)/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr.at(0));

    for (int i = 1; i < arr.size(); i++) {
        if (arr.at(i - 1) != arr.at(i))
            answer.push_back(arr.at(i));
    }

    return answer;
}

int main() {
    vector<int> sol1 = solution({ 1, 1, 3, 3, 0, 1, 1 });
    cout << "== sol1 ==" << endl;
    for (int i = 0; i < sol1.size(); i++) {
        cout << sol1.at(i) << " ";
    }
    cout << endl;
    
    vector<int> sol2 = solution({ 4, 4, 4, 3, 3 });
    cout << "== sol2 ==" << endl;
    for (int i = 0; i < sol2.size(); i++) {
        cout << sol2.at(i) << " ";
    }
    cout << endl;
    
    
    return 0;
}
