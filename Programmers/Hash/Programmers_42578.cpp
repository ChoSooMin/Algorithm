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
    int answer = 0;
    
    unordered_map<string, int> clothesMap;
    
    for (int i = 0; i < clothes.size(); i++)
    {
        string key = clothes[i][1];
        string value = clothes[i][0];
        
        if (clothesMap.end() == clothesMap.find(key))
            clothesMap.insert(make_pair(key, 1));
        else
            clothesMap[key]++;
    }
    
    int multi = 1;
    int count = 0;
    
    for (auto current : clothesMap)
    {
        cout << current.first << " " << current.second << endl;
        count++;
        answer += current.second;
        multi *= current.second;
    }
    
    if (count != 1)
        answer += multi;
    
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
