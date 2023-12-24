#include <windows.h>  // �ܼ�â clear �� �ð� ������ �ֱ����� �������
#include <algorithm> 
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "Formation.h"
#include "Player.h"
#include "FunctionManager.h"

using namespace std;

// system("cls");        //�ܼ�â clear�ϴ� ��ɾ�

// �Լ� ����
void DisplayMenu();  //������� �䱸�� ���� ���ϴ� �޴��� ���
void loadPlayersInfo(vector<Player>& players);  // ���� ����� ���� �ҷ�����
void loadPlayersInfo(string filename);
void loadFormationsInfo(vector<Formation>& formations);

void PlayerMenu();
void FormationMenu();

void SquadMakerMenu();
bool ComparePlayers(const Player& a, const Player& b);
void SortPlayersForFormation(vector<Player>& players);
void ExaminePositionPreference(vector<Player>& players);
template <typename T>
void DisplayArray(const vector<T>& arr);

vector<Player> players;        //�÷��̾��� ������ ����� �迭
vector<Formation> formations;  // �����̼��� ������ ����� �迭

int main() {
	cout << "----������ ����Ŀ ���α׷��� �����մϴ�.------ \n\n";
	cout << "------------���� ������ �ҷ��ɴϴ�-------------\n\n";

	loadPlayersInfo(players);  // ���� ���� �ҷ�����
	loadPlayersInfo("Blueveins.txt");
	loadFormationsInfo(formations);  // ���� �����̼� ���� �ҷ�����

	DisplayMenu();  //���� �޴� ���

	return 0;
}
void DisplayMenu() {
	int user_input;
	while (true) {
		//���θ޴� ���
		cout << "���� �޴��Դϴ�.\n\n";
		cout << "\n-----------------------------------------------\n";
		cout << "�׸��� �������ּ���.\n\n";
		cout << "0.����\n";
		cout << "1.���� ���� �Է�/����/����\n";
		cout << "2.�����̼� ���� �Է�/����/����\n";
		cout << "3.���������Ŀ\n";
		cout << "------------------------------------------------\n";

		try {
			cout << "����� �Է�:";
			cin >> user_input;
			if (cin.fail()) {
				cin.clear();  // ���� �÷��� �ʱ�ȭ
				cin.ignore(200, '\n');
				throw runtime_error("�߸��� �Է��Դϴ�.�ٽ� �Է����ּ���.\n");
			}
			else {
				break;
			}
		}
		catch (const exception& e) {
			system("cls");
			cout << e.what();
		}
	}

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
		FormationMenu();
		break;
	case 3:
		SquadMakerMenu();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�.�ٽ� �Է����ּ���.\n";
		DisplayMenu();
	}
}
void loadPlayersInfo(vector<Player>& players) {
	// ����� �÷��̾� ����
	players.push_back(Player("�����", "����", "��Ű��"));
	players.push_back(Player("�ڹ�ȣ", "����", "����"));
	players.push_back(Player("�߳�", "����", "����"));
	players.push_back(Player("�̴���", "�߾�", "����"));
	players.push_back(Player("�ֽ¹�", "�߾�", "����"));
	players.push_back(Player("������", "����", "����"));
	players.push_back(Player("����", "����", "����"));
	players.push_back(Player("������", "����", "����"));
	players.push_back(Player("������", "��Ű��", "����"));

	Sleep(1500);
	cout << "�÷��̾� ���� �ε� �Ϸ�\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // �ܼ�â �ʱ�ȭ
}
void loadPlayersInfo(string filename) {
	// �÷��̾� ������ ����� ���� �б�
	ifstream is{ filename };
	if (!is) {
		cerr << "���� ���¿� �����Ͽ����ϴ�." << endl;
		cout << filename << "�� ������ �ٽ� Ȯ���ϼ���\n";
		cout << "���α׷��� �����մϴ�\n";
		exit(1);
	}
	string txt_name, txt_pre,
		txt_non_pre;  //������ 1�࿡ ��� ���� ����(�̸�,��ȣ,��ȣ)
	while (is >> txt_name >> txt_pre >> txt_non_pre) {
		players.push_back(Player(txt_name, txt_pre, txt_non_pre));
	}

	Sleep(1500);
	cout << filename << "������ �÷��̾� ���� �ε� �Ϸ�\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // �ܼ�â �ʱ�ȭ
}
//����� �����̼� ����
void loadFormationsInfo(vector<Formation>& formations) {
	// formationName(""), defenders(0), midfielders(0), forwards(0)
	formations.push_back(Formation("343", 3, 4, 3));
	formations.push_back(Formation("352", 3, 5, 2));
	formations.push_back(Formation("433", 4, 3, 3));
	formations.push_back(Formation("42(31)", 4, 2, 4));
	formations.push_back(Formation("442", 4, 4, 2));
	formations.push_back(Formation("541", 5, 4, 1));
	formations.push_back(Formation("523", 5, 2, 3));

	Sleep(1500);
	cout << "�����̼� ���� �ε� �Ϸ�\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // �ܼ�â �ʱ�ȭ
}

void PlayerMenu() {
	cout << "\n\n���� ���� �Է�/����/���� ȭ�� �Դϴ�. \n\n";
	// Player player;
	GetInformation(players);  //���� �÷��̾� ���� ���
	cout << "�޴��� �������ּ���.\n\n";
	cout << "0.�������� ���ư��� \n";
	cout << "1.���� ���� �Է�\n";
	cout << "2.���� ���� ����\n";
	cout << "3.���� ���� ����\n";
	cout << "\n------------------------------------------------\n";
	cout << "����� �Է�:";
	int user_input;
	cin >> user_input;
	switch (user_input) {
	case 0:
		DisplayMenu();  //���� �޴��� ���ư��ϴ�
		break;
	case 1:
		InsertPlayer(players);
		PlayerMenu();
		break;
	case 2:
		EditPlayer(players);
		PlayerMenu();
		break;
	case 3:
		DeletePlayer(players);
		PlayerMenu();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�.�ٽ� ���� ���ּ��� .\n\n";
		PlayerMenu();
	}
}

void FormationMenu() {
	cout << "\n\n�����̼� ���� �Է�/����/���� ȭ�� �Դϴ�. \n\n";
	// Formation formation;
	DisplayFormation(formations);  //���� �÷��̾� ���� ���
	cout << "�޴��� �������ּ���.\n\n";
	cout << "0.�������� ���ư��� \n";
	cout << "1.�����̼� ���� �Է�\n";
	cout << "2.�����̼� ���� ����\n";
	cout << "3.�����̼� ���� ����\n";
	cout << "------------------------------------------------\n";
	cout << "����� �Է�:";
	int user_input;
	cin >> user_input;
	switch (user_input) {
	case 0:
		DisplayMenu();  //���� �޴��� ���ư��ϴ�
		break;
	case 1:
		InsertFormation(formations);
		FormationMenu();
		break;
	case 2:
		EditFormation(formations);
		FormationMenu();
	case 3:
		DeleteFormation(formations);
		FormationMenu();
		break;
	default:
		cout << "�߸��� �Է��Դϴ�.�ٽ� ���� ���ּ��� .\n\n";
		FormationMenu();
	}
}
void SquadMakerMenu() {
	system("cls"); // ���� �ʱ�ȭ 
	cout << "���������Ŀ ȭ�� �Դϴ�.\n";
	// ����� �Է� �ޱ�(���ͼ�, ���� �ο�,���� ���� ����)
	int num_quarters, player_num;
	cout << "������ ����Ŀ ������ �����մϴ�.\n";
	cout << "���� ���� �Է��� �ּ��� \n";
	cout << "����� �Է�:";
	cin >> num_quarters;

	system("cls");
	while (true) {
		player_num = 0;
		cout << "\n���� 1���� ��ϵ� ������ ����Դϴ�.\n";
		GetInformation(players);
		cout << "��⿡ �������� ���ϴ� ������ ��ȣ�� �Է����ּ��� \n";
		cout << "������ ������ ���ų� ������ ���ƴٸ� 0�� �Է����ּ���\n";
		cout << "����� �Է�:";
		cin >> player_num;
		if (player_num == 0) {
			break;
		}
		else {
			players[player_num - 1].is_participating = false;
		}
	}
	int formationindex;
	cout << "��⿡����� �����̼��� ������ �ּ���\n";
	DisplayFormation(formations);
	cout << "����� �Է�:";
	cin >> formationindex;
	int num_def = formations[formationindex - 1].defenders;
	int num_mid = formations[formationindex - 1].midfielders;
	int num_for = formations[formationindex - 1].forwards;
	int num_keeper = 1;

	//���� �������� �� �����Ǻ� ��ȣ�� ���� 	
	ExaminePositionPreference(players);

	//������ ����ŷ �� ��� 
	for (int quarter = 1; quarter <= num_quarters; quarter++) {
		// ������ ���� ����, ������ ��ȣ��, �����̼� ����ġ�� ���� ����
		SortPlayersForFormation(players);

		// �� �����Ǻ��� ���õ� ������ ������ �迭
		vector<string> forward, mid, def, keeper;

		// ������ ��ȸ�ϸ� ������ ����
		for (auto& player : players) {
			if (!player.is_participating) {
				continue; // �������� �ʴ� ���� �ǳʶ�
			}

			// �����忡 ���õǾ����Ƿ� ���� ����ġ ����
			player.part_weight -= 7;

			// ��ȣ���� ����ġ�� ���� �����ǿ� ���� ����
			if (player.pre_pos == "����" && forward.size() < num_for) {
				forward.push_back(player.name);
			}
			else if (player.pre_pos == "�߾�" && mid.size() < num_mid) {
				mid.push_back(player.name);
			}
			else if (player.pre_pos == "����" && def.size() < num_def) {
				def.push_back(player.name);
			}
			else if (player.pre_pos == "��Ű��" && keeper.empty()) {
				keeper.push_back(player.name);
			}
			// 
			else {
				if (forward.size() + mid.size() + def.size() + keeper.size() == 11) {
					break; //11���� ��� �ۼ��Ϸ� 
				}
				else {
					while (true) {
						int randomPosition = rand() % 4;
						// �����ϰ� ���õ� �����ǿ� ���� ����� ���� ����
						vector<string>* posVector;
						int pos_num = 0;
						switch (randomPosition) {
						case 0:
							posVector = &forward;
							pos_num = num_for;
							break;
						case 1:
							posVector = &mid;
							pos_num = num_mid;
							break;
						case 2:
							posVector = &def;
							pos_num = num_def;
							break;
						case 3:
							posVector = &keeper;
							pos_num = 1;
							break;
						default:
							cerr << "����: �߸��� ������ ��ȣ�Դϴ�.\n";
							continue; // ��ȿ���� ���� ��ȣ�� �����Ǹ� �ٽ� �õ�
						}

						// �ش� �����ǿ� ������ ������ ������ �Ҵ��ϰ� ������ ����
						if (posVector->size() < pos_num) {
							posVector->push_back(player.name);
							break;
						}						

					}


				}
			}
		}

		// ���� ������ ������ ǥ��
		cout << "\n\n======== " << quarter << "������ ������ ========\n";
		cout << "Forward: ";
		DisplayArray(forward);
		cout << "Mid: ";
		DisplayArray(mid);
		cout << "Defense: ";
		DisplayArray(def);
		cout << "Keeper: ";
		DisplayArray(keeper);
	}


	int user_input;
	cout << "\n0�� �Է��ϸ� ���� �޴��� ���ư��ϴ�.\n";
	cout << "����� �Է�:";
	cin >> user_input;
	if (user_input == 0) {
		DisplayMenu();
	}

}
// ���� ����, ������ ��ȣ��, �����̼� ����ġ�� ���� �������� �����ϴ� �� �Լ�
bool ComparePlayers(const Player& a, const Player& b) {
	// ���� ���ο� ���� ���� (���� ���̸� �켱, ���� ������ ������ ���� ��������)
	if (a.is_participating != b.is_participating) {
		return a.is_participating > b.is_participating;
	}

	// ����ġ�� ���� ���� (����ġ ��������)
	return a.part_weight > b.part_weight;
}

// �����̼� ���� �� ��ȣ���� ���� �������� �����ϴ� �Լ�
void SortPlayersForFormation(vector<Player>& players) {
	sort(players.begin(), players.end(), ComparePlayers);
}

// ���� ���� �������� ������ ��ȣ���� �����ϴ� �Լ�
void ExaminePositionPreference(vector<Player>& players) {
	int pre_attack = 0, pre_center = 0, pre_defense = 0, pre_goalkeeper = 0;


	for (const auto& player : players) {
		if (!player.is_participating) {
			continue; // �������� �ʴ� ������ �ǳʶݴϴ�.
		}

		// ��ȣ �����ǿ� ���� ��ȣ���� ������ŵ�ϴ�.
		if (player.pre_pos == "����") {
			pre_attack++;
		}
		else if (player.pre_pos == "�߾�") {
			pre_center++;
		}
		else if (player.pre_pos == "����") {
			pre_defense++;
		}
		else if (player.pre_pos == "��Ű��") {
			pre_goalkeeper++;
		}

		// ��ȣ �����ǿ� ���� ��ȣ���� ���ҽ�ŵ�ϴ�.
		if (player.non_pre_pos == "����") {
			pre_attack--;
		}
		else if (player.non_pre_pos == "�߾�") {
			pre_center--;
		}
		else if (player.non_pre_pos == "����") {
			pre_defense--;
		}
		else if (player.non_pre_pos == "��Ű��") {
			pre_goalkeeper--;
		}
	}

	// ������ ��ȣ�� ����� ����մϴ�.
	cout << "���� ���� �������� ������ ��ȣ�� ���:\n";
	cout << "����: " << pre_attack << "\n";
	cout << "�߾�: " << pre_center << "\n";
	cout << "����: " << pre_defense << "\n";
	cout << "��Ű��: " << pre_goalkeeper << "\n";

	cout << " ��ȣ�� �� �ݿ��մϴ�.\n";

	//��ȣ���� �ݿ��մϴ�. 
	for (auto& player : players) {
		if (!player.is_participating) {
			continue; // �������� �ʴ� ������ �ǳʶݴϴ�.
		}

		// ��ȣ �������� ��� ����ġ�� ���� �켱������ ����ϴ�. 
		if (player.pre_pos == "����") {
			player.part_weight -= pre_attack;
		}
		else if (player.pre_pos == "�߾�") {
			player.part_weight -= pre_center;
		}
		else if (player.pre_pos == "����") {
			player.part_weight -= pre_defense;
		}
		else if (player.pre_pos == "��Ű��") {
			player.part_weight -= pre_goalkeeper;
		}

		// ��ȣ �������� ��� ����ġ�� ���� �켱������ ���Դϴ�. 
		if (player.non_pre_pos == "����") {
			player.part_weight += pre_attack;
		}
		else if (player.non_pre_pos == "�߾�") {
			player.part_weight += pre_center;
		}
		else if (player.non_pre_pos == "����") {
			player.part_weight += pre_defense;
		}
		else if (player.non_pre_pos == "��Ű��") {
			player.part_weight += pre_goalkeeper;
		}
	}


}

// �迭�� ��Ҹ� ǥ���ϴ� �Լ�
template <typename T>
void DisplayArray(const vector<T>& arr) {
	for (const auto& elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}
