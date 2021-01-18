//
//  SWEA_1984.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/18.
//  Copyright © 2021 조수민. All rights reserved.
//
//  중간 평균값 구하기(https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pw_-KAdcDFAUq&categoryId=AV5Pw_-KAdcDFAUq&categoryType=CODE)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> answer;
    for (int i = 1; i <= t; i++) {
        vector<int> t_case;
        
        for (int j = 0; j < 10; j++) {
            int num;
            cin >> num;
            
            t_case.push_back(num);
        }
        
        sort(t_case.begin(), t_case.end());
        
        double sum = 0;
        for (int j = 1; j <= 8; j++) {
            sum += t_case.at(j);
        }
        
        int round_num = round(sum / 8);
        answer.push_back(round_num);
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << "#" << (i + 1) << " ";
        cout << answer.at(i) << endl;
    }
    
    return 0;
}
