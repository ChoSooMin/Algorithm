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

using namespace std;

int p[50001];

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // limit에서 본인의 무게를 빼고 (1) 그 값보다 작거나 같은 애를 찾으면?
    // 시간복잡도 괜찮나?
    for (int i = 0; i < people.size(); i++) {
        p[i] = people.at(i);
    }
    
    for (int i = 0; i < people.size(); i++) {
        int cur = p[i];
        
        int max = 0;
        int maxIndex = -1;
        
        if (cur == 0) // 현재 위치의 사람이 이미 구조된 후라면 다음으로 넘긴다.
            continue;
        
        int rest = limit - cur;
        
        if (i != people.size() - 1) {
            for (int j = i + 1; j < people.size(); j++) {
                int next = p[j];
                
                if (next == 0) // 마찬가지로 구조된 후라면 다음으로
                    continue;
                if (next > rest) // 남은 무게 제한보다 몸무게가 많이 나가면 다음으로
                    continue;
                
                // 구조 X && 남은 무게 제한에 충족
                if (max < next) {
                    max = next;
                    maxIndex = j;
                }
            }
            
            if (max != 0 && maxIndex != -1) { // 맞는 짝을 찾았을 때
                answer++;
                
                p[i] = 0;
                p[maxIndex] = 0;
            }
        }
    }
    
    for (int i = 0; i < people.size(); i++) {
        if (p[i] == 0)
            continue;
        
        answer++;
    }
    
    return answer;
}

int main() {
    cout << solution({ 30, 80, 40, 70, 20, 50}, 100) << endl;
    cout << solution({ 70, 80, 50}, 100) << endl;
    
    return 0;
}
