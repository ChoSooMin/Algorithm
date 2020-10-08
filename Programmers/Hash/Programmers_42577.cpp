//
//  Programmers_42577.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/07.
//  Copyright © 2020 조수민. All rights reserved.
//
//  전화번호 목록(https://programmers.co.kr/learn/courses/30/lessons/42577)

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // for문을 사용해서 하나씩 다 탐색하는건 너무 시간이 오래 걸린다,,
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book.size(); j++)
        {
            if (i == j)
                continue;
            
            int pos = phone_book[j].find(phone_book[i]);
            if (pos < phone_book.size())
            {
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}

int main()
{
    vector<string> phone_book1 = { "119", "97674223", "1195524421" };
    
    cout << (solution(phone_book1) ? "true" : "false") << endl;
    
    vector<string> phone_book2 = { "123", "456", "789" };
    
    cout << (solution(phone_book2) ? "true" : "false") << endl;
    
    vector<string> phone_book3 = { "12", "123", "1235", "567", "88" };
    
    cout << (solution(phone_book3) ? "true" : "false") << endl;
    
    return 0;
}
