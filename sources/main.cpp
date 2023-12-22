#include <windows.h>  // 콘솔창 clear 및 시간 지연을 주기위한 헤더파일

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
	// 사용자 입력 받기(쿼터수, 참여 인원, 각 쿼터당 참여 여부 
	int num_quarters, num_of_players,player_num;
	cout << "스쿼드 메이커 설정을 시작합니다.\n";
	cout << "쿼터 수를 입력해 주세요 \n";
	cin >> num_quarters;
	cout << "각 쿼터당 참여인원을 정해주세요 \n";
	cout << "풋살의 경우 6또는 5 축구의 경우 11 입력 \n";
	cin >> num_of_players;
	while (true) {
		player_num=0;
		cout << "현재 1군에 등록된 선수의 명단입니다.\n";
		GetInformation(players);
		cout << "경기에 참여하지 못하는 선수의 번호를 입력해주세요 \n";
		cout << "빠지는 선수가 없거나 수정을 마쳤다면 0을 입력해주세요\n ";
		cin >> player_num;
		if (player_num == 0) {
			break;
		}
		else {
			players[player_num - 1].is_participating = false;
		}
	}
	int user_input;
	cout << "0을 입력하면 메인 메뉴로 돌아갑니다.\n";
	cin >> user_input;
	if (user_input == 0) {
		DisplayMenu();
	}
	
}
