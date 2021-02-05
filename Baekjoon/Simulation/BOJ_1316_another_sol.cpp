//
//  BOJ_1316_another_sol.cpp
//  Algorithm
//
//  Created by 조수민 on 2021/02/05.
//  Copyright © 2021 조수민. All rights reserved.
//
//  그룹 단어 체커(https://www.acmicpc.net/problem/1316)

#include <stdio.h>
#include <iostream>

using namespace std;

bool isGroupWord(string word) {
    bool groupWord = true;
    
    int arr[26];
    fill_n(arr, 26, 0); // 현재 알파벳이 이미 나왔던 알파벳인지 저장하는 배열
    
    arr[word[0] - 97] = 1; // 제일 첫번째 알파벳이 이미 나온 알파벳임을 저장해둔다.
    
    for (int i = 1; i < word.length(); i++) { // word의 두번째 알파벳부터 순서대로 접근
        int ascii = word[i] - 97; // 알파벳의 순서 값 구하기 (a가 0, .. z가 25)

        if (word[i - 1] != word[i]) { // 바로 전의 알파벳과 다를 경우
            if (arr[ascii] == 0) { // 현재 알파벳이 처음 나오는 알파벳이면 arr 값을 1로 바꿔준다.
                arr[ascii] = 1;
            }
            else { // 이미 나왔던 알파벳이면
                groupWord = false; // 이 단어는 그룹 단어가 아니다
                break;
            }
        }
    }
    
    return groupWord;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    int answer = 0;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        
        if (isGroupWord(word))
            answer++;
    }
    cout << answer << endl;
    
    return 0;
}
