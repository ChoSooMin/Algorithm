//
//  Programmers_42584.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/09.
//  Copyright © 2020 조수민. All rights reserved.
//
//  주식가격(https://programmers.co.kr/learn/courses/30/lessons/42584)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    
    for (int i = 0; i < prices.size(); i++)
        for (int j = i + 1; j < prices.size(); j++)
        {
            answer[i]++;
            
            if (prices[i] > prices[j])
                break;
        }
    return answer;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
    
    vector<int> s = solution(prices);
    
    for (int i : s)
        cout << i << " " << endl;
    
    return 0;
}
