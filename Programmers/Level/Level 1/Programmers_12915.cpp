//
//  Programmers_12915.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/27.
//  Copyright © 2020 조수민. All rights reserved.
//
//  문자열 내 마음대로 정렬하기(https://programmers.co.kr/learn/courses/30/lessons/12915)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool sortAlgorithm(string a, string b) {
    if (a.at(N) != b.at(N)) {
        return a.at(N) < b.at(N); // N 인덱스의 문자로 정렬
    }
    else {
        return a < b; // 사전순으로 정렬
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = strings;
    
    N = n;
    
    sort(answer.begin(), answer.end(), sortAlgorithm);
    
    return answer;
}

int main() {
    
    
    return 0;
}
