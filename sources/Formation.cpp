#include "Formation.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// 생성자 구현
Formation::Formation()
    : formationName(""), defenders(0), midfielders(0), forwards(0) {}
Formation::Formation(std ::string formationName, int defenders, int midfielders,
                     int forwards) {
  this->formationName = formationName;
  this->defenders = defenders;
  this->midfielders = midfielders;
  this->forwards = forwards;
}

// 유효한 포메이션 입력을 받기 위한 함수 구현
std::string Formation::GetValidFormation(const std::string& prompt) {
  std::string formation;
  while (true) {
    std::cout << prompt;
    std::cin >> formation;

    if (formation == "343" || formation == "352" || formation == "433" ||
        formation == "4231" || formation == "442" || formation == "541" ||
        formation == "523") {
      break;
    } else {
      std::cout << "유효하지 않은 포메이션입니다. 유효한 값을 입력해주세요.\n";
    }
  }
  return formation;
}

// 현재 포메이션 정보를 표시하는 함수 구현
void Formation::DisplayFormation(const vector<Formation>& formations) {
  // 현재 포메이션 정보를 출력하는 함수
  cout << "포메이션 이름 | 수비수 | 미드필더 | 공격수\n";
  cout << "------------------------------------------\n";

  for (int i = 0; i < formations.size(); i++) {
    cout << setw(13) << formations[i].formationName;
    cout << " | " << setw(6) << formations[i].defenders;
    cout << " | " << setw(8) << formations[i].midfielders;
    cout << " | " << setw(6) << formations[i].forwards << endl;
  }
  cout << endl;
  cout << "------------------------------------------\n";
}
