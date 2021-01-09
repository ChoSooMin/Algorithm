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
vector<int> lis; // 가장 긴 증가하는 부분 수열

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
    
    // 변수 leng에 ans 값을 담고, for문을 통해 dp 배열에 접근한다.
    // dp 배열에서 dp[i]가 leng과 같은 경우, a[i]는 LIS의 원소에 속한다는 뜻이므로,
    // lis 벡터에 넣어준다.
    int leng = ans;
    
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == leng) {
            lis.push_back(a[i]);
            leng--;
        }
    }
    
    reverse(lis.begin(), lis.end()); // dp 배열을 뒤에서부터 접근했으므로, lis 벡터를 reverse 시켜준다.
    
    cout << ans << endl;
    
    for(int i = 0; i < lis.size(); i++) {
        cout << lis.at(i) << " ";
    }
    
    return 0;
}
