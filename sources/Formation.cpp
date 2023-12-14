#include "Formation.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// ������ ����
Formation::Formation()
    : formationName(""), defenders(0), midfielders(0), forwards(0) {}
Formation::Formation(std ::string formationName, int defenders, int midfielders,
                     int forwards) {
  this->formationName = formationName;
  this->defenders = defenders;
  this->midfielders = midfielders;
  this->forwards = forwards;
}

// ���� �����̼� ������ ǥ���ϴ� �Լ� ����
void Formation::DisplayFormation(const vector<Formation>& formations) {
  // ���� �����̼� ������ ����ϴ� �Լ�
  cout << "�����̼� �̸� | ����� | �̵��ʴ� | ���ݼ�\n";
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
  cout << "�߰��� �����̼��� �̸�:\n";
  cin >> formationName;
  int def, mid, forward;
  while (true) {
    cout << "����� ����:\n";
    cin >> def;
    cout << "�̵��ʴ� ����\n";
    cin >> mid;
    cout << "���ݼ� ����\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations.push_back(Formation(formationName, def, mid, forward));
        cout << "���ο� �����̼��� �߰��Ǿ����ϴ�.\n";
        break;
      } else {
        cout << "�ʵ� �÷��̾�� 10�� �Դϴ�.�ٽ� �Է����ּ���\n";
        cout << "���� �ʵ� �÷��̾� ���� :" << def + mid + forward << endl;
      }
    } else {
      cout << "�� �������� �÷��̾� ���ڴ� �ּ� �Ѹ��̿��� �մϴ�. �ٽ� "
              "�Է����ּ��� \n";
    }
  }
}
void Formation::EditFormation(vector<Formation>& formations) {

}
