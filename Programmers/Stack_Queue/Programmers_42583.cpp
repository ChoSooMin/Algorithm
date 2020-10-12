//
//  Programmers_42583.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/10.
//  Copyright © 2020 조수민. All rights reserved.
//
//  다리를 지나가는 트럭(https://programmers.co.kr/learn/courses/30/lessons/42583)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 예은 풀이 : head랑 tail을 만들어 사용 (queue)
 queue에서 tail은 마지막을 가리키는 게 아니라 마지막 인덱스 - 1을 가리킨다.
 처음에는 head = tail = 0으로 초기화해 아무것도 없다고 표시
 answer는 반복문이 실행될 때마다 +1 되어야 한다.
 */
int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    
    // truck_weights.size()만큼의 트럭 수가 있다.
    // truck_weights[i]는 각 bridge_length번 있어야한다?
    queue<int> standbyQ; // 대기 중인 트럭들의 index를 저장하는 큐
    for (int i = 0; i < truck_weights.size(); i++)
    {
        standbyQ.push(i);
    }
    
    queue<pair<int, int>> bridgeQ; // 다리 위에 몇 번 트럭이 얼마나 있는지 저장하는 큐 <1, 1>이라면 1번 트럭이 1초동안 큐에 있었다는 뜻
    int curWeight = 0; // 다리 위에 있는 트럭들의 무게의 합
    int i = standbyQ.front();
    
    // 먼저 대기중인 트럭 중 맨 처음 트럭이 진입
    bridgeQ.push(make_pair(i, 1));
    curWeight += truck_weights[i];
    int time = 1;
    standbyQ.pop();
    i = standbyQ.front();
    /**
     0초일 때는 다리 위에 아무것도 없다.
     1초일 때
     다리 길이만큼 트럭의 개수가 진입할 수 있다. 진입한 트럭의 개수 = q.size()
     &&
     진입한 트럭 앞에서부터의 합이 weight를 넘지 않는 선에서 진입 가능
     */
    while (!bridgeQ.empty() && !standbyQ.empty()) // 다리를 건너고 있는 트럭과 대기 트럭이 아무것도 없으면 모든 트럭이 다 건넌 것이므로 반복문이 끝나고 마지막 time값이 answer가 된다.
    {
        // 큐의 맨 앞의 second값이 bridge_length만큼 큐에 있었다면 다리를 다 건넜다는 뜻이므로
        auto cur = bridgeQ.front();
        if (cur.second == bridge_length)
            bridgeQ.pop(); // pop하고
        

        /**
         큐는 특정 위치의 값을 수정할 수 없는데 ,, 큐 말고 다른걸 써야하나 ,,?ㅠ
         */
        
        else
        {
            for (int i = 0; i < bridgeQ.size(); i++)
            {
                
            }
        }
        
        if ((bridgeQ.size() < bridge_length) && (curWeight + truck_weights[i] <= weight))
        {
            
        }
        else
        {
            
        }
        
        time++;
    }
    
    return answer;
}

int main()
{
    int bridge_length1 = 2;
    int weight1 = 10;
    vector<int> truck_weights1 = { 7, 4, 5, 6 };
    
    solution(bridge_length1, weight1, truck_weights1);
    
    return 0;
}
