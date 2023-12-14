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

void Formation::InsertFormation(vector<Formation>& formations) {
  string formationName;
  cout << "추가할 포메이션의 이름:\n";
  cin >> formationName;
  int def, mid, forward;
  while (true) {
    cout << "수비수 숫자:\n";
    cin >> def;
    cout << "미드필더 숫자\n";
    cin >> mid;
    cout << "공격수 숫자\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations.push_back(Formation(formationName, def, mid, forward));
        cout << "새로운 포메이션이 추가되었습니다.\n";
        break;
      } else {
        cout << "필드 플레이어는 10명 입니다.다시 입력해주세요\n";
        cout << "현재 필드 플레이어 숫자 :" << def + mid + forward << endl;
      }
    } else {
      cout << "각 포지션의 플레이어 숫자는 최소 한명이여야 합니다. 다시 "
              "입력해주세요 \n";
    }
  }
}
void Formation::EditFormation(vector<Formation>& formations) {

}
