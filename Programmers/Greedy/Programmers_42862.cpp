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
    map<int, int> lostStudents; // 도난당한 학생
    map<int, int> reserveStudents; // 여분이 있는 학생

    // lostStudents에 (학생번호, -1)로 넣어준다.
    for (int i = 0; i < lost.size(); i++) {
        lostStudents.insert(make_pair(lost.at(i), -1));
    }
    
    // reserveStudents에 (학생번호, -1)로 넣어준다.
    for (int i = 0; i < reserve.size(); i++) {
        reserveStudents.insert(make_pair(reserve.at(i), -1));
    }
    
    // 도난당한 학생이 여분이 있는 학생에 포함하는지 확인하고, 만약에 포함되면 여분이 있는 학생 map과 도난당한 학생 map에서 해당 학생을 빼준다.
    for (int i = 0; i < lost.size(); i++) {
        if (reserveStudents.find(lost.at(i))->second == -1) {
            reserveStudents.erase(lost.at(i));
            lostStudents.erase(lost.at(i));
        }
    }
    
    /**
     students에 모두 넣어준다.
     도난당한 학생은 (학생번호, 0)으로,
     여분이 있는 학생은 (학생번호, 2)로,
     둘 다 아닌 학생은 (학생번호, 1)로 -> 이건 안해도 되나?
     */
    for (auto it = lostStudents.begin(); it != lostStudents.end(); it++) {
        students.insert(make_pair(it->first, 0));
    }
    for (auto it = reserveStudents.begin(); it != reserveStudents.end(); it++) {
        students.insert(make_pair(it->first, 2));
    }
    for (int i = 1; i <= n; i++) {
        if (students.find(i)->second != 2 || students.find(i)->second != 0) {
            students.insert(make_pair(i, 1));
        }
    }
    
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << "index : " << it->first << " 개수 : " << it->second << endl;
    }
    
    // 여분이 있는 애들 앞 뒤를 봐서 도난 당한 애들이 있는지 확인
    for (auto it = reserveStudents.begin(); it != reserveStudents.end(); it++) {
        int cur = it->first;
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
        if (it->second >= 1) {
            answer++;
        }
    }
    
    return answer;
}

int main() {
    cout << solution(3, {2, 3}, {1, 2}) << endl;
    
    return 0;
}
