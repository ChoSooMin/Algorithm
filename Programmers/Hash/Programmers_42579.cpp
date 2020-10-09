//
//  Programmers_42579.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/09.
//  Copyright © 2020 조수민. All rights reserved.
//
//  베스트앨범(https://programmers.co.kr/learn/courses/30/lessons/42579)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// vector를 정렬하기 위한 함수
bool cmp(const pair<string,int> &a, const pair<string,int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<pair<string, int>, int> m;
    map<string, int> genrePlays; // 각 장르별로 총 몇번 재생되었는지를 저장하는 map (classic : 1450, pop : 3100)
    
    for (int i = 0; i < genres.size(); i++)
    {
        m.insert(make_pair(make_pair(genres[i], i), plays[i]));
        
        if (genrePlays.find(genres[i]) == genrePlays.end()) // 장르가 아직 genrePlays에 있지 않은 경우
            genrePlays.insert(make_pair(genres[i], plays[i]));
        else
            genrePlays[genres[i]] += plays[i];
    }
    
    // (장르 : 재생수)로 저장된 벡터를 재생수 내림차순으로 정렬한다.
    vector<pair<string, int>> vec(genrePlays.begin(), genrePlays.end());
    sort(vec.begin(), vec.end(), cmp);
    
    
    for (auto elem : vec)
    {
        
    }
    
    
    for (auto elem : m)
    {
        cout << elem.first.first << " " << elem.first.second << " : " << elem.second << endl;
    }
    
    
    
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    
    vector<int> s = solution(genres, plays);
    
    return 0;
}
