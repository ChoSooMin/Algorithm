//
//  Programmers_12917.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/03.
//  Copyright © 2020 조수민. All rights reserved.
//
//  문자열 내림차순으로 배치하기(https://programmers.co.kr/learn/courses/30/lessons/12917)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> asciiVec;
    vector<char> sortedVec;
    
    for (int i = 0; i < s.length(); i++) {
        asciiVec.push_back(s[i] - '0');
    }
    
    sort(asciiVec.begin(), asciiVec.end(), greater<>());
    
    for (int i = 0; i < asciiVec.size(); i++) {
        char c = asciiVec.at(i);
        
        cout << (char)asciiVec.at(i) << " ";
        
        answer += c;
    }
    
    return answer;
}

int main() {
    cout << solution("Zbcdefg") << endl;
    
    return 0;
}
