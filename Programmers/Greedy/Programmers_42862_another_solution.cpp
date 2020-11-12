//
//  Programmers_42862_another_solution.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/12.
//  Copyright © 2020 조수민. All rights reserved.
//
//  체육복(https://programmers.co.kr/learn/courses/30/lessons/42862)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int student[35];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    /**
     여분이 있는 학생을 1,
     도난당한 학생을 -1,
     아닌 학생은 0
     */
    for (int i : reserve)
        student[i] += 1;
    for (int i : lost)
        student[i] -= 1;
    for (int i = 1; i <= n; i++) {
        // 도난당한 학생일 경우
        if (student[i] == -1) {
            if (student[i - 1] == 1) // 앞의 학생이 여분을 갖고 있다면
                student[i - 1] = student[i] = 0; // 둘 다 0으로
            else if (student[i + 1] == 1) // 뒤의 학생이 여분을 갖고 있다면
                student[i] = student[i + 1] = 0; // 둘 다 0으로
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (student[i] != -1)
            answer++;
    }
    
    return answer;
}

int main() {
    cout << solution(3, {2, 3}, {1, 2}) << endl;
    
    return 0;
}
