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
#define ABS(X) ((X) > 0 ? (X) : (X) * -1)

using namespace std;

int arrp[1000001];
int n;

int main()
{
    // fibonacci 배열에 양수일 때의 피보나치 값을 구해서 넣어둔다.
    arrp[0] = 0;
    arrp[1] = 1;
    
    for (int i = 2; i <= 1000000; i++)
        arrp[i] = (arrp[i - 1] + arrp[i - 2]) % MOD;
    
    cin >> n; // n을 입력받는다.
    
    // 출력
    if (n > 0)
        cout << 1 << endl;
    else if (n == 0)
        cout << 0 << endl;
    else
    {
        if (n % 2 == 0)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
    cout << arrp[ABS(n)] % MOD << endl;
        
    return 0;
}

