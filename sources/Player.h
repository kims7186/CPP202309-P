#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
 public:
  string name;         //�÷��̾� �̸�
  string pre_pos;      //��ȣ ������
  string non_pre_pos;  //��ȣ ������
  bool is_participating; //���� ���� 
  int part_weight; //���� ����ġ 
  
  Player();            //�⺻ ������
  Player(string name, string pre_pos, string non_pre_pos);
  
};
