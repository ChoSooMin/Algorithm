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

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int currentWeight = 0; // 현재 도로에 올라가져있는 차 무게
    queue<int> onBridgeCar, remainDistance; // 도로에 올라가져있는 차, 차마다 남은 거리
    
    while (true)
    {
        /**
         도로 위에 올라간 차들이 각각 얼마나 더 움직여야 도로를 건너는지를 저장하는 remainDistance 큐에 접근
         */
        // 중간에 차가 빠져나가면 계산이 바뀌기 때문에 size 고정
        int size = remainDistance.size();
        // 맨 처음에는 이 for문을 돌리지 않는다.
        for (int i = 0; i < size; i++)
        {
            int length = remainDistance.front();
            remainDistance.pop();
            
            // 도로에 남은 길이가 없다면
            if (length <= 1)
            {
                // 도로에서 현재차 무게를 제외
                currentWeight -= onBridgeCar.front();
                
                // 도로에 올라가져 있는 차 제외
                onBridgeCar.pop();
                continue;
            }
            
            // 남아있다면 길이 감소 후 다시 넣기
            remainDistance.push(length - 1);
        }
        
        /**
         대기 중인 차가 1대 이상 있고, 그 차가 도로에 진입했을 때 무게를 견딜 수 있다면
         해당 차를 도로에 진입하고, currentWeight에 차의 무게를 더해준다.
         그리고 대기 큐에서 해당 차를 삭제한다.
         */
        // 벡터에 접근할 때는 .at으로 사용하는게 official !!
        // 대기큐에 차가 1대 이상 있고 도로가 무게를 견딜 수 있다면
        if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight)
        {
            // 도로에 올라가져있는 차 추가
            onBridgeCar.push(truck_weights.at(0));
            // 현재 올라가져있는 무게 추가
            currentWeight += truck_weights.at(0);
            // 남은 도로거리 추가
            remainDistance.push(bridge_length);
            // 대기차량 삭제
            truck_weights.erase(truck_weights.begin()); // vector의 원소를 삭제하는 것은 erase !!
        }
        // 시간초 증가
        answer++;
        
        // 도로에 올라가져있는 차와 대기 차가 모두 없다면 반복문 탈출
        if (onBridgeCar.size() == 0 && truck_weights.size() == 0)
            break;
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
