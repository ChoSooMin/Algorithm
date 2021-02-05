//
//  BOJ_1316.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/05.
//  Copyright © 2021 조수민. All rights reserved.
//
//  그룹 단어 체커(https://www.acmicpc.net/problem/1316)

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int answer;
vector<string> words;

bool isGroupWord(string word) {
    bool groupWord = true;
    
    // wordCount 벡터에는 해당 char가 word 안에 몇번 들어가는지 담고 있다.
    // ex) word가 happy일 경우, wordCount = { { h, 1 }, { a, 1 }, { p, 2 }, { y, 1 } }
    vector<pair<char, int>> wordCount;
    wordCount.push_back({ word[0], 1 }); // 초기 wordCount벡터 = { { h, 1 } };
    
    for (int i = 1; i < word.length(); i++) { // happy라는 문장이 들어올 경우
        char curChar = word[i]; // curChar에는 순차적으로 a, p, p, y가 들어온다.

        int isExist = -1;
        for (int index = 0; index < wordCount.size(); index++) {
            if (wordCount.at(index).first == curChar) {
                isExist = index;
                break;
            }
        }
        
        if (isExist == -1)
            wordCount.push_back({ curChar, 1 });
        else
            wordCount.at(isExist).second += 1;
    }
    
    
    int i = 0;
    while (i != word.length() - 1) {
        char curChar = word[i]; // h, a, p, p, y가 순서대로 들어온다.
        
        int curCharCount = -1; // 각 char가 word안에 몇 개 존재하는지
        for (int index = 0; index < wordCount.size(); index++) {
            if (wordCount.at(index).first == curChar) {
                curCharCount = wordCount.at(index).second;
                break;
            }
        }
        
        if (curCharCount == 1) {
            i++;
            continue;
        }
        
        for (int j = 1; j < curCharCount; j++) {
            char nextChar = word[i + j];
            
            if (nextChar != curChar) {
                groupWord = false;
                return groupWord;
            }
        }
        
        i += curCharCount;
    }
    
    return groupWord;
}

int main() {
    int N;
    cin >> N;
    
    words.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> words.at(i);
        
        if (isGroupWord(words.at(i)))
            answer++;
    }
    
    cout << answer;
    
    return 0;
}
