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
        
        // 모든 경우의 스킬트리 검색
        for(int i = 0; i < skill_trees.size(); i++) {
            vector <int> temp;
            // skill_trees 중에 skill에 없는 skill을 제외하고 temp에 저장
            for(int j = 0; j < skill_trees[i].size(); j++) { // skill_tress[i] = string
                for(int k = 0; k < skill.size(); k++) {
                    if(skill[k] == skill_trees[i][j]) {
                        temp.push_back(skill_trees[i][j]);
                    }
                }
            }
            // temp의 길이만큼 skill을 비교하여 순서가 일치하는지 확인
            int flag = 0;
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] != skill[j]) {
                    flag = 1;
                    break;
                }
            }
            // 일치하면 answer값 1증가
            if(flag == 0) {
                answer++;
            }
        }
        return answer;
}

int main() {
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
    
    return 0;
}
