//
//  Programmers_42628.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/18.
//  Copyright © 2020 조수민. All rights reserved.
//
//  이중우선순위큐(https://programmers.co.kr/learn/courses/30/lessons/42628)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

// 타 언어는 문자열을 나누는 split 함수가 존재하지만 c++은 존재하지 않는다. (직접 만들어야 함)
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string tmp;
    
    while (getline(ss, tmp, delimiter)) {
        answer.push_back(tmp);
    }
    
    return answer;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, less<int>> pq; // 내림차순으로 정렬
    
    /**
     먼저 연산들에 접근
     */
    for (int i = 0; i < operations.size(); i++) {
        string operation = operations.at(i); // ex) I 16
        vector<string> splitOperation = split(operation, ' ');
        
        string operator1 = splitOperation.at(0);
        int num = stoi(splitOperation.at(1));
        
        if (operator1 == "I") { // 큐에 숫자 삽입
            pq.push(num);
        }
        else if (operator1 == "D") { // 삭제
            int QSize = pq.size();
            int turnSize = pq.size();
            
            if (QSize == 0) { // 빈 큐에 삭제 연산일 경우, 해당 연산은 무시
                continue;
            }
            
            if (num == 1) { // 최댓값 삭제
                pq.pop(); // 내림차순으로 정렬되어 있으므로 top 값을 pop 하면 된다.
            }
            else if (num == -1) { // 최솟값 삭제
                priority_queue<int> anotherPQ; // 최솟값이 아닌 값들은 이 큐에 넣어둔다.
                
                while (QSize != 0) {
                    int first = pq.top();
                    pq.pop();
                    
                    if (turnSize == 1) { // 맨 마지막 값이라면 최솟값이므로
                        break; // 끝!
                    }
                    else { // 맨 마지막 값이 아니라면
                        anotherPQ.push(first); // anotherPQ에 넣어둔다.
                    }
                    
                    turnSize--;
                }
                
                // 최솟값 삭제 후에 anotherPQ에 있는 값들을 다시 pq에 넣는다.
                while (!anotherPQ.empty()) {
                    int aa = anotherPQ.top(); anotherPQ.pop();
                    pq.push(aa);
                }
            }
        }
        
        
    }
    
    if (pq.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq.top());

        priority_queue<int, vector<int>, greater<int>> greaterQ;
        while (!pq.empty()) {
            int a = pq.top(); pq.pop();
            greaterQ.push(a);
        }
        answer.push_back(greaterQ.top());
    }
    

    return answer;
}

int main() {
    vector<string> op1 = { "I 16", "D 1" };
    vector<string> op2 = { "I 7", "I 5", "I -5", "D -1" };
    
    cout << solution(op1).at(0) << solution(op1).at(1) << endl;
    cout << solution(op2).at(0) << solution(op2).at(1) << endl;
    
    return 0;
}
