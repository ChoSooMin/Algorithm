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
int dist[100001]; // n에서부터 몇번만에 갈 수 있는지 저장하는 배열
int cnt[100001]; // 현재 인덱스까지 올 수 있는 방법이 몇개인지 담는 배열
bool check[100001]; // 방문했는지 여부

void getAnswer()
{
    queue<int> Q;
    
    Q.push(n);
    dist[n] = 0;
    check[n] = true; // 방문여부
    cnt[n] = 1;
    
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        
        for (int next : {cur - 1, cur + 1, 2 * cur}) // next에 차례대로 cur - 1, cur + 1, 2 * cur이 들어온다.
        {
            if (next < 0 || next > 100000)
                continue;
            
            /**
             숨바꼭질1 코드와 다른 부분
             if (dist[next] != -1)
                 continue;
             이미 방문을 했어도 next의 위치에 가는 경로가 최단경로와 같으면 cnt를 늘려줘야 한다.
             그래서 이 코드는 빼야함!
             */
            
            if (check[next] == false) // 아직 방문하지 않은 곳일 때
            {
                // 여기는 이전의 코드와 같다.
                dist[next] = dist[cur] + 1;
                Q.push(next);
                
                check[next] = true; // 방문했다는 표시를 남기고
                cnt[next] = cnt[cur]; // next까지 가는 방법의 수는 cur까지 가는 방법의 수와 같다.
            }
            else if (dist[next] == dist[cur] + 1) // 이미 방문했고, 현재를 거쳐 가는 경우?
            {
                cnt[next] += cnt[cur];
            }
        }
    }
    
    cout << dist[k] << endl << cnt[k];
}
    
    
int main()
{
    cin >> n >> k;
    fill(dist, dist + 100000, -1); // 모든 값을 -1로
    
    getAnswer();
    
    return 0;
}
