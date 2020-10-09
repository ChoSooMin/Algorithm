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

// map의 키를 구조체 클래스로 갖게 하기 위해
class Music
{
    public :
    string genreName;
    int genreIndex;
    
    public :
    Music(string _genreName, int _genreIndex) : genreName(_genreName), genreIndex(_genreIndex) {}
    
    bool operator<(const Music& rhs) const
    {
        if (genreName != rhs.genreName)
            return genreName < rhs.genreName;
        
        return genreIndex < rhs.genreIndex;
    }
};

// vector를 정렬하기 위한 함수
bool cmp(const pair<string,int> &a, const pair<string,int> &b) {
    return a.second > b.second;
}

bool cmp2(const pair<Music,int> &a, const pair<Music,int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<Music, int> m;
    map<string, int> genrePlays; // 각 장르별로 총 몇번 재생되었는지를 저장하는 map (classic : 1450, pop : 3100)
    
    for (int i = 0; i < genres.size(); i++)
    {
        Music key = Music(genres[i], i);
        
        m.insert(make_pair(key, plays[i]));
        
        if (genrePlays.find(genres[i]) == genrePlays.end()) // 장르가 아직 genrePlays에 있지 않은 경우
            genrePlays.insert(make_pair(genres[i], plays[i]));
        else
            genrePlays[genres[i]] += plays[i];
    }
    
    // (장르 : 재생수)로 저장된 벡터를 재생수 내림차순으로 정렬한다.
    vector<pair<string, int>> vec(genrePlays.begin(), genrePlays.end());
    sort(vec.begin(), vec.end(), cmp);
    
    vector<pair<Music, int>> vecvec(m.begin(), m.end());
    sort(vecvec.begin(), vecvec.end(), cmp2);
    
    int count = 0;
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (auto elem : vecvec)
        {
            if (count < 2 && (elem.first.genreName == vec[i].first))
            {
                answer.push_back(elem.first.genreIndex);
                count++;
            }
        }

        count = 0;
    }
    
    return answer;
}

int main()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    
    vector<int> s = solution(genres, plays);
    
    for (auto elem : s)
    {
        cout << elem << " " << endl;
    }
    
    return 0;
}
