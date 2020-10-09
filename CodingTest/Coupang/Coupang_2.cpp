//
//  Coupang_2.cpp
//  multi-target
//
//  Created by 조수민 on 2020/10/09.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arrivalSecVec;
vector<int> finalSecVec;

// 정렬하기 위한 함수
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    
    return a.second < b.second;
}

vector<string> splitWord(string str, char c)
{
    vector<string> splitString;
    string word = "";
    
    for (auto x : str)
    {
        if (x == c)
        {
            splitString.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    
    string minute = str.substr(str.size() - 2, str.size() - 1);
    splitString.push_back(minute);
    
    return splitString;
}

int getFinalTime(vector<string> splitStr)
{
    // 변수로 들어온 splitStr은 날짜, 도착시간, 소요시간을 담는 벡터
    string date = splitStr[0];
    string arrivalTime = splitStr[1];
    int runMinute = stoi(splitStr[2]);
    
    vector<string> splitDate = splitWord(date, '/');
    int month = stoi(splitDate[0]);
    int day = stoi(splitDate[1]);
    
    vector<string> splitArrivalTime = splitWord(arrivalTime, ':');
    int arrivalHour = stoi(splitArrivalTime[0]);
    int arrivalMinute = stoi(splitArrivalTime[1]);
    int arrivalSecond = stoi(splitArrivalTime[2]);
    
    vector<int> monthDay = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int getDay = 0;
    for (int i = 0; i < month - 1; i++)
    {
        getDay += monthDay[i];
    }
    getDay += day - 1;
    
    
    // 끝나는 시간을 초로 갖고 있다가 비교를 하면?
    // 도착 시간을 초로 환산 (1년 기준)
    int arrivalSec = getDay * 24 * 3600 + arrivalHour * 3600 + arrivalMinute * 60 + arrivalSecond;
    int runSec = runMinute * 60;
    int finalSec = arrivalSec + runSec; // 끝나는 시간을 초로 환산
    
    arrivalSecVec.push_back(arrivalSec);
    finalSecVec.push_back(finalSec);
    
    return finalSec;
}

int solution(int n, vector<string> customers)
{
    int answer = 0;
    
    vector<string> completeTime;
    
    for (int i = 0; i < customers.size(); i++)
    {
        getFinalTime(splitWord(customers[i], ' '));
    }
    
    for (int ele : arrivalSecVec)
        cout << ele << " ";
    cout << endl;
    for (int ele : finalSecVec)
        cout << ele << " ";
    cout<<endl;
    
    
    
    priority_queue<pair<int, int>> keyss;
    
    vector<int> key(finalSecVec.size());
    int minSec = finalSecVec[0];
    int minN = 0;
    int count = 1;
    for (int i = 0; i < finalSecVec.size(); i++)
    {
        if (count <= n)
        {
            keyss.push(make_pair(finalSecVec[i], count));
            count++;
        }
        else
        {
            
        }
    }
    
    
    
    return answer;
}

int main()
{
    int n1 = 3;
    vector<string> customers1 = { "10/01 23:20:25 30", "10/01 23:25:50 26", "10/01 23:31:00 05", "10/01 23:33:17 24", "10/01 23:50:25 13", "10/01 23:55:45 20", "10/01 23:59:39 03", "10/02 00:10:00 10" };
    int s = solution(n1, customers1);
    
    int n2 = 2;
    vector<string> customers2 = { "02/28 23:59:00 03", "03/01 00:00:00 02", "03/01 00:05:00 01" };
    
//    int s = solution(n2, customers2);
    
    return 0;
}
