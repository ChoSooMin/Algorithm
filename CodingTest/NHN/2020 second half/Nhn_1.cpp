//
//  Nhn_1.cpp
//  Algorithm
//
//  Created by 조수민 on 2020/10/24.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 ASCII 코드를 사용?
 */
int ascii[27];
char quickPlayers[26];

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
    strcpy(quickPlayers, namesOfQuickPlayers); // 배열에 달리기가 빠른 선수들의 이름을 넣는다.
    vector<int> movesPerGame;
    movesPerGame.resize(numOfGames);
    for (int i = 0; i < movesPerGame.size(); i++) {
        movesPerGame.push_back(numOfMovesPerGame[i]);
    }
    
    int startPosition = 98; // 맨 처음에는 술래가 B의 위치에서 시작
    
    while (numOfGames != 0) { // 게임 진행
        
        
        numOfGames--; // 한 게임이 끝날 때마다 -1
    }
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}
