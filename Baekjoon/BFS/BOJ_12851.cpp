//
//  BOJ_12851.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/09/28.
//  Copyright © 2020 조수민. All rights reserved.
//
//  숨바꼭질 2(https://www.acmicpc.net/problem/12851)

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, k;
int dist[100002]; // n에서부터 몇번만에 갈 수 있는지 저장하는 배열

int getDist()
{
    queue<int> Q;
    
    Q.push(n);
    dist[n] = 0;
    
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        
        for (int next : {cur - 1, cur + 1, 2 * cur}) // next에 차례대로 cur - 1, cur + 1, 2 * cur이 들어온다.
        {
            if (next < 0 || next > 100000)
                continue;
            if (dist[next] != -1)
                continue;
            
            dist[next] = dist[cur] + 1;
            Q.push(next);
        }
    }
    
    return dist[k];
}

int getCount()
{
    int answer = 0;
    
    int distK = getDist();
    
    if (k % 2 == 0)
    {
        for (int before : { k + 1, k - 1, k / 2 })
        {
            if (dist[before] == distK - 1)
                answer++;
        }
    }
    else if (k % 2 == 1)
    {
        for (int before : { k + 1, k - 1 })
        {
            if (dist[before] == distK - 1)
                answer++;
        }
    }
    
    return answer;
}

int main()
{
    cin >> n >> k;
    fill(dist, dist + 100001, -1); // 모든 값을 -1로
    
    cout << getDist() << endl << getCount() << endl;
    
    return 0;
}
