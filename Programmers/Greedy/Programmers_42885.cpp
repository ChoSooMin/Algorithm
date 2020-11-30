//
//  Programmers_42885.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/27.
//  Copyright © 2020 조수민. All rights reserved.
//
//  구명보트(https://programmers.co.kr/learn/courses/30/lessons/42885)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0; // 보트가 나간 횟수
    int cnt = 0; // 나간 사람의 수
    int begin = 0; // 뒤 인덱스
    int end = 1; // 앞 인덱스
    
    // 정렬
    sort(people.begin(), people.end());
    
    while(true) {
        // 제일 뒤의 무게를 넣기
        int first = people.at(people.size() - end++);
        cnt++; // 한 명 보트에 태움
        
        // 최대 제한에서 제일 무거운 사람을 뻈을 때 나머지 자리에 가장 가벼운 사람이 탈 수 있다면
        if (limit - first >= people.at(begin)) {
            // 앞사람 인덱스 증가 & 보트에 탄 사람 추가
            begin++;
            cnt++;
        }
        
        // 보트 나간 횟수 증가
        answer++;
        
        // 보트를 타고 나간 사람이 총인원보다 같거나 많으면 반복문 종료
        if (cnt >= people.size())
            break;
    }
    
    return answer;
}

int main() {
    cout << solution({ 30, 80, 40, 70, 20, 50}, 100) << endl;
    cout << solution({ 70, 80, 50}, 100) << endl;
    
    return 0;
}
