//
//  BOJ_10451.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/22.
//  Copyright © 2020 조수민. All rights reserved.
//
//  순열 사이클(https://www.acmicpc.net/problem/10451)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 [예제 입력 1]
 2
 8
 3 2 7 8 1 4 5 6
 10
 2 1 3 4 5 6 7 9 10 8
 */
int T;
vector<int> N; // N에는 {8, 10}
vector<vector<int>> numbers; // numbers에는 { { 3, 2, 7, 8, 1, 4, 5, 6 }, { 2, 1, 3, 4, 5, 6, 7, 9, 10, 8 } };


void input() {
    cin >> T;
    N.resize(T);
    numbers.resize(T);
    
    for (int i = 0; i < T; i++) {
        cin >> N.at(i);
        
        numbers.at(i).resize(N.at(i));
        for (int j = 0; j < numbers.at(i).size(); j++) {
            int number;
            cin >> number;
            numbers.at(i).at(j) = number - 1;
        }
    }
}

/**
 size = 8이 들어오고, nums = { 2, 1, 6, 7, 0, 3, 4, 5 } 일 경우
 */
int getCycleNum(int size, vector<int> nums) {
    int answer = 0;
    
    vector<bool> check;
    check.resize(size);
    check.assign(check.size(), false); // check 벡터를 모두 false로 초기화한다.
    
    queue<int> Q;
    check.at(0) = true; // index 0은 방문 (1)
    Q.push(0);
    
    /**
     check 벡터의 모든 값이 true라면 다 확인한 것이다.
     -> while문에서 빠져나와야 함
     */
    bool isTrue = true; // check벡터의 모든 값이 true인지 확인하는 flag
    int noneIndex = -1;
    bool turnEnd = false;
    
    while (true) {
//        for (int i = 0; i < check.size(); i++) {
//            cout << i << " : " << (check.at(i) ? "true" : "false") << " ";
//        }
        
        for (int i = 0; i < check.size(); i++) {
            
            
            if (check.at(i) == false) { // 하나라도 체크하지 않았으면
                noneIndex = i;
                isTrue = false; // isTrue를 false로 바꾼다. (true일 때 while문이 끝남)
                
//                cout << i << " : false" << " ";
                break;
            }
            else {
                isTrue = true;
//                cout << i << " : true" << " ";
            }
        }
//        cout << endl;
        
        if (isTrue == true) {
            break;
        }
//        cout << "noneINdex : " << noneIndex << endl;
        
        /**
         isTrue가 false라는 뜻 (다 돌지 않았다)
         */
        if (Q.empty() && noneIndex != -1) { // 큐가 비어있을 때 (하나으 ㅣ사이클이 끝)
            check.at(noneIndex) = true;
            Q.push(noneIndex);
            continue;
        }
        else { // 큐에 무언가가 있을 때
            int curFrom = Q.front(); Q.pop(); // 0 이라면
            int curTo = nums.at(curFrom); // 2
            
            // 이미 방문했다
            if (check.at(curTo) == true) {
                turnEnd = true;
                answer++;
                continue;
            }
            // 방문을 안했으면
            else {
                check.at(curTo) = true; // 방문을 했다고 바꿔주고
                Q.push(curTo);
            }
            
        }
        
//        cout << "answer : " << answer << endl;
    }
    answer++; // 왜인지 마지막 턴은 +1을 안한다,,
    
    return answer;
}

int main() {
    input();

    for (int i = 0; i < N.size(); i++) {
        cout << getCycleNum(N.at(i), numbers.at(i)) << endl;
//        cout << N.at(i) << endl;
//
//        for (int j = 0; j < numbers.at(i).size(); j++) {
//            cout << numbers.at(i).at(j) << " ";
//        }
//        cout << endl;
    }
    
//    cout << getCycleNum(10, { 1, 0, 2, 3, 4, 5, 6, 8, 9, 7 });
    
    return 0;
}
