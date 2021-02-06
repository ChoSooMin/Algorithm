//
//  BOJ_2564.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/06.
//  Copyright © 2021 조수민. All rights reserved.
//
//  경비원(https://www.acmicpc.net/problem/2564)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int w;
int h;
pair<int, int> d; // 동근이의 방향, 위치

int minDistance(pair<int, int> p) {
    int minD = 400;

    if (d.first == p.first) { // 같은 방향에 있을 경우
        minD = abs(d.second - p.second);
    }
    
    if (d.first == 3 || d.first == 4) { // 동근이의 방향이 서 or 동
        int topDistance = d.second; // 위쪽으로부터 동근이가 있는 곳까지의 거리
        int bottomDistance = h - d.second; // 동근이가 있는 곳부터 아래쪽까지의 거리

        if ((d.first == 3 && p.first == 4) || (d.first == 4 && p.first == 3)) { // 동근이와 상가가 반대편에 있을 경우
            int pTop = p.second;
            int pBottom = h - p.second;

            minD = min(topDistance + pTop + w, bottomDistance + pBottom + w);
        }
        // 동근이와 상가가 반대에 있지 않을 경우
        else if (d.first == 3 && p.first == 1) { // 동근이가 서, 상가가 북
            minD = topDistance + p.second;
        }
        else if (d.first == 4 && p.first == 1) { // 동근이가 동, 상가가 북
            minD = topDistance + (w - p.second);
        }
        else if (d.first == 3 && p.first == 2) { // 동근이가 서, 상가가 남
            minD = bottomDistance + p.second;
        }
        else if (d.first == 4 && p.first == 2) { // 동근이가 동, 상가가 남
            minD = bottomDistance + (w - p.second);
        }
    }
    else { // 동근이의 방향이 북 or 남
        int leftDistance = d.second;
        int rightDistance = w - d.second;

        if ((d.first == 1 && p.first == 2) || (d.first == 2 && p.first == 1)) { // 동근이와 상가가 반대편에 있을 경우
            int pLeft = p.second;
            int pRight = w - p.second;

            minD = min(leftDistance + pLeft + h, rightDistance + pRight + h);
            return minD;
        }

        // 동근이와 상가가 반대에 있지 않을 경우
        else if (d.first == 1 && p.first == 3) { // 동근이가 북, 상가가 서
            minD = leftDistance + p.second;
        }
        else if (d.first == 2 && p.first == 3) { // 동근이가 남, 상가가 서
            minD = leftDistance + (h - p.second);
        }
        else if (d.first == 1 && p.first == 4) { // 동근이가 북, 상가가 동
            minD = rightDistance + p.second;
        }
        else if (d.first == 2 && p.first == 4) { // 동근이가 남, 상가가 동
            minD = rightDistance + (h - p.second);
        }
    }

    return minD;
}

int main() {
    int n; // 가로, 세로, 상점의 개수
    cin >> w >> h;
    cin >> n;
    vector<pair<int, int>> v; // 각 상점의 방향, 위치가 담긴 벡터
    
    for (int i = 0; i < n; i++) {
        int direction, location;
        cin >> direction >> location;
        v.push_back({ direction, location });
    }

    int dDir, dLoc;
    cin >> dDir >> dLoc;
    d.first = dDir;
    d.second = dLoc;

    int answer = 0;
    for (int i = 0; i < v.size(); i++) {
        answer += minDistance(v.at(i));
    }

    cout << answer << endl;
    
    return 0;
}
