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
    
    // 정렬한 후
    sort(phone_book.begin(), phone_book.end());
    
    /**
     순서대로 현재 위치의 값을 뒤의 값에서 find함수를 사용해 찾는다.
     만약 찾은 위치가 0이라면 현재 값이 뒤의 값의 접두어라는 뜻이므로 answer를 false로 바꿔준다.
     */
    for (int i = 0; i < phone_book.size(); i++)
    {
        if (i == phone_book.size() - 1)
            break;
        
        unsigned long point = phone_book[i + 1].find(phone_book[i]);
        if (point == 0)
            answer = false;
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
