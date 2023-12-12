#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
 public:
  string name;         //플레이어 이름
  string pre_pos;      //선호 포지션
  string non_pre_pos;  //비선호 포지션
  Player(); //기본 생성자 
  Player(string name, string pre_pos, string non_pre_pos);
  void InsertPlayer(vector<Player> &players);  // 플레이어 추가
  void DeletePlayer(vector<Player> &players);  //플레이어 삭제
  void EditPlayer(vector<Player> &players);  // 플레이어 수정
  void GetInformation(const vector<Player> &players);  // 플레이어 정보 보여주는 함수
  string GetValidPosition(const string &prompt);  // 입력된 포지션 유효성 검사 및 올바른 입력 반환하는 함수
};
