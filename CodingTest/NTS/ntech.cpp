//
//  ntech.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/25.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int day[366];

int solution(vector<vector<int>> flowers) {
    int answer = 0;
    
    for (int i = 0; i < flowers.size(); i++)
        for (int j = 0; j < 2; j++)
        {
            int start = flowers[i].front(); // 시작 날짜
            int end = flowers[i].back(); // 끝나는 날짜
            
//            fill(day + start, day + end, -1);
            for (int i = start; i < end; i++)
            {
                day[i] += 1;
            }
        }
   
    for (int i = 0; i < 366; i++)
        if (day[i] >= 1)
            answer++;
    
    return answer;
}

int main()
{
    int s = solution({ {2, 5}, {3, 7}, {10, 11} });
    
    cout << s;
    
    return 0;
}
