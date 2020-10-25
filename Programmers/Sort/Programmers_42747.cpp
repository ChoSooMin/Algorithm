//
//  Programmers_42747.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  H-index(https://programmers.co.kr/learn/courses/30/lessons/42747)
//  [참고] https://m.blog.naver.com/PostView.nhn?blogId=promarketyj&logNo=221434899288&categoryNo=22&proxyReferer=https:%2F%2Fwww.google.com%2F

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
        
        if (citations.at(i) <= answer)
            break;
        answer++;
    }
    
    return answer;
}

int main() {
    cout << solution({ 3, 0, 6, 1, 5 });
    
    return 0;
}
