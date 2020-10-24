//
//  Nhn_2.cpp
//  multi-target
//
//  Created by 조수민 on 2020/10/24.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> blockVector;

/**
 왼쪽 최대, 오른쪽 최대 구해서,, 
 */
int getMaxIndex(int start, int end, vector<int> blockVector) {
    int maxIndex = start;
    int maxBlock = blockVector.at(maxIndex);
    
    for (int i = start; i <= end; i++) {
        if (blockVector.at(i) >= maxBlock) {
            maxIndex = i;
            maxBlock = blockVector.at(i);
        }
    }
    
    return maxIndex;
}

void solution(int day, int width, int **blocks) {
    // init
    blockVector.resize(width);
    
    // 초기 벽돌 (예시 1일 경우, 초기 blockVector에는 6 2 11 0 3 5 가 들어간다.
    for (int i = 0; i < blockVector.size(); i++) {
        blockVector.at(i) = blocks[0][i];
    }
    
    int getCimentCount = 0;
    
    int leftIndex = 0;
    int rightIndex = blockVector.size() - 1;
    
    
    if (blockVector.at(leftIndex) < blockVector.at(leftIndex + 1)) {
        leftIndex = leftIndex + 1;
    }
    int rightMax = blockVector.at(rightIndex);
    for (int j = blockVector.size() - 1; j > leftIndex; j--) {
        if (blockVector.at(j) >= rightMax) {
            rightIndex = j;
            rightMax = blockVector.at(j);
        }
    }
    
    cout << "left : " << leftIndex << " / ";
    cout << "right : " << rightIndex << endl;
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
    struct input_data inputData;
    process_stdin(inputData);

    solution(inputData.day, inputData.width, inputData.blocks);
    return 0;
}
