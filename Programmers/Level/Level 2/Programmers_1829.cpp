//
//  Programmers_1829.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/06.
//  Copyright © 2021 조수민. All rights reserved.
//
//  카카오프렌즈 컬러링북(https://programmers.co.kr/learn/courses/30/lessons/1829)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방문했는지 체크하는 벡터
vector<vector<bool>> isVisited;
// 상하좌우 움직이기 위한 배열
int dx[4];
int dy[4];
vector<vector<int>> vec;
int area; // 한 영역의 크기
int M, N;

void dfs(int x, int y, int color) {
    isVisited.at(x).at(y) = true;
    area++;
    
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (nextX < 0 || nextY < 0 || nextX >= M || nextY >= N) // 범위를 벗어나면 다음으로
            continue;
        
        // 아직 방문하지 않은 곳이고, 현재 위치의 색상과 같으면 재귀
        if (!isVisited.at(nextX).at(nextY) && (vec.at(nextX).at(nextY) == color)) {
            dfs(nextX, nextY, color);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // init
    isVisited.resize(m);
    for (int i = 0; i < isVisited.size(); i++) {
        isVisited.at(i).assign(n, false);
    }
    
    dx[0] = 0; dy[0] = -1; // 상
    dx[1] = 0; dy[1] = 1; // 하
    dx[2] = -1; dy[2] = 0; // 좌
    dx[3] = 1; dy[3] = 0; // 우
    
    area = 0;
    M = m;
    N = n;
    vec = picture;
    
    //
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // 현재 위치가 아직 방문하지 않은 곳이고, 색이 칠해져 있는 곳이면
            // 새로운 영역이 시작하는 위치라고 판단
            if (!isVisited.at(i).at(j) && (vec.at(i).at(j) > 0)) {
                area = 0;
                dfs(i, j, vec.at(i).at(j)); // 여기서 dfs는 재귀함수가 되므로, 만약 이 줄이 끝났다면 한 영역이 끝났다는 소리
                number_of_area++; // 영역의 개수를 +1 한다.
                max_size_of_one_area = max(area, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area; // 몇 개의 영역이 있는지
    answer[1] = max_size_of_one_area; // 가장 큰 영역의 크기
    return answer;
}

int main() {
    vector<int> sol = solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    cout << sol.at(0) << endl;
    cout << sol.at(1) << endl;
    
    return 0;
}
