//
//  Programmers_42862.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/11.
//  Copyright © 2020 조수민. All rights reserved.
//
//  체육복(https://programmers.co.kr/learn/courses/30/lessons/42862)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    map<int, int> students;
    
//    map<int, int> lostStudents;
    for (int i = 0; i < lost.size(); i++) {
//        lostStudents.insert(make_pair(lost.at(i), 1));
        students.insert(make_pair(lost.at(i), 0)); // 도난
    }
    
    //
    for (int i = 0; i < reserve.size(); i++) {
        students.insert(make_pair(reserve.at(i), 2)); // 여분이 있는 경우
//        int cur = reserve.at(i);
//        int curBefore = cur - 1;
//        int curAfter = cur + 1;
        
        // 존재하면?
//        if (lostStudents.find(curBefore) -> second
//            == 1 || lostStudents.find(curAfter) -> second) {
//
//        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (students.find(i)->second != 0 || students.find(i)->second != 2) {
            students.insert(make_pair(i, 1));
        }
    }
    // 여분이 있는 애들ㄹ
    for (int i = 0; i < reserve.size(); i++) {
        int cur = reserve.at(i);
        int curBefore = cur - 1;
        int curAfter = cur + 1;
        
        
        if (students.find(curBefore)->second == 0) {
            students.find(curBefore)->second += 1;
            students.find(cur)->second -= 1;
            
            continue;
        }
        if (students.find(curAfter)->second == 0) {
            students.find(curAfter)->second += 1;
            students.find(cur)->second -= 1;
            
            continue;
        }
    }
    
    
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << "index : " << it->first << " 개수 : " << it->second << endl;
    }
    cout << endl;
    
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->second >= 1) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    cout << solution(3, {3}, {1}) << endl;
    
    return 0;
}
