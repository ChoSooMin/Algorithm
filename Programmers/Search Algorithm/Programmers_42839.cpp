//
//  Programmers_42839.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/26.
//  Copyright © 2020 조수민. All rights reserved.
//
//  소수 찾기(https://programmers.co.kr/learn/courses/30/lessons/42839)

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 소수 판별 함수
bool isPrime(int n) {
    if (n == 2) // 2는 소수이다
        return true;

    if (n == 1) // 1은 소수가 아니다
        return false;
    
    if (n % 2 == 0) // 소수는 다 홀수이므로, 짝수는 소수가 아니다
        return false;
    
    /**
     앞에서 짝수는 다 걸러줬으므로,
     홀수로만 나눠본다.
     n보다 작은 모든 홀수로 나눴을 때, 나누어 떨어지지 않는다면
     소수이다
     */
    for (int i = 3; i < n; i += 2) {
        if (n % i == 0) // 나누어떨어짐 = 소수가 아니다
            return false;
    }
    
    return true;
}

/**
 algorithm 헤더에 있는 next_permutation 함수를 사용하면 순열을 쉽게 구할 수 있다.
 */
int solution(string numbers) {
    int answer = 0;
    
    // 순열 구하기
    vector<int> newNums;
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            newNums.push_back(stoi(numbers.substr(0, i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    // newNums 벡터의 중복을 제거하기 위해 unique와 erase를 사용한다.
    // 이 때 주의점은, sort를 한 후 사용해줘야 중복된 값이 제대로 삭제된다.
    sort(newNums.begin(), newNums.end());
    newNums.erase(unique(newNums.begin(), newNums.end()), newNums.end());
    
    // 소수인지 판별, 소수가 맞으면 answer + 1
    for (int i = 0; i < newNums.size(); i++) {
        if (isPrime(newNums.at(i)))
            answer++;
    }
    
    return answer;
}

int main() {
    cout << solution("17") << endl;
    
    return 0;
}
