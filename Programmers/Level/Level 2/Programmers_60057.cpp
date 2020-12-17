//
//  Programmers_60057.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/12/16.
//  Copyright © 2020 조수민. All rights reserved.
//
//  문자열 압축(https://programmers.co.kr/learn/courses/30/lessons/60057)

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    if (s.length() == 1) // 문자열의 크기가 1이면 return 1
        return 1;
    
    for (int i = 1; i <= s.length() / 2; i++) { // 문자열 압축 길이
        int count = 1;
        string firstStr = s.substr(0, i); // position 0부터 자른 문자열
        string compareStr, compressStr;
        
        for (int j = i; j < s.length(); j+= i) { // 그 다음 압축할 범위는 i부터 시작한다 (0 + i)
            compareStr = s.substr(j, i); // 비교할 문자열
            
            if (!(firstStr.compare(compareStr))) // 같으면 count 증가
                count++;
            else { // 다르면
                if (count == 1) { // 문자열이 압축되지 못함
                    compressStr += firstStr;
                    firstStr = compareStr; // 다음 비교를 위해 firstStr에 compareStr을 넣어준다.
                }
                else { // 압축된 문자열이 있을 경우
                    compressStr += to_string(count) + firstStr;
                    firstStr = compareStr;
                    count = 1; // count를 1로 초기화
                }
            }
            
            // 마지막 잘려진 str을 위해
            if (j + i >= s.length()) { // 마지막에 substr 기준을 초과한 경우
                if (count != 1) { // 앞의 str과 같다는 뜻
                    compressStr += to_string(count) + firstStr;
                    break;
                }
                else { // 앞의 str과 다르다
                    compressStr += s.substr(j); // j부터 끝까지 자른걸 compressStr에 추가해준다.
                    break;
                }
            }
        }
        
        answer = (answer > compressStr.length()) ? compressStr.length() : answer; // 더 작은 값을 비교해서 answer에 더 작은 값을 넣는다.
    }
    
    return answer;
}

int main() {
    cout << solution("aabbaccc") << endl;
    
    return 0;
}
