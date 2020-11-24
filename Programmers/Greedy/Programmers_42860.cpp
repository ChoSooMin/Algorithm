//
//  Programmers_42860.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/11/13.
//  Copyright © 2020 조수민. All rights reserved.
//
//  조이스틱(https://programmers.co.kr/learn/courses/30/lessons/42860)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int i = 0;
    string temp(name.length(), 'A'); // temp = AAA
    while (true) {
        temp[i] = name[i];
        
        // A쪽이 더 가까운지 Z쪽이 더 가까운지 비교하여 더 가까운 쪽을 answer에 더한다.
        name[i] - 'A' > 'Z' + 1 - name[i] ? answer += 'Z' + 1 - name[i] : answer += name[i] - 'A';
        
        if (temp == name) // name이 만들어졌으면 break
            break;
        
        // 왼쪽 or 오른쪽 둘 중 어디로 이동?
        for (int move = 1; move < name.length(); move++) {
            // 오른쪽 이동이 빠를 경우 오른쪽으로 이동하고 이동횟수 반영
            if (name[(i + move) % name.length()] != temp[(i + move) % name.length()]) {
                i = (i + move) % name.length();
                answer += move;
                
                break;
            }
            // 왼쪽 이동이 빠를 경우 왼쪽으로 이동하고 이동횟수 반영
            else if (name[(i + name.length() - move) % name.length()]
                     != temp[(i + name.length() - move) % name.length()]) {
                i = (i + name.length() - move) % name.length();
                answer += move;
                
                break;
            }
        }
    }
    
    return answer;
}

int main() {
    cout << solution("JEROEN") << endl;
    
    return 0;
}
