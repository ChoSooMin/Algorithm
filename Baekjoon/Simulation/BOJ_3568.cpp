//
//  BOJ_3568.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/01/13.
//  Copyright © 2021 조수민. All rights reserved.
//
//  iSharp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // input
    string str;
//    cin >> str; // 공백이 포함된 문자열을 입력받을 땐 이렇게 하면 안된다!! cin은 공백이 문자열이 끝나는 단위로 보기 때문에, 공백을 만나면 문자열 입력이 끝났다고 생각한다!
    getline(cin, str); // 공백이 포함된 문자열을 입력받을 땐 getline을 사용하면 된다!!!
    
    // 공백을 기준으로 잘라준다.
    vector<string> splitByGap = split(str, ' '); // { "int&", "a*[]&,", "b,", "c*;" }
    string variableType = splitByGap.at(0); // 가장 첫번째에 있는 인자는 변수형이다.
    
    vector<string> answer;
    for (int i = 1; i < splitByGap.size(); i++) {
        string curStr = splitByGap.at(i);
        string variable = variableType;
        
        for (int i = curStr.length() - 1; i >= 0; i--) {
            if (curStr[i] == ';' || curStr[i] == ',' || curStr[i] == '[')
                continue;
            
            if (curStr[i] == ']') {
                variable += "[]";
                continue;
            }
            
            int ascii = (int)curStr[i];
            if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
                variable += " ";
                variable += curStr[i];
                variable += ";";
                answer.push_back(variable);
                break;
            }
            
            variable += curStr[i];
        }
    }
    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer.at(i) << endl;
    }
    
    return 0;
}
