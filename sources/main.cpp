#include <windows.h>  // 콘솔창 clear 및 시간 지연을 주기위한 헤더파일
#include <algorithm> 
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "Formation.h"
#include "Player.h"
#include "FunctionManager.h"

using namespace std;

// system("cls");        //콘솔창 clear하는 명령어

// 함수 선언
void DisplayMenu();  //사용자의 요구에 따라 원하는 메뉴를 출력
void loadPlayersInfo(vector<Player>& players);  // 기존 사용자 정보 불러오기
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

vector<Player> players;        //플레이어의 정보가 저장된 배열
vector<Formation> formations;  // 포메이션의 정보가 저장된 배열

int main() {
	cout << "----스쿼드 메이커 프로그램을 시작합니다.------ \n\n";
	cout << "------------기존 정보를 불러옵니다-------------\n\n";

	loadPlayersInfo(players);  // 기존 정보 불러오기
	loadPlayersInfo("Blueveins.txt");
	loadFormationsInfo(formations);  // 기존 포메이션 정보 불러오기

	DisplayMenu();  //메인 메뉴 출력

	return 0;
}
void DisplayMenu() {
	int user_input;
	while (true) {
		//메인메뉴 출력
		cout << "메인 메뉴입니다.\n\n";
		cout << "\n-----------------------------------------------\n";
		cout << "항목을 선택해주세요.\n\n";
		cout << "0.종료\n";
		cout << "1.선수 정보 입력/수정/삭제\n";
		cout << "2.포메이션 정보 입력/수정/삭제\n";
		cout << "3.스쿼드메이커\n";
		cout << "------------------------------------------------\n";

		try {
			cout << "사용자 입력:";
			cin >> user_input;
			if (cin.fail()) {
				cin.clear();  // 오류 플래그 초기화
				cin.ignore(200, '\n');
				throw runtime_error("잘못된 입력입니다.다시 입력해주세요.\n");
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
		FormationMenu();
		break;
	case 3:
		SquadMakerMenu();
		break;
	default:
		cout << "잘못된 입력입니다.다시 입력해주세요.\n";
		DisplayMenu();
	}
}
void loadPlayersInfo(vector<Player>& players) {
	// 저장된 플레이어 정보
	players.push_back(Player("김건휘", "공격", "골키퍼"));
	players.push_back(Player("박민호", "공격", "수비"));
	players.push_back(Player("야넥", "공격", "수비"));
	players.push_back(Player("이다윗", "중앙", "수비"));
	players.push_back(Player("최승민", "중앙", "수비"));
	players.push_back(Player("박종훈", "수비", "없음"));
	players.push_back(Player("장희석", "수비", "공격"));
	players.push_back(Player("이준희", "수비", "공격"));
	players.push_back(Player("조영훈", "골키퍼", "없음"));

	Sleep(1500);
	cout << "플레이어 정보 로드 완료\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // 콘솔창 초기화
}
void loadPlayersInfo(string filename) {
	// 플레이어 정보가 저장된 파일 읽기
	ifstream is{ filename };
	if (!is) {
		cerr << "파일 오픈에 실패하였습니다." << endl;
		cout << filename << "의 내용을 다시 확인하세요\n";
		cout << "프로그램을 종료합니다\n";
		exit(1);
	}
	string txt_name, txt_pre,
		txt_non_pre;  //파일의 1행에 담긴 선수 정보(이름,선호,비선호)
	while (is >> txt_name >> txt_pre >> txt_non_pre) {
		players.push_back(Player(txt_name, txt_pre, txt_non_pre));
	}

	Sleep(1500);
	cout << filename << "파일의 플레이어 정보 로드 완료\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // 콘솔창 초기화
}
//저장된 포메이션 정보
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
	cout << "포메이션 정보 로드 완료\n\n";
	cout << "------------------------------------------------\n";
	Sleep(1000);
	system("cls");  // 콘솔창 초기화
}

void PlayerMenu() {
	cout << "\n\n선수 정보 입력/수정/삭제 화면 입니다. \n\n";
	// Player player;
	GetInformation(players);  //현재 플레이어 정보 출력
	cout << "메뉴를 선택해주세요.\n\n";
	cout << "0.메인으로 돌아가기 \n";
	cout << "1.선수 정보 입력\n";
	cout << "2.선수 정보 수정\n";
	cout << "3.선수 정보 삭제\n";
	cout << "\n------------------------------------------------\n";
	cout << "사용자 입력:";
	int user_input;
	cin >> user_input;
	switch (user_input) {
	case 0:
		DisplayMenu();  //메인 메뉴로 돌아갑니다
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
		cout << "잘못된 입력입니다.다시 선택 해주세요 .\n\n";
		PlayerMenu();
	}
}

void FormationMenu() {
	cout << "\n\n포메이션 정보 입력/수정/삭제 화면 입니다. \n\n";
	// Formation formation;
	DisplayFormation(formations);  //현재 플레이어 정보 출력
	cout << "메뉴를 선택해주세요.\n\n";
	cout << "0.메인으로 돌아가기 \n";
	cout << "1.포메이션 정보 입력\n";
	cout << "2.포메이션 정보 수정\n";
	cout << "3.포메이션 정보 삭제\n";
	cout << "------------------------------------------------\n";
	cout << "사용자 입력:";
	int user_input;
	cin >> user_input;
	switch (user_input) {
	case 0:
		DisplayMenu();  //메인 메뉴로 돌아갑니다
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
		cout << "잘못된 입력입니다.다시 선택 해주세요 .\n\n";
		FormationMenu();
	}
}
void SquadMakerMenu() {
	system("cls"); // 보드 초기화 
	cout << "스쿼드메이커 화면 입니다.\n";
	// 사용자 입력 받기(쿼터수, 참여 인원,게임 참여 여부)
	int num_quarters, player_num;
	cout << "스쿼드 메이커 설정을 시작합니다.\n";
	cout << "쿼터 수를 입력해 주세요 \n";
	cout << "사용자 입력:";
	cin >> num_quarters;

	system("cls");
	while (true) {
		player_num = 0;
		cout << "\n현재 1군에 등록된 선수의 명단입니다.\n";
		GetInformation(players);
		cout << "경기에 참여하지 못하는 선수의 번호를 입력해주세요 \n";
		cout << "빠지는 선수가 없거나 수정을 마쳤다면 0을 입력해주세요\n";
		cout << "사용자 입력:";
		cin >> player_num;
		if (player_num == 0) {
			break;
		}
		else {
			players[player_num - 1].is_participating = false;
		}
	}
	int formationindex;
	cout << "경기에사용할 포메이션을 선택해 주세요\n";
	DisplayFormation(formations);
	cout << "사용자 입력:";
	cin >> formationindex;
	int num_def = formations[formationindex - 1].defenders;
	int num_mid = formations[formationindex - 1].midfielders;
	int num_for = formations[formationindex - 1].forwards;
	int num_keeper = 1;

	//참가 선수별로 각 포지션별 선호도 조사 	
	ExaminePositionPreference(players);

	//스쿼드 메이킹 및 출력 
	for (int quarter = 1; quarter <= num_quarters; quarter++) {
		// 선수를 참여 여부, 포지션 선호도, 포메이션 가중치에 따라 정렬
		SortPlayersForFormation(players);

		// 각 포지션별로 선택된 선수를 저장할 배열
		vector<string> forward, mid, def, keeper;

		// 선수를 순회하며 스쿼드 구성
		for (auto& player : players) {
			if (!player.is_participating) {
				continue; // 참가하지 않는 선수 건너뜀
			}

			// 스쿼드에 선택되었으므로 참여 가중치 감소
			player.part_weight -= 7;

			// 선호도와 가중치에 따라 포지션에 선수 배정
			if (player.pre_pos == "공격" && forward.size() < num_for) {
				forward.push_back(player.name);
			}
			else if (player.pre_pos == "중앙" && mid.size() < num_mid) {
				mid.push_back(player.name);
			}
			else if (player.pre_pos == "수비" && def.size() < num_def) {
				def.push_back(player.name);
			}
			else if (player.pre_pos == "골키퍼" && keeper.empty()) {
				keeper.push_back(player.name);
			}
			// 
			else {
				if (forward.size() + mid.size() + def.size() + keeper.size() == 11) {
					break; //11명의 명단 작성완료 
				}
				else {
					while (true) {
						int randomPosition = rand() % 4;
						// 랜덤하게 선택된 포지션에 따라 사용할 벡터 설정
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
							cerr << "에러: 잘못된 포지션 번호입니다.\n";
							continue; // 유효하지 않은 번호가 생성되면 다시 시도
						}

						// 해당 포지션에 공간이 있으면 선수를 할당하고 루프를 종료
						if (posVector->size() < pos_num) {
							posVector->push_back(player.name);
							break;
						}						

					}


				}
			}
		}

		// 현재 쿼터의 스쿼드 표시
		cout << "\n\n======== " << quarter << "쿼터의 스쿼드 ========\n";
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
	cout << "\n0을 입력하면 메인 메뉴로 돌아갑니다.\n";
	cout << "사용자 입력:";
	cin >> user_input;
	if (user_input == 0) {
		DisplayMenu();
	}

}
// 참가 여부, 포지션 선호도, 포메이션 가중치에 따라 선수들을 정렬하는 비교 함수
bool ComparePlayers(const Player& a, const Player& b) {
	// 참가 여부에 따라 정렬 (참가 중이면 우선, 참가 중이지 않으면 가장 마지막에)
	if (a.is_participating != b.is_participating) {
		return a.is_participating > b.is_participating;
	}

	// 가중치에 따라 정렬 (가중치 높을수록)
	return a.part_weight > b.part_weight;
}

// 포메이션 참여 및 선호도에 따라 선수들을 정렬하는 함수
void SortPlayersForFormation(vector<Player>& players) {
	sort(players.begin(), players.end(), ComparePlayers);
}

// 참가 중인 선수들의 포지션 선호도를 조사하는 함수
void ExaminePositionPreference(vector<Player>& players) {
	int pre_attack = 0, pre_center = 0, pre_defense = 0, pre_goalkeeper = 0;


	for (const auto& player : players) {
		if (!player.is_participating) {
			continue; // 참가하지 않는 선수는 건너뜁니다.
		}

		// 선호 포지션에 따라 선호도를 증가시킵니다.
		if (player.pre_pos == "공격") {
			pre_attack++;
		}
		else if (player.pre_pos == "중앙") {
			pre_center++;
		}
		else if (player.pre_pos == "수비") {
			pre_defense++;
		}
		else if (player.pre_pos == "골키퍼") {
			pre_goalkeeper++;
		}

		// 비선호 포지션에 따라 선호도를 감소시킵니다.
		if (player.non_pre_pos == "공격") {
			pre_attack--;
		}
		else if (player.non_pre_pos == "중앙") {
			pre_center--;
		}
		else if (player.non_pre_pos == "수비") {
			pre_defense--;
		}
		else if (player.non_pre_pos == "골키퍼") {
			pre_goalkeeper--;
		}
	}

	// 포지션 선호도 요약을 출력합니다.
	cout << "참가 중인 선수들의 포지션 선호도 요약:\n";
	cout << "공격: " << pre_attack << "\n";
	cout << "중앙: " << pre_center << "\n";
	cout << "수비: " << pre_defense << "\n";
	cout << "골키퍼: " << pre_goalkeeper << "\n";

	cout << " 선호도 를 반영합니다.\n";

	//선호도를 반영합니다. 
	for (auto& player : players) {
		if (!player.is_participating) {
			continue; // 참가하지 않는 선수는 건너뜁니다.
		}

		// 선호 포지션의 경우 가중치를 낮춰 우선순위를 낮춥니다. 
		if (player.pre_pos == "공격") {
			player.part_weight -= pre_attack;
		}
		else if (player.pre_pos == "중앙") {
			player.part_weight -= pre_center;
		}
		else if (player.pre_pos == "수비") {
			player.part_weight -= pre_defense;
		}
		else if (player.pre_pos == "골키퍼") {
			player.part_weight -= pre_goalkeeper;
		}

		// 비선호 포지션의 경우 가중치를 높여 우선순위를 높입니다. 
		if (player.non_pre_pos == "공격") {
			player.part_weight += pre_attack;
		}
		else if (player.non_pre_pos == "중앙") {
			player.part_weight += pre_center;
		}
		else if (player.non_pre_pos == "수비") {
			player.part_weight += pre_defense;
		}
		else if (player.non_pre_pos == "골키퍼") {
			player.part_weight += pre_goalkeeper;
		}
	}


}

// 배열의 요소를 표시하는 함수
template <typename T>
void DisplayArray(const vector<T>& arr) {
	for (const auto& elem : arr) {
		cout << elem << " ";
	}
	cout << endl;
}
