//
//  Programmers_42748.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/18.
//  Copyright © 2020 조수민. All rights reserved.
//
//  K번째 수(https://programmers.co.kr/learn/courses/30/lessons/42748)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getNum(vector<int> array, vector<int> command) {
    int answer = -1;
    
    // i, j, k 구하기
    int i = command.at(0);
    int j = command.at(1);
    int k = command.at(2);
    int indexI = i - 1;
    int indexJ = j - 1;
    
    // 새로운 벡터에 넣는다.
    vector<int> cuttingVector;
    for (int a = indexI; a <= indexJ; a++) {
        cuttingVector.push_back(array.at(a));
    }
    
    sort(cuttingVector.begin(), cuttingVector.end());
    
    answer = cuttingVector.at(k - 1);
    
    return answer;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); i++) {
        int getAns = getNum(array, commands.at(i));
        answer.push_back(getAns);
    }
    
    return answer;
}

int main() {
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } };
    vector<int> sol = solution(array, commands);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
