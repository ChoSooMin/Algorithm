//
//  BOJ_10451_using_recurrence.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/23.
//  Copyright © 2020 조수민. All rights reserved.
//
//  순열 사이클(https://www.acmicpc.net/problem/10451)
//  재귀 사용 [참고] https://kyunstudio.tistory.com/125

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
 나는 vector를 사용했는데 이 답은 배열을 사용했다.
 */
int arr[1001];
bool visited[1001];

// DFS 구현
void DFS(int i) {
    if (visited[i]) // 방문했으면
        return; // 끝
    
    // 방문하지 않았으면
    visited[i] = true;
    DFS(arr[i]); // 재귀
}

int findCycles(int N) {
    // 초기화
    memset(visited, false, sizeof(visited)); // 배열의 모든 값을 false로 초기화한다. (memset 함수 사용!!)
    
    int count = 0;
    /**
     내가 푼 풀이는 입력받은 값을 넣을 때 -1 했는데
     그럴 필요 없이 index를 1부터 시작하면 되는 거였다,,!
     */
    for (int i = 1; i <= N; i++) {
        // 배열 중에 아직 선택이 안된 것이 있다면
        if (!visited[i]) {
            // DFS를 해서 사이클 고리를 찾아낸다.
            DFS(i);
            // 그리고 사이클 1개 추가
            count++;
        }
    }
    
    return count; // 사이클 개수 반환
}

int main() {
    int T, N;
    cin >> T;
    
    while (T--) {
        cin >> N;
        
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        
        cout << findCycles(N) << endl; // 사이클 개수 찾기
    }
    
    return 0;
}
