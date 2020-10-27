//
//  Programmers_42839.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  소수 찾기(https://programmers.co.kr/learn/courses/30/lessons/42839)

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int numbersLength;
vector<string> newNums;
vector<bool> visited;

// 소수 판별 함수
bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    
    return true;
}

void dfs(int index, string num, char char_array[]) {
    string newNum = num;
  
    for (int i = 0; i < numbersLength; i++) {
        if (visited.at(i) == true) {
            continue;
        }
        
        newNum += char_array[i]; // 아직 방문하지 않은 곳의
        visited.at(i) = true;
        
        if (newNum.size() == numbersLength) {
            cout << "새로운 숫자! " << newNum << endl;
            break;
        }
        else {
            dfs(i, newNum, char_array);
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    numbersLength = numbers.length();
    char char_array[numbersLength + 1];
    strcpy(char_array, numbers.c_str());
    
    for (int i = 0; i < numbersLength; i++) {
        char current = char_array[i];
        
        visited.resize(numbersLength);
        fill(visited.begin(), visited.end(), false); // visited 초기화(false)
        
        string charToStr(1, current);
        visited.at(i) = true;
        dfs(i, charToStr, char_array);
    }
    
    return answer;
}

int main() {
    solution("012");
    
    return 0;
}
