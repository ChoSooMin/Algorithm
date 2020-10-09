//
//  Coupang_1.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/09.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int createN(int n, int b)
{
    vector<int> v;
    
    while(1)
    {
        v.push_back(n % b); // 해당 진수로 나눈 나머지를 vector에 넣음
        n /= b;
        if (n == 0)
            break;
    }
    
    // 벡터를 다시 돌려야함
    vector<int> backV;
    vector<int>::reverse_iterator iter;
    for (iter = v.rbegin(); iter != v.rend(); iter++)
        backV.push_back(*iter);
    
    int multi = 1;
    for (int i = 0; i < backV.size(); i++)
        if (backV[i] != 0)
            multi *= backV[i];
    
    return multi;
}

vector<int> solution(int N)
{
    vector<int> answer;
    
    int max = 0;
    int maxK = -1;
    
    for (int i = 2; i <= 9; i++)
    {
        if (max <= createN(N, i))
        {
            max = createN(N, i);
            maxK = i;
        }
    }
    
    answer.push_back(maxK);
    answer.push_back(max);
    
    return answer;
}

int main()
{
//    cout << createN(10, 6) << endl;
    vector<int> s = solution(10);
    for (int ele : s)
        cout << ele << " ";
    
    return 0;
}
