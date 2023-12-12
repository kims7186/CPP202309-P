#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Formation {
 public:
  Formation();  // 생성자
  Formation(std::string formationName, int defenders, int midfielders,
            int forwards);

  // 유효한 포메이션 입력을 받기 위한 함수
  std::string GetValidFormation(const std::string& prompt);

  // 현재 포메이션 정보를 표시하는 함수
  void DisplayFormation(const vector<Formation>& formations);

 private:
  std::string formationName;           // 포메이션 이름
  int defenders;                       // 수비수 수
  int midfielders;                     // 미드필더 수
  int forwards;                        // 공격수 수
  std::vector<std::string> positions;  // 선수 위치
};
