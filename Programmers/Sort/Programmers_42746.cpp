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
 cmp 함수를 만들어 정렬해준다!!
 이 때 비교는 string 형으로 한다.
 */
bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    // int형 벡터 numbers를 string형으로 바꿔 넣는다.
    vector<string> stringVector;
    for (int i = 0; i < numbers.size(); i++) {
        string s = to_string(numbers.at(i));
        
        stringVector.push_back(s);
    }
    
    /**
     sort 함수를 사용한다.
     이때, 마지막 인자에 비교 함수를 넣으면 그 함수 기준으로 정렬을 수행한다!!
     */
    sort(stringVector.begin(), stringVector.end(), cmp);
    
    for (int i = 0; i < stringVector.size(); i++) {
        string cur = stringVector.at(i);
        answer += cur;
    }
    
    if (answer[0] == '0') return "0"; // answer[0]이 0이면 가장 큰 수가 0이라는 뜻이므로 0을 리턴한다.
    
    return answer;
}

int main() {
    vector<int> numbers1 = { 6, 10, 2 };
    vector<int> numbers2 = { 3, 30, 34, 5, 9 };
    
    cout << solution(numbers1) << endl;
    cout << solution(numbers2) << endl;
    
    return 0;
}
