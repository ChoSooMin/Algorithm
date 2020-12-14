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

bool isOkay(string skill, string skillTree) {
    bool ans = false;
    
    vector<int> positions;
    
    for (int i = 0; i < skillTree.length(); i++) {
        char curSkill = skillTree[i];

        if (skill.find(curSkill) != string::npos) {
            int pos = skill.find(curSkill);
            
            positions.push_back(pos);
        }
    }
    
    if (positions.size() != 0) {
        vector<int>::iterator iter;
        iter = find(positions.begin(), positions.end(), 0);
        if (iter == positions.end())
            return false;
    }
    
    vector<int> beforePositions;
    beforePositions.assign(positions.begin(), positions.end());
    sort(positions.begin(), positions.end());
    
    if (positions == beforePositions) {
        ans = true;
    }
    
    return ans;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (int i = 0; i < skill_trees.size(); i++) {
        string curSkillTree = skill_trees.at(i);

        if (isOkay(skill, curSkillTree)) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
    
    return 0;
}
