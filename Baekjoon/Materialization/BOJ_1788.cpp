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

int fibonacci[10000001];

int getFibonacci(int n)
{
    if (n == 0) // 0일 때
        return fibonacci[0];
    else if (n > 0) // 양수일 때
        return fibonacci[n];
    else // 음수일 때
    {
        int abs = n * (-1);
        
        if (abs % 2 == 0) // 절대값이 짝수일 때
            return fibonacci[abs] * (-1);
        else // 절대값이 홀수일 때
            return fibonacci[abs];
    }
}

int main()
{
    int n;
    
    // fibonacci 배열에 양수일 때의 피보나치 값을 구해서 넣어둔다.
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    
    for (int i = 2; i < 1000000; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    
    cin >> n; // n을 입력받는다.
    
    // 출력
    if (n == 0)
        cout << 0 << endl << getFibonacci(n) % MOD << endl;
    else if (n > 0)
        cout << 1 << endl << getFibonacci(n) % MOD << endl;
    else
    {
        cout << -1 << endl;
        
        int fibo = getFibonacci(n);
        if (fibo < 0)
            cout << (getFibonacci(n) * (-1)) % MOD << endl;
        else
            cout << getFibonacci(n) % MOD << endl;
    }
        
    return 0;
}

