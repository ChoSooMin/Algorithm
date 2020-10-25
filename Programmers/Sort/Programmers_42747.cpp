//
//  Programmers_42747.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  H-index(https://programmers.co.kr/learn/courses/30/lessons/42747)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    /**
     3, 0, 6, 1, 5
     sort
     6, 5, 3, 1, 0
     */
    sort(citations.begin(), citations.end(), greater<>()); // 벡터 내림차순 정렬을 greater<>() 사용
    for (int i = 0; i < citations.size(); i++) {
        int curNum = citations.at(i);
        /**
         만약 curNum이 6일 경우, 절대 H-index가 될 수 없다.
         6번 이상 인용된 논문이 6편 이상이어야 하는데, 논문 수는 5개 이므로
         */
        if (curNum > citations.size()) {
            continue;
        }
        
        int upperCount = i + 1; // h편 이상 인용된 논문의 개수
        int lowerCount = citations.size() - upperCount; // h편 미만 인용된 논문의 개수
        
        if (upperCount >= curNum && lowerCount < curNum) {
            answer = curNum;
            break;
        }
    }
    
    return answer;
}

int main() {
    cout << solution({ 3, 0, 6, 1, 5 });
    
    return 0;
}
