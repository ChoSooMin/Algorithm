//
//  BOJ_14002.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/09.
//  Copyright © 2021 조수민. All rights reserved.
//
//  가장 긴 증가하는 부분 수열 4(https://www.acmicpc.net/problem/14002)

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int a[1001];
int dp[1001];
vector<int> v; // 가장 긴 증가하는 부분 수열

int main() {
    cin >> N;
    
    fill_n(dp, 1001, 1); // dp 배열을 1로 초기화
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int ans = 1; // 가장 긴 증가하는 부분 수열의 길이
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) { // a[j]가 a[i]보다 작으면 i를 포함한 증가하는 부분 수열이 될 수 있다.
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        ans = max(ans, dp[i]);
    }
    
    // leng을 1씩 줄여나가면서,,
    int leng = ans;
    int inDp = 100;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == leng) {
            if (a[i] < inDp) {
                inDp = a[i];
                v.push_back(inDp);
                leng--;
            }
        }
    }
    
    reverse(v.begin(), v.end());
    
    cout << ans << endl;
    
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    
    return 0;
}
