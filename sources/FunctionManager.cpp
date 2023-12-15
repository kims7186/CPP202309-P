#include "Player.h"
#include "Formation.h"
#include "FunctionManager.h"
#include <iomanip>  //setw()사용하기 위함
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 다른 멤버 함수들의 구현은 여기에 추가
void InsertPlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "플레이어를 추가합니다.\n\n";
  cout << "플레이어의 정보를 이름/선호 포지션/비선호 포지션 순으로 "
          "입력하세요.\n\n";
  cout << "선호/비선호 포지션은 공격/중앙/수비/골키퍼/없음 중에서 "
          "입력해주세요\n\n";
  Player input;
  // 이름 입력
  cout << "이름: ";
  cin >> input.name;

  // 선호 포지션 입력 및 유효성 검사
  input.pre_pos = GetValidPosition("선호 포지션: ");
  input.non_pre_pos = GetValidPosition("비선호 포지션: ");
  players.push_back(input);
  cout << "------------------------------------------------------\n";
  cout << "선수가 추가되었습니다.\n\n";
  cout << "------------------------------------------------------\n";
}

void DeletePlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "플레이어를 삭제합니다.\n\n";
  cout << "삭제할 플레이어의 번호를 입력해주세요 \n\n";

  int delete_index;  // 삭제할 플레이어 번호

  // 삭제할 번호 입력
  cout << "번호: ";
  cin >> delete_index;
  players.erase(players.begin() + delete_index - 1);

  cout << "선수가 삭제 되었습니다.\n";
}

void EditPlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "플레이어를 수정합니다.\n\n";
  cout << "수정할 플레이어의 번호를 입력해주세요 \n\n";

  int edit_index;  //수정할 플레이어 번호

  // 수정할 플레이어 번호 입력
  cout << "수정할 플레이어 번호: ";
  cin >> edit_index;
  cout << "플레이어의 정보를 이름/선호 포지션/비선호 포지션 순으로 "
          "입력하세요.\n\n";
  cout << "선호/비선호 포지션은 공격/중앙/수비/골키퍼/없음 중에서 "
          "입력해주세요\n\n";
  cout << "이름: ";
  cin >> players[edit_index - 1].name;
  players[edit_index - 1].pre_pos = GetValidPosition("선호 포지션:");
  players[edit_index - 1].pre_pos = GetValidPosition("비선호 포지션:");

  cout << "선수정보가 수정 되었습니다.\n";
}

void GetInformation(const vector<Player> &players) {
  cout << "번호 |  이름               | 선호 포지션      | 비선호 포지션\n";
  cout << "------------------------------------------------------\n";

  for (int i = 0; i < players.size(); i++) {
    cout << setw(4) << i + 1;
    cout << " | " << setw(19) << players[i].name;
    cout << " | " << setw(16) << players[i].pre_pos;
    cout << " | " << players[i].non_pre_pos << endl;
  }
  cout << endl;
  cout << "------------------------------------------------------\n";
}

string GetValidPosition(const string &prompt) {
  string position;  // 입력을 통해 들어온 포지션
  while (true) {
    cout << prompt;
    cin >> position;

    if (position == "공격" || position == "중앙" || position == "수비" ||
        position == "골키퍼" || position == "없음") {
      break;
    } else {
      cout << "잘못된 포지션입니다. 공격/중앙/수비/골키퍼/없음 중 하나를 "
              "입력하세요.\n";
    }
  }
  return position;
}

// 현재 포메이션 정보를 표시하는 함수 구현
void DisplayFormation(const vector<Formation> &formations) {
  // 현재 포메이션 정보를 출력하는 함수
  cout << "번호 |포메이션 이름 | 수비수 | 미드필더 | 공격수\n";
  cout << "------------------------------------------------\n";

  for (int i = 0; i < formations.size(); i++) {
    cout << setw(4) << i + 1 << " |";
    cout << setw(13) << formations[i].formation_name;
    cout << " | " << setw(6) << formations[i].defenders;
    cout << " | " << setw(8) << formations[i].midfielders;
    cout << " | " << setw(6) << formations[i].forwards << endl;
  }
  cout << endl;
  cout << "------------------------------------------------\n";
}

void InsertFormation(vector<Formation> &formations) {
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
void EditFormation(vector<Formation> &formations) {
  cout << "------------------------------------------------------\n";
  cout << "포메이션 정보를 수정합니다.\n\n";
  cout << "수정할 포메이션의 번호를 입력해주세요 \n\n";

  int edit_index;  //수정할 플레이어 번호

  // 수정할 플레이어 번호 입력
  cout << "수정할 포메이션 번호: ";
  cin >> edit_index;
  cout << "이름: ";
  cin >> formations[edit_index - 1].formation_name;
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
        formations[edit_index - 1].defenders = def;
        formations[edit_index - 1].midfielders = mid;
        formations[edit_index - 1].forwards = forward;
        cout << "포메이션 정보가 수정되었습니다.\n";
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
void DeleteFormation(vector<Formation> &formations) {
  cout << "------------------------------------------------------\n";
  cout << "포메이션을 삭제합니다.\n\n";
  cout << "삭제할 포메이션의 번호를 입력해주세요 \n\n";

  int delete_index;  // 삭제할 플레이어 번호

  // 삭제할 번호 입력
  cout << "번호: ";
  cin >> delete_index;
  formations.erase(formations.begin() + delete_index - 1);

  cout << "포메이션이 삭제 되었습니다.\n";
}
