//
//  Programmers_68644.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/01.
//  Copyright © 2020 조수민. All rights reserved.
//
//  두 개 뽑아서 더하기(https://programmers.co.kr/learn/courses/30/lessons/68644)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int a = numbers.at(i);
            int b = numbers.at(j);
            
            int sum = a + b;
            
            if (find(answer.begin(), answer.end(), sum) != answer.end())
                continue;
            
            answer.push_back(sum);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    vector<int> ans1 = solution({2, 1, 3, 4, 1});
    
    cout << "====== ans1 ======" << endl;
    for (int i = 0; i < ans1.size(); i++) {
        cout << ans1.at(i) << " ";
    }
    cout << endl;
    
    vector<int> ans2 = solution({5, 0, 2, 7});
    
    cout << "====== ans2 ======" << endl;
    for (int i = 0; i < ans2.size(); i++) {
        cout << ans2.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
