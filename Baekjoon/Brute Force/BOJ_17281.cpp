//
//  BOJ_17281.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/22.
//  Copyright © 2021 조수민. All rights reserved.
//
//  ⚾(https://www.acmicpc.net/problem/17281)

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, ans;
int order[9] = { 3, 0, 1, 2, 4, 5, 6, 7, 8 };
int norder[9];
int score[10][55];
int arr[1515];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> score[j][i]; // i번째 이닝에 타자 j가 치는 점수
        }
    }
    
    do {
        // 각 순열을 norder에 저장해두기
        for (int i = 0; i < 9; i++)
            norder[order[i]] = i;
            
        // 매 순열, 얻는 점수를 cnt에 저장한다.
        int cnt = 0, pos = 0;

        for (int i = 0; i < N; i++) { // N 이닝동안
            int out = 0; // 각 이닝 초기 out 값은 0으로 시작
            int prev = pos; // 이닝이 끝나면 다음 이닝은 pos번째 타자부터 시작한다.

            while (out != 3) { // 3 아웃인 경우 다음 이닝으로 넘어간다.
                int num = score[norder[pos % 9]][i]; // 현재 타자의 값을 가져온다.

                if (num == 0) // 현재 타자가 아웃을 칠 경우
                    out += 1; // out + 1

                arr[pos++] = num;
            }

            for (int j = prev; j < pos; j++) {
                if (!arr[j]) // 만약 내가 아웃이라면 다음으로 넘긴다
                    continue;

                for (int k = j + 1; k <= j + 3, k < pos; k++) // 1루, 2루, 3루, 홈으로 이루어져있으므로 나는 내 뒤에 3명에게 영향을 받는다
                    arr[j] += arr[k];
            }
        }

        for (int j = 0; j < pos; j++) {
            if (arr[j] >= 4) // arr값이 4보다 크거나 같다면 해당 주자가 홈으로 들어왔다는 소리이므로 cnt + 1 해준다.
                cnt += 1;
        }

        ans = max(ans, cnt);
        
    } while (next_permutation(order + 1, order + 9)); // int형 배열 순열 돌리기 (1번 타자는 4번째에 치기로 정해져있으므로, order + 1부터 돌린다)
    
    cout << ans << "\n";
    
    return 0;
}
