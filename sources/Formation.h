#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Formation {
 public:
  Formation();  // 생성자
  Formation(string formationName, int defenders, int midfielders,
            int forwards);
  string formation_name;          // 포메이션 이름
  int defenders;                       // 수비수 수
  int midfielders;                     // 미드필더 수
  int forwards;                        // 공격수 수
  vector<string> positions;  // 선수 위치
};
