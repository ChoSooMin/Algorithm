//
//  Combination_using_DFS.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/29.
//  Copyright © 2021 조수민. All rights reserved.
//  DFS 공부 - 조합 구하기

#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX 5 // 1부터 5까지 수의 순열을 구한다.

using namespace std;

//vector<int> arr;
int visit[MAX]; // (!) 방문 여부를 저장하는 배열

void print_combination() {
    for (int i = 1; i <= MAX; i++) {
        if (visit[i] == true) // 조합과 순열의 차이 (조합은 중복 제거)
            cout << i << " ";
    }
    cout << endl;
}

void combination_DFS(int index, int count) { // count개의 수를 이용해 순열을 만든다.
    if (count == 3) {
        print_combination();
        return;
    }
    
    for (int i = index; i <= MAX; i++) {
        if (visit[i] == true) // 이미 방문한 곳이라면 건너뛴다.
            continue;
        
        visit[i] = true; // 방문 표시를 남긴다.
        combination_DFS(i, count + 1);
        visit[i] = false;
    }
}

int main() {
    combination_DFS(1, 0);
    
    return 0;
}
