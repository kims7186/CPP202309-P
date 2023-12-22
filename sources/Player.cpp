#include "Player.h"

#include <iomanip>  //setw()사용하기 위함
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 생성자 정의와 초기화 목록 사용
Player::Player() {}
Player::Player(string name, string pre_pos, string non_pre_pos) {
  if (name.size() < 3) {
    name = " " + name;
  } else {
    this->name = name;
  }

  this->pre_pos = pre_pos;
  this->non_pre_pos = non_pre_pos;
  this->is_participating = true; //참여여부는 항상 true로 초기화 
}
