//
//  BOJ_1788.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/07/13.
//  Copyright © 2020 조수민. All rights reserved.
//
//  피보나치 수의 확장(https://www.acmicpc.net/problem/1788)

#include <iostream>
#include <stdio.h>

#define MOD 1000000000

using namespace std;

int fibonacci[1000001];

int getFibonacci(int n)
{
    if (n == 0) // 0일 때
        return fibonacci[0];
    else if (n > 0) // 양수일 때
        return fibonacci[n];
    else // 음수일 때
    {
        if (n % 2 == 0) // 2로 나누어 떨어질 때 (절대값이 짝수일 때)
            return fibonacci[n * (-1)] * (-1);
        else // 2로 나누어 떨어지지 않을 때 (절대값이 홀수일 때)
            return fibonacci[n * (-1)];
    }
}

int main()
{
    int n;
    
    // fibonacci 배열에 양수일 때의 피보나치 값을 구해서 넣어둔다.
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for (int i = 2; i <= 1000000; i++)
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD; // 1) 여기서 MOD로 나눴는데
    
    cin >> n; // n을 입력받는다.
    
    // 출력
    if (n > 0) // n이 양수일 때
        cout << 1 << endl;
    else if (n == 0) // n이 0일 때
        cout << 0 << endl;
    else // n이 음수일 때
    {
        if (n % 2 == 0) // n이 2로 나누어 떨어지면 피보나치 값이 음수이다.
            cout << -1 << endl;
        else // n이 2로 나누어 떨어지지 않으면 피보나치 값이 양수이다.
            cout << 1 << endl;
    }
    cout << fibonacci[abs(n)] % MOD << endl; // 2) 왜 여기서 MOD로 또 나누지..?
    
        
    return 0;
}

// 이게 맞는 답인데 의문점 1 & 2
