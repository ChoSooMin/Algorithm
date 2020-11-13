//
//  Programmers_42883.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/12.
//  Copyright © 2020 조수민. All rights reserved.
//
//  큰 수 만들기(https://programmers.co.kr/learn/courses/30/lessons/42883)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int remainLength = number.length() - k;
    int max = -1;
    int maxIndex = -1;
    
    for (int i = 0; i < number.size() - k + 1; i++) {
        char cur = number.at(i);
        int curToInt = cur - '0'; // char를 int형으로 변환
        
        if (max < curToInt) {
            max = curToInt;
            maxIndex = i;
        }
    }
    answer += to_string(max);
    
    k -= maxIndex;
    cout << "max : " << max << " maxIndex : " << maxIndex << " remain k : " << k;
    cout << endl;
    
    remainLength -= 1;
    
    if (k == 1) { // k가 1만 남았을 때는 뒤의 원소들 중 가장 작은 애만 빼면 된다,,?
        int min = 10;
        int minIndex = -1;
        for (int i = maxIndex + 1; i < number.size(); i++) {
            char cur = number.at(i);
            int curToInt = cur - '0';
            
            if (min > curToInt) {
                min = curToInt;
                minIndex = i;
            }
        }
        
        for (int i = maxIndex + 1; i < number.size(); i++) {
            if (i == minIndex)
                continue;
            answer += number.at(i);
        }
    }
    else {
        int secondMax = -1;
        int secondMaxIndex = -1;
        
        for (int i = maxIndex + 1; i < number.length() - remainLength; i++) {
            
            char cur = number.at(i);
            int curToInt = cur - '0';
            
            cout << "index : " << i << "cur : " << cur << endl;
            
            if (secondMax < curToInt) {
                secondMax = curToInt;
                secondMaxIndex = i;
            }
        }
        
        answer += to_string(secondMax);
        k -= 1;
        
        cout << "secondMax < " << secondMax << " secondMaxIndex : " << secondMaxIndex << endl;
    }
    
    return answer;
}

int main() {
    solution("4177252841", 4);
    
    return 0;
}
