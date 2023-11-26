#include <windows.h>  // 콘솔창 clear 및 시간 지연을 주기위한 헤더파일
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

// system("cls");        //콘솔창 clear하는 명령어

// 함수 선언
void DisplayMenu();  //사용자의 요구에 따라 원하는 메뉴를 출력
void loadPlayersInfo(vector<Player> &players);  // 기존 사용자 정보 불러오기
void PlayerMenu();

vector<Player> players;  //

int main() {
  cout << "------스쿼드 메이커 프로그램을 시작합니다.------- \n\n";
  cout << "-------------기존 정보를 불러옵니다--------------\n\n";

  loadPlayersInfo(players);  // 기존 정보 불러오기

  DisplayMenu();  //메인 메뉴 출력

  return 0;
}
void DisplayMenu() {
  //메인메뉴 출력
  cout << "메인 메뉴입니다.\n\n";
  cout << "\n------------------------------------------------------\n";
  cout << "항목을 선택해주세요.\n\n";
  cout << "0.종료\n";
  cout << "1.선수 정보 입력/수정/삭제\n";
  cout << "2.포메이션 정보 입력/수정/삭제\n";
  cout << "3.스쿼드메이커\n";
  cout << "\n------------------------------------------------------\n";
  cout << "사용자 입력:";
  int user_input;
  cin >> user_input;
  system("cls");  //콘솔창 clear
  switch (user_input) {
    case 0:
      cout << "프로그램을 종료합니다.\n";
      exit(0);  //프로그램 종료
      break;
    case 1:
      PlayerMenu();
      break;
    case 2:
      cout << "포메이션 정보 입력/수정/삭제 화면 입니다.\n";
      break;
    case 3:
      cout << "스쿼드메이커 화면 입니다.\n";
      break;
    default:
      cout << "잘못된 입력입니다.다시 선택 해주세요 .\n\n";
      DisplayMenu();
  }
}
void loadPlayersInfo(vector<Player> &players) {
  // 저장된 플레이어 정보
  players.push_back(Player("김건휘", "공격", "골키퍼"));
  players.push_back(Player("박민호", "공격", "수비"));
  players.push_back(Player("야넥", "공격", "수비"));
  players.push_back(Player("다윗", "중앙", "수비"));
  players.push_back(Player("승민", "중앙", "수비"));
  players.push_back(Player("종훈", "수비", "없음"));
  players.push_back(Player("희석", "수비", "공격"));
  players.push_back(Player("준희", "수비", "공격"));
  players.push_back(Player("영훈", "골키퍼", "없음"));

  Sleep(1500);
  cout << "플레이어 정보 로드 완료\n\n";
  cout << "--------------------------------------\n";
  Sleep(1000);
  system("cls");
}

void PlayerMenu() {
  cout << "\n\n선수 정보 입력/수정/삭제 화면 입니다. \n\n";
  Player player;
  player.GetInformation(players);  //현재 플레이어 정보 출력
  cout << "메뉴를 선택해주세요.\n\n";
  cout << "0.메인으로 돌아가기 \n";
  cout << "1.선수 정보 입력\n";
  cout << "2.선수 정보 수정\n";
  cout << "3.선수 정보 삭제\n";
  cout << "\n------------------------------------------------------\n";
  cout << "사용자 입력:";
  int user_input;
  cin >> user_input;
  switch (user_input) {
    case 0:
      DisplayMenu();  //메인 메뉴로 돌아갑니다
      break;
    case 1:
      player.InsertPlayer(players);
      PlayerMenu();
      break;
    case 2:
      player.EditPlayer(players);
      PlayerMenu();
      break;
    case 3:
      player.DeletePlayer(players);
      PlayerMenu();
      break;
    default:
      cout << "잘못된 입력입니다.다시 선택 해주세요 .\n\n";
      PlayerMenu();
  }
}
