//
//  ntech3.cpp
//  target-cpp
//
//  Created by 조수민 on 2020/09/25.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

stack<int> S;

int solution(vector<int> histogram)
{
    int answer = 12;
    
    int cur = 0; // 높이가 가장 큰 것을 담고 있는 수
    
    for (int i = 0; i < histogram.size(); i++)
    {
        cur = max(cur, histogram[i]);
    }
    
    return answer;
}


int main()
{
    
    
    return 0;
}
