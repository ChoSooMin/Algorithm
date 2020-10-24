//
//  Nhn_3.cpp
//  target-cpp
//
//  Created by 조수민 on 2020/10/24.
//  Copyright © 2020 조수민. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

void solution(int numOfOrder, string *orderArr) {
    
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
