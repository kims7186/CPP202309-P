#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Formation {
 public:
  Formation();  // ������
  Formation(std::string formationName, int defenders, int midfielders,
            int forwards);

  // �����̼��� �߰��ϱ� ���� �Լ�
  void InsertFormation(vector<Formation> &formations);  // �����̼� �߰�
  void DeleteFormation(vector<Formation> &formations);  //�����̼� ����
  void EditFormation(vector<Formation> &formations);    //�����̼� ����

  // ���� �����̼� ������ ǥ���ϴ� �Լ�
  void DisplayFormation(const vector<Formation> &formations);

 private:
  std::string formationName;           // �����̼� �̸�
  int defenders;                       // ����� ��
  int midfielders;                     // �̵��ʴ� ��
  int forwards;                        // ���ݼ� ��
  std::vector<std::string> positions;  // ���� ��ġ
};
