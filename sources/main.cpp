#include <windows.h>  // �ܼ�â clear �� �ð� ������ �ֱ����� �������
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

// system("cls");        //�ܼ�â clear�ϴ� ��ɾ�

// �Լ� ����
void DisplayMenu();  //������� �䱸�� ���� ���ϴ� �޴��� ���
void loadPlayersInfo(vector<Player> &players);  // ���� ����� ���� �ҷ�����
void PlayerMenu();

vector<Player> players;  //

int main() {
  cout << "------������ ����Ŀ ���α׷��� �����մϴ�.------- \n\n";
  cout << "-------------���� ������ �ҷ��ɴϴ�--------------\n\n";

  loadPlayersInfo(players);  // ���� ���� �ҷ�����

  DisplayMenu();  //���� �޴� ���

  return 0;
}
void DisplayMenu() {
  //���θ޴� ���
  cout << "���� �޴��Դϴ�.\n\n";
  cout << "\n------------------------------------------------------\n";
  cout << "�׸��� �������ּ���.\n\n";
  cout << "0.����\n";
  cout << "1.���� ���� �Է�/����/����\n";
  cout << "2.�����̼� ���� �Է�/����/����\n";
  cout << "3.���������Ŀ\n";
  cout << "\n------------------------------------------------------\n";
  cout << "����� �Է�:";
  int user_input;
  cin >> user_input;
  system("cls");  //�ܼ�â clear
  switch (user_input) {
    case 0:
      cout << "���α׷��� �����մϴ�.\n";
      exit(0);  //���α׷� ����
      break;
    case 1:
      PlayerMenu();
      break;
    case 2:
      cout << "�����̼� ���� �Է�/����/���� ȭ�� �Դϴ�.\n";
      break;
    case 3:
      cout << "���������Ŀ ȭ�� �Դϴ�.\n";
      break;
    default:
      cout << "�߸��� �Է��Դϴ�.�ٽ� ���� ���ּ��� .\n\n";
      DisplayMenu();
  }
}
void loadPlayersInfo(vector<Player> &players) {
  // ����� �÷��̾� ����
  players.push_back(Player("�����", "����", "��Ű��"));
  players.push_back(Player("�ڹ�ȣ", "����", "����"));
  players.push_back(Player("�߳�", "����", "����"));
  players.push_back(Player("����", "�߾�", "����"));
  players.push_back(Player("�¹�", "�߾�", "����"));
  players.push_back(Player("����", "����", "����"));
  players.push_back(Player("��", "����", "����"));
  players.push_back(Player("����", "����", "����"));
  players.push_back(Player("����", "��Ű��", "����"));

  Sleep(1500);
  cout << "�÷��̾� ���� �ε� �Ϸ�\n\n";
  cout << "--------------------------------------\n";
  Sleep(1000);
  system("cls");
}

void PlayerMenu() {
  cout << "\n\n���� ���� �Է�/����/���� ȭ�� �Դϴ�. \n\n";
  Player player;
  player.GetInformation(players);  //���� �÷��̾� ���� ���
  cout << "�޴��� �������ּ���.\n\n";
  cout << "0.�������� ���ư��� \n";
  cout << "1.���� ���� �Է�\n";
  cout << "2.���� ���� ����\n";
  cout << "3.���� ���� ����\n";
  cout << "\n------------------------------------------------------\n";
  cout << "����� �Է�:";
  int user_input;
  cin >> user_input;
  switch (user_input) {
    case 0:
      DisplayMenu();  //���� �޴��� ���ư��ϴ�
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
      cout << "�߸��� �Է��Դϴ�.�ٽ� ���� ���ּ��� .\n\n";
      PlayerMenu();
  }
}
