#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Formation {
 public:
  Formation();  // ������
  Formation(string formationName, int defenders, int midfielders,
            int forwards);
  string formation_name;          // �����̼� �̸�
  int defenders;                       // ����� ��
  int midfielders;                     // �̵��ʴ� ��
  int forwards;                        // ���ݼ� ��
  vector<string> positions;  // ���� ��ġ
};
