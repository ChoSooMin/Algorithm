//
//  Programmers_42842.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/28.
//  Copyright © 2020 조수민. All rights reserved.
//
//  카펫(https://programmers.co.kr/learn/courses/30/lessons/42842)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int carpetWidth = 0;
int carpetHeight = 0;

/**
 카펫의 가로를 carpetWidth, 세로를 carpetHeight라고 선언한다.
 노란색의 가로를 yellowWidth, 세로를 yellowHeight라고 선언한다.
 carpetWidth는 무조건 yellowWidth + 2가 된다. (감싸야 하므로)
 carpetHeight또한 carpetHeight + 2가 된다.
 carpet의 전체 격자 수는 yellow + brown이다.
 */
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int carpet = brown + yellow;
    
    for (int yellowWidth = 1; yellowWidth <= yellow; yellowWidth++) {
        if ((yellow % yellowWidth) != 0) // yellow가 yellowWidth로 떨어지지 않으면
            continue; // 다음으로 넘긴다. (yellowWidth는 무조건 yellow의 약수여야 함)
        
        // yellowWidth가 yellow의 약수인 경우
        int yellowHeight = yellow / yellowWidth; // yellowHeight는 yellow / yellowWidth이고
        carpetWidth = yellowWidth + 2; // carpetWidth는 무조건 yellowWidth + 2이다.
        
        if ((carpet % carpetWidth) != 0) // 만약 carpet이 carpetWidth로 나누어 떨어지지 않으면 다음으로 넘긴다.
            continue;
        
        // carpetWidth가 carpet의 약수인 경우
        carpetHeight = carpet / carpetWidth; // carpetHeight는 carpet / carpetWidth이고
        if (carpetHeight == yellowHeight + 2) { // carpetHeight가 yellowHeight + 2이면 맞게 구한 것
            break;
        }
    }
    
    if (carpetWidth != 0 && carpetHeight != 0) {
        answer.push_back(carpetHeight);
        answer.push_back(carpetWidth);
    }
    
    return answer;
}

int main() {
    vector<int> sol = solution(24, 24);
    
    for (int i = 0; i < sol.size(); i++) {
        cout << sol.at(i) << " ";
    }
    
    return 0;
}
