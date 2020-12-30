//
//  Programmers_12973.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/29.
//  Copyright © 2020 조수민. All rights reserved.
//
//  짝지어 제거하기(https://programmers.co.kr/learn/courses/30/lessons/12973)

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        // 스택이 비어있거나 이전에 스택 top의 값이 현재 s[i]와 다르면(중복이 아니면) push
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else // 스택 top의 값이 현재 s[i]와 같다면 top에 있는 값을 pop한다. (중복일 경우)
            st.pop();
    }
    
    // 스택이 비어있다면 문자열을 모두 제거할 수 있음 -> 1
    if (st.empty())
        return 1;

    return answer;
}

int main() {
    cout << solution("cdcd") << endl;
    
    return 0;
}
