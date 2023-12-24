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
  bool is_participating; //참여 여부 
  int part_weight; //참여 가중치 
  
  Player();            //기본 생성자
  Player(string name, string pre_pos, string non_pre_pos);
  
};
