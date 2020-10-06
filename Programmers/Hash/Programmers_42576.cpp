//
//  Programmers_42576.cpp
//  multi-target
//
//  Created by 조수민 on 2020/10/06.
//  Copyright © 2020 조수민. All rights reserved.
//
//  완주하지 못한 선수(https://programmers.co.kr/learn/courses/30/lessons/42576)

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    
    
    return answer;
}

int main()
{
    vector<string> participant1 = { "leo", "kiki", "eden" };
    vector<string> completion1 = { "eden", "kiki" };
    
    cout << solution(participa1, completion1) << endl;
    
    vector<string> participant2 = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion2 = { "josipa", "filipa", "marina", "nikola" };
    
    cout << solution(participa2, completion2) << endl;
    
    vector<string> participant3 = { "mislav", "stanko", "mislav", "ana" };
    vector<string> competion3 = { "stanko", "ana", "mislav" };
    
    cout << solution(participa3, completion3) << endl;
    
    return 0;
}
