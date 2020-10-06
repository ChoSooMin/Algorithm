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

/**
 처음에는 find를 써서 completion의 원소가 participant에 없는 것을 찾으려고 했는데
 완주자 명단에 동명이인이 있을 경우 너무 복잡해지는 문제가 있다.
 => sort를 써서 벡터를 정렬 후 비교하는 방식으로 해결
 */
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    // 벡터 정렬 후 비교
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < participant.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break; // break를 꼭 넣어야 한다! 그렇지 않으면 이 뒤에도 순서가 계속 맞지 않기 때문에 결국 participant의 가장 마지막 원소를 answer에 대입하게 된다.
        }
    }
    
    return answer;
}

int main()
{
    vector<string> participant1 = { "leo", "kiki", "eden" };
    vector<string> completion1 = { "eden", "kiki" };
    
    cout << solution(participant1, completion1) << endl;
    
    vector<string> participant2 = { "marina", "josipa", "nikola", "vinko", "filipa" };
    vector<string> completion2 = { "josipa", "filipa", "marina", "nikola" };
    
    cout << solution(participant2, completion2) << endl;
    
    vector<string> participant3 = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion3 = { "stanko", "ana", "mislav" };
    
    cout << solution(participant3, completion3) << endl;
    
    return 0;
}
