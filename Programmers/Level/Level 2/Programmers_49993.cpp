//
//  Programmers_49993.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/14.
//  Copyright © 2020 조수민. All rights reserved.
//
//  스킬트리(https://programmers.co.kr/learn/courses/30/lessons/49993)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    // 스킬트리에 있는 스킬들이 스킬 순서에 있는지 확인하고, 있으면 skillVector에 넣어준다.
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<char> skillVector;
        
        for (int k = 0; k < skill_trees[i].size(); k++) {
            for (int j = 0; j < skill.size(); j++) {
                if (skill[j] == skill_trees[i][k]) {
                    char cur = skill[j];
                    skillVector.push_back(cur);
                }
            }
        }
        
        bool check = true;
        for (int c = 0; c < skillVector.size(); c++) { // skillVector와 skill의 순서를 비교한다.
            if (skill[c] != skillVector[c]) { // 순서가 다를 경우, 해당 스킬 트리는 불가능한 스킬 트리이므로 check를 false로 바꿔준다.
                check = false;
            }
        }
        
        if (check)
            answer++;
    }
    
    return answer;
}

int main() {
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
    
    return 0;
}
