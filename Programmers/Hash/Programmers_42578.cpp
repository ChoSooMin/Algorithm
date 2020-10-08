//
//  Programmers_42578.cpp
//  multi-target
//
//  Created by 조수민 on 2020/10/08.
//  Copyright © 2020 조수민. All rights reserved.
//
//  위장(https://programmers.co.kr/learn/courses/30/lessons/42578)

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1; // 추후에 answer값에 *를 하기 위해 1로 초기화한다.
    
    // unordered_map을 사용해 옷의 종류와 개수를 담는 맵을 생성한다.
    unordered_map<string, int> clothesMap;
    
    // 옷의 종류와 개수를 map에 삽입
    for (int i = 0; i < clothes.size(); i++)
    {
        string key = clothes[i][1];
        
        clothesMap[key]++;
    }
    
    /**
     머리부분이 3개고, 눈부분이 2개라면
     ([머리] 입을 수 있는 경우 3가지 + 아무것도 안입는 경우 1가지) * ([눈] 입을 수 있는 경우 2가지 + 아무것도 안입는 경우 1가지) - 아무것도 안입는 경우 1가지
     를 해줘야 제대로 된 답이 나온다. (적어도 무언가 하나는 써야된다고 했으므로)
     */
    for (auto it = clothesMap.begin(); it != clothesMap.end(); it++) // map for-loop
        answer *= (it -> second + 1);
    answer--; // 아무것도 안 입는 경우 1가지
    
    return answer;
}

int main()
{
    vector<vector<string>> clothes1 = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };
    
    cout << solution(clothes1) << endl;
    
    vector<vector<string>> clothes2 = { {"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"} };
    
    cout << solution(clothes2) << endl;
    
    return 0;
}
