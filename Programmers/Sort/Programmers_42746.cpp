//
//  Programmers_42746.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  가장 큰 수(https://programmers.co.kr/learn/courses/30/lessons/42746)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 int형 벡터를 string으로 바꿔서 내림차순 정렬 후,
 앞에서부터 붙인다
 */
string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> stringVector;
    for (int i = 0; i < numbers.size(); i++) {
        string s = to_string(numbers.at(i));
        
        stringVector.push_back(s);
    }
    
    // sort
    sort(stringVector.begin(), stringVector.end(), greater<string>()); // 내림차순 정렬 : greater 사용
    for (int i = 0; i < stringVector.size(); i++) {
        /**
         문제)
         2 10 1 로 정렬될 경우,
         2101보다 2110이 더 크다. -> 어떻게 비교?
         (string형) a+b값과 b+a 값을 비교하여 sort해준다.
         */
        if (i != stringVector.size() - 1) {
            string curStr = stringVector.at(i);
            string nextStr = stringVector.at(i + 1);
            
            if (curStr.at(0) == nextStr.at(0)) {
                int a = stoi(curStr + nextStr);
                int b = stoi(nextStr + curStr);
                
                if (a < b) {
                    // 현재와 뒤의 값을 바꿔준다.
                    stringVector.at(i) = nextStr;
                    stringVector.at(i + 1) = curStr;
                }
            }
        }
        
        string cur = stringVector.at(i);
        answer += cur;
    }
    
    return answer;
}

int main() {
    vector<int> numbers1 = { 6, 10, 2 };
    vector<int> numbers2 = { 3, 30, 34, 5, 9 };
    
    cout << solution(numbers1) << endl;
    cout << solution(numbers2) << endl;
    
    return 0;
}
