#include"stdafx.h"
#include "Inven.h"
#include "Function.h"
#include "Monster.h"
#include "Windows.h"



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//각종 전역변수들
//인벤토리
vector<Item*>Inven;


//플레이어 돈
int g_PlayerMoney = 1000;


//플레이어 구현
Player Pl;

//상점관련 변수
int strcount = 0;
int dexcount = 0;
int tolcount = 0;
int teccount = 0;
int rescount = 0;

//스킬 해제
void SkillOpen(int PL_LV)
{
	switch (PL_LV)
	{
	case 2:
		cout << "레벨2가 되어 기술 막기를 습득합니다" << endl << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl << "막기는 공격과 같이 쓸수있다" << endl;
		break;
	case 3:
		cout << "레벨3가 되어 기술 기절시키기를 습득합니다" << endl << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		break;
	case 5:
		cout << "레벨5이 되어 기술 꿰뚫기를 습득합니다" << endl << "꿰뚫기: 이번 공격이 3배의 피해를 입힙니다 / 스태미너: 30" << endl;
		break;
	case 10:
		cout << "최고 레벨에 도달했습니다." << endl;
		cout << "레벨10이 되어 기술 장풍을 습득합니다" << endl << "장풍: 이번 공격이 7배의 피해를 입힙니다 / 스태미너: 60" << endl;
		break;
	}
}

//아이템 구매에따른 능력치 재설정
void ItemPoint()
{
	Pl.Str = Pl.Str + strcount;
	Pl.Dex = Pl.Dex + dexcount;
	Pl.Tol = Pl.Tol + tolcount;
	Pl.Tec = Pl.Tec + teccount;
	Pl.Res = Pl.Res + rescount;
}


//지역탐사
void Searching(int CASE)
{
	switch (CASE)
	{
	case 0:
		cout << "당신은 저만치에서 금빛을 발견합니다" << endl;
		cout << "찾아보니 그곳에는 금이 있었습니다" << endl;
		cout << "500G를 획득합니다" << endl;
		g_PlayerMoney += 500;
		break;
	case 1:
		cout << "당신은 저만치에서 금빛을 발견합니다" << endl;
		cout << "찾아보니 그곳에는 먼지밖에 없었습니다. " << endl;
		cout << "그때 뒤에서 갑자기 황금망토를 두른 도둑이 나타나더니 내 돈주머니를 가져갑니다." << endl;
		cout << "500G를 잃습니다" << endl;
		g_PlayerMoney -= 500;
		break;
	case 2:
		cout << "당신은 용사의 석상을 발견합니다" << endl;
		cout << "성스러운 힘이 느껴집니다 " << endl;
		cout << "뚝심이 영구적으로 2 늘어납니다" << endl;
		Pl.Res += 2;
		Pl.StatPoint();
		break;
	case 3:
		cout << "당신은 광전사의 석상을 발견합니다" << endl;
		cout << "강렬한 힘이 느껴집니다 " << endl;
		cout << "타격력이 영구적으로 2 늘어납니다" << endl;
		Pl.Str += 2;
		Pl.StatPoint();
		break;
	case 4:
		cout << "당신은 저만치에서 금빛을 발견합니다" << endl;
		cout << "찾아보니 그곳에는 먼지밖에 없었습니다. " << endl;
		cout << "그때 뒤에서 갑자기 황금망토를 두른 도둑이 나타나더니 내 돈주머니를 가져갑니다." << endl;
		cout << "500G를 잃습니다" << endl;
		g_PlayerMoney -= 500;
		break;
	case 5:
		cout << "당신은 저만치에서 금빛을 발견합니다" << endl;
		cout << "찾아보니 그곳에는 엄청난 금이 있었습니다. " << endl;
		cout << "1000G를 획득합니다" << endl;
		g_PlayerMoney += 1000;
		break;
	}
}


int main()
{

	srand(static_cast<unsigned int>(time(NULL)));


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//몬스터 구현
	Monster** Cute;
	Cute = new Monster*[16];

	for (int i = 0; i < 16; i++)
	{
		Cute[i] = nullptr;
	}

	Monster* pCuteMonster;

	pCuteMonster = new Monster(100,30,300,30,10,5,0);
	pCuteMonster->kind = "언데드";
	pCuteMonster->name = "스켈레톤아처(독)";
	//난투
	Cute[0] = pCuteMonster;

	pCuteMonster = new Monster(0, 20, 400, 30, 10, 80, 0);
	pCuteMonster->kind = "언데드";
	pCuteMonster->name = "좀비(독)";
	//해독제 필수  ㅣ1
	Cute[1] = pCuteMonster;

	pCuteMonster = new Monster(80,25,800,10,20,0,100);
	pCuteMonster->kind = "언데드";
	pCuteMonster->name = "데스나이트(출혈)";
	//붕대 필수  ㅣ2
	Cute[2] = pCuteMonster;

	pCuteMonster = new Monster(150, 80, 500, 0, 0, 0, 0);
	pCuteMonster->kind = "인간";
	pCuteMonster->name = "자객(속도)";
	//막기 필수 ㅣ3
	Cute[3] = pCuteMonster;

	pCuteMonster = new Monster(220, 20, 1000, 10, 10, 0, 0);
	pCuteMonster->kind = "인간";
	pCuteMonster->name = "산적장사(강공)";
	//속도, ㅣ3
	Cute[4] = pCuteMonster;

	pCuteMonster = new Monster(600, 20, 1400, 200, 20, 100, 0);
	pCuteMonster->kind = "인간";
	pCuteMonster->name = "산적우두머리(초강공, 초재생, 강독)";
	//기절시키기 or 막기 필수, 해독제 필수, ㅣ4
	Cute[5] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1200, 10, 0, 0, 50);
	pCuteMonster->kind = "고블린";
	pCuteMonster->name = "고블린 전사(출혈)";
	//붕대 필수 ㅣ5
	Cute[6] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1300, 10, 0, 0, 50);
	pCuteMonster->kind = "고블린";
	pCuteMonster->name = "광란의 고블린(출혈)";
	//막기, 붕대 필수  ㅣ5
	Cute[7] = pCuteMonster;

	pCuteMonster = new Monster(300, 30, 2000, 30, 0, 0, 100);
	pCuteMonster->kind = "고블린";
	pCuteMonster->name = "고블린 챔피언(강공, 출혈)";
	//막기, 붕대, 꿰뚫기 필수 ㅣ6
	Cute[8] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1000, 10, 0, 0, 0);
	pCuteMonster->kind = "코볼트";
	pCuteMonster->name = "코볼트 점쟁이(독)";
	//막기, 해독제, 꿰뚫기 필수 ㅣ7
	Cute[9] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1500, 0, 0, 0, 0);
	pCuteMonster->kind = "코볼트";
	pCuteMonster->name = "코볼트 광전사(강공, 속도)";
	//막기, 해독제, 꿰뚫기 필수 ㅣ7
	Cute[10] = pCuteMonster;

	pCuteMonster = new Monster(200, 90, 2000, 0, 0, 0, 0);
	pCuteMonster->kind = "코볼트";
	pCuteMonster->name = "코볼트 대왕(강공, 강속도)";
	//막기 절대 필수 ㅣ8
	Cute[11] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 2000, 80, 30, 0, 0);
	pCuteMonster->kind = "오우거";
	pCuteMonster->name = "오우거 전사(단단함, 초재생)";
	//막기, 꿰뚫기 필수 ㅣ9
	Cute[12] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 3000, 100, 30, 0, 50);
	pCuteMonster->kind = "오우거";
	pCuteMonster->name = "오우거 마법사(단단함, 초재생, 독)";
	//막기, 해독제, 꿰뚫기 필수 ㅣ9
	Cute[13] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 5000, 150, 30, 0, 0);
	pCuteMonster->kind = "오우거";
	pCuteMonster->name = "트윈헤드오우거(단단함, 초재생, 독)";
	//막기, 해독제, 꿰뚫기 필수 ㅣ10
	Cute[14] = pCuteMonster;

	pCuteMonster = new Monster(1000, 90, 10000, 0, 50, 50, 100);
	pCuteMonster->kind = "악마";
	pCuteMonster->name = "개발자(강공, 강속도, 초출혈, 초독, 단단함)";
	//몰라 ㅣ10
	Cute[15] = pCuteMonster;

	//몬스터들 담을 변수
	int battle1, battle2, battle3, battle4, battle5, battle6, battle7, battle8, battle9, battle10
		, battle11, battle12, battle13, battle14, battle15, battle16;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//상점 구현
	Item** Shop;
	Shop = new Item*[40];

	for (int i = 0; i < 40; i++)
	{
		Shop[i] = nullptr;
	}

	Weapon* pShopWeapon;
	Head*  pShopHead;
	Hand*  pShopHand;
	Chest*  pShopChest;
	Leg*  pShopLeg;
	Foot*  pShopFoot;
	Ring*  pShopRing;
	Tem*  pShopTem;

	pShopTem = new Tem(0, 0, 400, 0);
	pShopTem->name = "체력 포션";
	pShopTem->price = 300;

	Shop[1] = pShopTem;

	pShopTem = new Tem(0, 0, 0, 30);
	pShopTem->name = "스태미너 포션";
	pShopTem->price = 300;

	Shop[2] = pShopTem;

	pShopTem = new Tem(1000,0,0,0);
	pShopTem->name = "해독제";
	pShopTem->price = 300;

	Shop[3] = pShopTem;

	pShopTem = new Tem(0,1000,0,0);
	pShopTem->name = "붕대";
	pShopTem->price = 300;

	Shop[4] = pShopTem;

	pShopWeapon = new Weapon(2, 5, 0, 0, 0);
	pShopWeapon->name = "나무꾼의 도끼";
	pShopWeapon->price = 500;

	Shop[8] = pShopWeapon;

	pShopWeapon = new Weapon(3, 4, 0, 0, 0);
	pShopWeapon->name = "종자의 양손검";
	pShopWeapon->price = 500;

	Shop[9] = pShopWeapon;

	pShopWeapon = new Weapon(7, 0, 0, 2, 0);
	pShopWeapon->name = "사냥꾼의 창";
	pShopWeapon->price = 500;

	Shop[10] = pShopWeapon;

	pShopWeapon = new Weapon(6, 10, 0, 0, 0);
	pShopWeapon->name = "바이킹의 양손도끼";
	pShopWeapon->price = 2000;

	Shop[11] = pShopWeapon;

	pShopWeapon = new Weapon(8, 8, 0, 0, 0);
	pShopWeapon->name = "십자군의 크루세이더";
	pShopWeapon->price = 2000;

	Shop[12] = pShopWeapon;

	pShopWeapon = new Weapon(15, 0, 0, 5, 0);
	pShopWeapon->name = "업군용사의 장창";
	pShopWeapon->price = 2000;

	Shop[13] = pShopWeapon;

	pShopWeapon = new Weapon(20, 30, 0, 0, 5);
	pShopWeapon->name = "둠해머,";
	pShopWeapon->price = 10000;

	Shop[14] = pShopWeapon;

	pShopWeapon = new Weapon(25, 25, 20, 0, 0);
	pShopWeapon->name = "진은검";
	pShopWeapon->price = 10000;

	Shop[15] = pShopWeapon;

	pShopWeapon = new Weapon(40, 10, 0, 10, 0);
	pShopWeapon->name = "스타피어";
	pShopWeapon->price = 10000;

	Shop[16] = pShopWeapon;

	pShopWeapon = new Weapon(100,100,100,100,100);
	pShopWeapon->name = "엑스칼리버";
	pShopWeapon->price = 100000000;

	Shop[17] = pShopWeapon;

	pShopHand = new Hand(0, 3, 3, 0, 1);
	pShopHand->name = "가죽장갑";
	pShopHand->price = 500;

	Shop[18] = pShopHand;

	pShopHand = new Hand(0, 5, 8, 0, 3);
	pShopHand->name = "투쟁의 팔목 덮개";
	pShopHand->price = 2000;

	Shop[19] = pShopHand;

	pShopHand = new Hand(0, 30, 30, 0, 10);
	pShopHand->name = "가위손";
	pShopHand->price = 10000;

	Shop[20] = pShopHand;

	pShopHead = new Head(0, 0, 5, 0, 2);
	pShopHead->name = "철투구";
	pShopHead->price = 500;

	Shop[21] = pShopHead;

	pShopHead = new Head(0, 0, 15, 0, 5);
	pShopHead->name = "실버 헬름";
	pShopHead->price = 2000;

	Shop[22] = pShopHead;

	pShopHead = new Head(0, 0, 50, 0, 10);
	pShopHead->name = "은빛 독수리";
	pShopHead->price = 10000;

	Shop[23] = pShopHead;

	pShopChest = new Chest(0, 0, 6, 0, 2);
	pShopChest->name = "참나무흉갑";
	pShopChest->price = 500;

	Shop[24] = pShopChest;

	pShopChest = new Chest(0, 0, 15, 0, 5);
	pShopChest->name = "검은무쇠흉갑";
	pShopChest->price = 2000;

	Shop[25] = pShopChest;

	pShopChest = new Chest(0, 0, 60, 0, 10);
	pShopChest->name = "블랙체인(상)";
	pShopChest->price = 10000;

	Shop[26] = pShopChest;

	pShopLeg = new Leg(0, 0, 6, 0, 2);
	pShopLeg->name = "참나무갑반";
	pShopLeg->price = 500;

	Shop[27] = pShopLeg;

	pShopLeg = new Leg(0, 0, 15, 0, 5);
	pShopLeg->name = "검은무쇠갑반";
	pShopLeg->price = 2000;

	Shop[28] = pShopLeg;

	pShopLeg = new Leg(0, 0, 60, 0, 10);
	pShopLeg->name = "블랙체인(하)";
	pShopLeg->price = 10000;

	Shop[29] = pShopLeg;

	pShopFoot = new Foot(0, 0, 5, 0, 2);
	pShopFoot->name = "가죽장화";
	pShopFoot->price = 500;

	Shop[30] = pShopFoot;

	pShopFoot = new Foot(0, 0, 15, 0, 5);
	pShopFoot->name = "아이론슈즈";
	pShopFoot->price = 2000;

	Shop[31] = pShopFoot;

	pShopFoot = new Foot(0, 0, 50, 0, 10);
	pShopFoot->name = "나이트워커";
	pShopFoot->price = 10000;

	Shop[32] = pShopFoot;

	pShopRing = new Ring(0, 0, 8, 15, 0);
	pShopRing->name = "철 반지";
	pShopRing->price = 500;

	Shop[33] = pShopRing;

	pShopRing = new Ring(0, 0, 15, 25, 0);
	pShopRing->name = "현자의 반지";
	pShopRing->price = 2000;

	Shop[34] = pShopRing;

	pShopRing = new Ring(0, 0, 50, 45, 10);
	pShopRing->name = "불멸의 반지";
	pShopRing->price = 8000;

	Shop[35] = pShopRing;






	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	




	//전투관련 변수
	int Plbattlecount = 0;
	int Mobattlecount = 0;
	int Poisoncount = 0;
	int Bleedcount = 0;
	int PlBattleGage = 100;
	int MoBattleGage = 100;
	int M_HEALTH;
	int P_HEALTH = Pl.Hp;
	int P_STAMINA = Pl.Sm;
	int P_DAMAGEDECLINE = Pl.Dd;

	//게임관련 변수
	int input;
	int choosenum;
	int playcount = 0;
	int count = 0;
	bool istrue = true;

	//홈화면관련 변수
	int FindCount = 0;



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







	cout << "회생자;;;;;;;;;;;;;;;;;" << endl;
	cout << "1 시작하기" << endl << "2 크레딧" << endl << "3 나가기" << endl;

	cin >> input;

	if (input == 1)
	{
		while (istrue)
		{
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//도입부 시작
			system("cls");


			cout << "당신은 눈을 떠보니 어느 외딴곳에 쓰러져있었다." << endl;
			/*Sleep(2000);*/
			cout << "당신은 당신이 누구인지 기억해보려하지만 기억이나지않는다." << endl;
			/*Sleep(2000);*/
			cout << "하지만 단한가지, 저곳 광산을 보자 피가 끓기 시작했다." << endl;
			/*Sleep(2000);*/
			cout << "당신은 당신을 주체하지못하고, 광산으로 향했다." << endl << endl;

			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			cout << endl;

			cout << "광산으로 향하는 길이 보인다." << endl
				<< "광산으로 가려면 무덤과 위험해보이는 산을 지나야할듯하다." << endl << endl;

			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//광산 입던 전 무덤
			system("cls");
			/*Sleep(2000);*/
			cout << "무덤에 진입했다" << endl;
			/*Sleep(2000);*/
			cout << "무덤은 아무도 관리한 흔적이 없어보인다." << endl;
			/*Sleep(2000);*/
			cout << "곳곳의 무덤들은 누구에게 마치 도굴당하기라도 했는지 파헤쳐져있었다." << endl;
			/*Sleep(2000);*/
			cout << "무덤에 들어간지 시간이 좀 지나자 무덤이 파헤쳐진 이유를 알수있었다." << endl;
			/*Sleep(3000);*/
			cout << "파헤쳐진게 아니라 망자가 파고 나온것이였다는것을." << endl;



			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle1 = 0;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}
						
						}



						
					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			
			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "첫번째 전투를 훌륭히 마치셨습니다" << endl << "이제 홈화면을 보여드리겠습니다." << endl << "홈 화면에선 내상태 확인, 상점이용" << endl << "기술,  지역탐색, 몬스터 도감을 이용하실수 있습니다." << "즐거운 게임하시기를 바랍니다." << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 묘지 초입부 누군가의 무덤 앞" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
									
								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);
								
							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			//묘지1-2구역 진입
			system("cls");
			/*Sleep(2000);*/
			cout << "무덤에 들어온지 이틀째이다" << endl;
			/*Sleep(2000);*/
			cout << "슬슬 스켈레톤들이 점점 안보이기 시작했다" << endl;
			/*Sleep(2000);*/
			cout << "그때 뒤에서 저주받은 망자 좀비 소리가 들렸다" << endl;




			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle2 = battle1;
			battle1 = 1;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "300exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 300;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "여기서 잠시 정비좀 하고 갈까?" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 묘지 중턱 어딘가" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//묘지1-3구역 진입
			system("cls");
			/*Sleep(2000);*/
			cout << "무덤에 들어온지도 삼일째 슬슬 무덤의 끝이 보이는듯하다" << endl;
			/*Sleep(2000);*/
			cout << "무덤 출구에 거의 다왔을때 기이한 비석이 눈에 띄였다" << endl;
			/*Sleep(2000);*/
			cout << "비석에 지나갈때쯤 비석이 쪼개지며 제일 마주치기 싫은 상대가 나왔다" << endl;
			/*Sleep(2000);*/
			cout << "데스나이트다" << endl;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle3 = battle1;
			battle1 = 2;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "이제 묘지에서의 정비도 이게 마지막이군" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 묘지의 끝" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			// 산길 (1-1) 구역 진입

		
			system("cls");
			cout << "묘지를 나와 위험한 산에 도달했다" << endl << "곳곳에 얼마 되지 않은 시체들이 눈에 보였다" << endl <<
				"시체에 남긴 표시를 보니 이 산은 꽤나 유명한 산적무리의 소굴이 된듯하다" << endl <<
				"조심해야겠다고 생각한 순간 뒤에서 단검을 쥔 누군가가 나를 덮쳤다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle4 = battle1;
			battle1 = 3;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "400exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 400;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "산길을 가다보니 꽤넓은 공터가보였다. 여기서 정비를 해야겠다." << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 산 중턱 어딘가의 공터" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// 산길 (1-2) 구역 진입


			system("cls");
			cout << "어느덧 산 중턱에 왔다" << endl << "곧 산적놈들이 튀어나올텐데......" << endl <<
				"이 생각을 하자마자 거대한 체구의 산적이 나왔다" << endl <<
				"공격력이 상당히 강해보인다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle5 = battle1;
			battle1 = 4;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "어느덧 산 정상이다. 작은 호수가 보였다. 여기서 휴식을 취해야겠다." << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 산 정상 한적한 호숫가" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// 산길 (1-3) 구역 진입


			system("cls");
			cout << "어느덧 광산이 바로 앞에 보이는 산 출구까지 왔다" << endl << "이제야 해방이군" << endl <<
				"그때 이런 나를 비웃기라도 하는듯 이 산의 주인이 나왔다" << endl;/* <<*/
				/*"공격력이 상당히 강해보인다" << endl;*/

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle6 = battle1;
			battle1 = 5;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "200exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 200;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "드디어 광산입구까지 왔다." << endl;
			cout << "무엇이 나를 여기까지 오게 한걸까?" << endl << "그때 이 광산의 주인의 웃음소리가 살짝 들린듯 했다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산 앞" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// 광산 (1-1) 구역 진입


			system("cls");
			cout << "광산에 들어왔다" << endl << "광산 곳곳은 예전에는 꽤나 개발되던 곳인지 곳곳에 버려진 기계 및 장비들로 가득했다" << endl <<
				"입구의 한 피로 적힌 글이 눈에 들어왔다" << endl << "우리는 건드리고야 말았다. 그것만큼은 안됐는데 건드리고야 말았다." << endl << "이제 그가 다시 이곳에 와 그것을 없앨때까지" << endl
				<< "아무도 이 곳에 들어온자는 다시는 나갈수 없으리......" << endl << "당황한 그 순간 고블린들이 덤벼왔다." << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle7 = battle1;
			battle1 = 6;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "300exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 300;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "광산의 끝없는 갱도로 가다보니, 전에 이곳 인부들이 사용한듯한 휴게실을 발견했다." << endl;
			cout << "이곳에서 잠시 정비해야겠다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산1층 어딘가의 휴게실" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// 광산 (1-2) 구역 진입


			system("cls");
			cout << "광산은 매우 깊었다" << endl << "가도가도 끝이 없이 이어졌다" << endl <<
				"그때 지금까지 죽여왔던 고블린과는 확연히 다르게 생긴 놈이 앞을 막아섰다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle8 = battle1;
			battle1 = 7;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "700exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 700;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "체력이 한계에 달했다" << endl;
			cout << "이곳에서 잠시 정비해야겠다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산1층 어딘가" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








			// 광산 (1-3) 구역 진입


			system("cls");
			cout << "뭐지 이 광산?" << endl << "그때 이 광산이 한층으로 이루어진게 아니라는 것을 알수있었다." << endl <<
				"내려가는 길이군" << endl << "그 앞에는 나를 이곳에 내려보낼수 없다는 듯한 표정의 덩치가 한마리 나타났다.";

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle9 = battle1;
			battle1 = 8;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "2000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 2000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "너무 힘든전투였다" << endl;
			cout << "내려가기전에 잠시 휴식해야겠다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산2층진입전" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









			// 광산 (2-1) 구역 진입


			system("cls");
			cout << "어마어마하군" << endl << "이곳부터는 사람이 만든곳이 아니라는것이 느껴졌다." << endl <<
				"무엇보다 너무 길이 작았다." << endl << "그래, 이곳은 인간들이 나가고 들어온 그 놈들의 서식지임에 틀림없다" << endl << "그 놈들이 아니나다를까 나타났다";

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle10 = battle1;
			battle1 = 9;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "이 작은길들은 사람한명이 딱 지나갈수 있는 너비에 높이였다" << endl;
			cout << "그때 코볼트들이 쓰는듯한 방이 나왔다" << endl;
			cout << "코볼트들은 내가 오면서 다 죽여 빈방이된듯하다." << endl;
			cout << "그럼 이제 여긴 내방" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산2칭 코볼트들의방(내방?)" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








			// 광산 (2-2) 구역 진입


			system("cls");
			cout << "좁다좁아" << endl << "뭐랄까 너무 답답했다" << endl << "코볼트 놈들도 생쥐마냥 끝없이 나왔다" << endl <<
				"그때 눈에 핏발이 선 코볼트 한마리가 다가왔다" << endl << "강해보인다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle11 = battle1;
			battle1 = 10;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "400exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 400;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "이방도 내가 오면서 다 죽여 빈방이된듯하다." << endl;
			cout << "그럼 이제 여기도 내방" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산2층 불쌍한 코볼트들의 또 다른 방(내방)" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					Cute[battle11]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// 광산 (2-3) 구역 진입


			system("cls");
			cout << "광산2층 끄트머리의 차원문 하나를 발견했다" << endl << "그 앞은 아니나다를까" << endl << "엄청나게 강해보이는 코볼트 한마리가 지키고있었다" << endl <<
				"이곳은 안들어가는게 좋을거다 인간.." << endl << "내가 싫다고 말하자 그놈은 한숨을 쉬며 내게 다가오기 시작했다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle12 = battle1;
			battle1 = 11;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "무척 강한놈이였다" << endl;
			cout << "차원문에 들어가기전에 만반의 준비를 해야겠다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 광산2층 차원문 앞" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					Cute[battle11]->AllPrint();
					Cute[battle12]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// 어딘가 (1-1) 구역 진입


			system("cls");
			cout << "제길!..머리가 깨질것같다" << endl << "차원문에 들어오니 그 놈의 웃음소리가 점점 크게들려온다" << endl << "난 그 놈을 죽이기 위해 이곳에 온걸것이다" << endl <<
				"그때 어지간한 건물만한 놈들이 튀어나왔다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle13 = battle1;
			battle1 = 12;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "쉬어야돼...." << endl;
			cout << "나는 필사적으로 그놈들 눈에는 작은 구멍일 어떤 곳에 들어갔다. 다행히 이곳에 적은 없는듯하다." << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 어딘가의 어딘가" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					Cute[battle11]->AllPrint();
					Cute[battle12]->AllPrint();
					Cute[battle13]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// 어딘가 (1-2) 구역 진입


			system("cls");
			cout << "두통이 점점 심해진다" << endl << "점점 이성을 잃어간다" << endl << "빨리 가야겠다" << endl <<
				"그때 특이하게 생긴 고깔모자를 쓴 집채만한 오우거가 나타났다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle14 = battle1;
			battle1 = 13;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "2000G" << endl;
				cout << "경험치: " << "1000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "정신, 체력 모두 한계에 달했다" << endl;
			cout << "나는 필사적으로 처음에 쉬었던 곳과는 다른 곳을 찾아 들어갔다. 다행히 이곳에도 적은 없는듯하다." << endl;
			cout << "그때 문득 누가 이런것을 왜 만들었을까라는 생각이 들었다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 어딘가의 어딘가2" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					Cute[battle11]->AllPrint();
					Cute[battle12]->AllPrint();
					Cute[battle13]->AllPrint();
					Cute[battle14]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// 어딘가 (1-3) 구역 진입


			system("cls");
			cout << "점점 잃었던 이성을 회복하고 있는것같다" << endl << "왜일까?" << endl << "그놈이 이제는 나를 향해 더이상 웃지 않는듯하다" << endl <<
				"곧 그놈을 만날것같다" << endl << "그때 머리 두개인 왠만한 성만한 오우거놈이 나타났다" << endl << "그놈은 아니네" << endl << "나는 무기를 들었다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle15 = battle1;
			battle1 = 14;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "5000G" << endl;
				cout << "경험치: " << "3000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 3000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 5000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "입에서 피가 솓구쳐나왔다" << endl;
			cout << "체력적으로 한계에 달했다" << endl;
			cout << "트윈헤드오우거가 지키고 있던곳을 지나니 거대한 장벽이 나타났고" << endl;
			cout << "그 밑에 내가 들어갈만한 문하나가 보였다" << endl;
			cout << "그놈을 저 문을 지나면 만날수 있을것같다" << endl;
			cout << "나는 최후의 정비를 시작했다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//홈 화면
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "현재위치: 어딘가의 거대한 장벽 그 밑의 문 앞" << endl;
				cout << "1 상태창  ||  2 상점  ||  3 기술  ||  4 지역탐색  ||  5 몬스터 도감  ||  6 다음구역으로" << endl;

				cout << "하실 행동을 입력해주세요" << endl;
				cin >> input;
				//상태창
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "소지금: " << g_PlayerMoney << "G" << endl;
					cout << "내 아이템" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "번 아이템" << endl;
						Inven[i]->Print();
					}
					cout << "돌아가려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				//상점
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "소지금: " << g_PlayerMoney << "G" << endl;
						cout << "내 아이템" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "번 아이템" << endl;
							Inven[i]->Print();
						}

						cout << "1 쇼핑하기  ||  2 홈화면으로" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "상점에 오신걸 환영 합니다." << endl;
						cout << "1.전부보기 , 2. 무기 , 3. 투구 ,4. 팔목보호대" << endl;
						cout << "5. 흉갑, 6.갑반, 7.신발, 8. 반지 9. 잡화" << endl;

						cin >> input;

						switch (input)
						{
						case 1:
							PrintShop(ITEM, Shop);
							break;
						case 2:
							PrintShop(WEAPON, Shop);
							break;
						case 3:
							PrintShop(HEAD, Shop);
							break;
						case 4:
							PrintShop(HAND, Shop);
							break;
						case 5:
							PrintShop(CHEST, Shop);
							break;
						case 6:
							PrintShop(LEG, Shop);
							break;
						case 7:
							PrintShop(FOOT, Shop);
							break;
						case 8:
							PrintShop(RING, Shop);
							break;
						default:
							PrintShop(TEM, Shop);
							break;

						}
						cout << "1.구매 2. 판매" << endl;

						cin >> input;

						//구매
						if (input == 1)
						{
							cout << "구매하실 아이템을 입력하세요" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "금이 부족합니다" << endl;
							}
							else
							{
								if (Shop[input]->type == WEAPON)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == WEAPON)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Weapon(*(Weapon*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == WEAPON)
											{
												strcount += dynamic_cast<Weapon*>(Inven[i])->str;
												dexcount += dynamic_cast<Weapon*>(Inven[i])->dex;
												tolcount += dynamic_cast<Weapon*>(Inven[i])->tol;
												teccount += dynamic_cast<Weapon*>(Inven[i])->tec;
												rescount += dynamic_cast<Weapon*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "무기가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == HEAD)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HEAD)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Head(*(Head*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HEAD)
											{
												strcount += dynamic_cast<Head*>(Inven[i])->str;
												dexcount += dynamic_cast<Head*>(Inven[i])->dex;
												tolcount += dynamic_cast<Head*>(Inven[i])->tol;
												teccount += dynamic_cast<Head*>(Inven[i])->tec;
												rescount += dynamic_cast<Head*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "투구가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}

								else if (Shop[input]->type == HAND)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == HAND)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Hand(*(Hand*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == HAND)
											{
												strcount += dynamic_cast<Hand*>(Inven[i])->str;
												dexcount += dynamic_cast<Hand*>(Inven[i])->dex;
												tolcount += dynamic_cast<Hand*>(Inven[i])->tol;
												teccount += dynamic_cast<Hand*>(Inven[i])->tec;
												rescount += dynamic_cast<Hand*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "팔목보호대가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == CHEST)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == CHEST)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Chest(*(Chest*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == CHEST)
											{
												strcount += dynamic_cast<Chest*>(Inven[i])->str;
												dexcount += dynamic_cast<Chest*>(Inven[i])->dex;
												tolcount += dynamic_cast<Chest*>(Inven[i])->tol;
												teccount += dynamic_cast<Chest*>(Inven[i])->tec;
												rescount += dynamic_cast<Chest*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "흉갑이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == LEG)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == LEG)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Leg(*(Leg*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == LEG)
											{
												strcount += dynamic_cast<Leg*>(Inven[i])->str;
												dexcount += dynamic_cast<Leg*>(Inven[i])->dex;
												tolcount += dynamic_cast<Leg*>(Inven[i])->tol;
												teccount += dynamic_cast<Leg*>(Inven[i])->tec;
												rescount += dynamic_cast<Leg*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "갑반이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == FOOT)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == FOOT)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Foot(*(Foot*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == FOOT)
											{
												strcount += dynamic_cast<Foot*>(Inven[i])->str;
												dexcount += dynamic_cast<Foot*>(Inven[i])->dex;
												tolcount += dynamic_cast<Foot*>(Inven[i])->tol;
												teccount += dynamic_cast<Foot*>(Inven[i])->tec;
												rescount += dynamic_cast<Foot*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "신발이 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == RING)
								{
									int Count = 0;
									for (int i = 0; i < Inven.size(); i++)
									{
										if (Inven[i]->type == RING)
										{
											Count += 1;
										}
									}
									if (Count == 0)
									{
										Item* temp = new Ring(*(Ring*)Shop[input]);
										Inven.push_back(temp);
										g_PlayerMoney -= Shop[input]->price;

										//구매한 아이템 능력치 구현
										for (int i = 0; i < Inven.size(); i++)
										{
											if (Inven[i]->type == RING)
											{
												strcount += dynamic_cast<Ring*>(Inven[i])->str;
												dexcount += dynamic_cast<Ring*>(Inven[i])->dex;
												tolcount += dynamic_cast<Ring*>(Inven[i])->tol;
												teccount += dynamic_cast<Ring*>(Inven[i])->tec;
												rescount += dynamic_cast<Ring*>(Inven[i])->res;
											}
										}
										ItemPoint();
										Pl.StatPoint();
									}
									else
									{
										cout << "반지가 이미 있습니다" << endl;
										Sleep(1000);
									}
								}
								else if (Shop[input]->type == TEM)
								{

									Item* temp = new Tem(*(Tem*)Shop[input]);
									Inven.push_back(temp);
									g_PlayerMoney -= Shop[input]->price;
								}
							}
						}
						//팔기
						else
						{
							cout << "판매 하실 아이템을 입력하세요(0.8배)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "해당 아이템이 존재하지않습니다" << endl;
							}
							else
							{
								//판매할 아이템 능력치 구현
								if (Inven[input]->type == WEAPON)
								{
									strcount -= dynamic_cast<Weapon*>(Inven[input])->str;
									dexcount -= dynamic_cast<Weapon*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Weapon*>(Inven[input])->tol;
									teccount -= dynamic_cast<Weapon*>(Inven[input])->tec;
									rescount -= dynamic_cast<Weapon*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Weapon*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Weapon*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Weapon*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Weapon*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Weapon*>(Inven[input])->res;
								}
								if (Inven[input]->type == HEAD)
								{
									strcount -= dynamic_cast<Head*>(Inven[input])->str;
									dexcount -= dynamic_cast<Head*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Head*>(Inven[input])->tol;
									teccount -= dynamic_cast<Head*>(Inven[input])->tec;
									rescount -= dynamic_cast<Head*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Head*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Head*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Head*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Head*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Head*>(Inven[input])->res;
								}
								if (Inven[input]->type == HAND)
								{
									strcount -= dynamic_cast<Hand*>(Inven[input])->str;
									dexcount -= dynamic_cast<Hand*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Hand*>(Inven[input])->tol;
									teccount -= dynamic_cast<Hand*>(Inven[input])->tec;
									rescount -= dynamic_cast<Hand*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Hand*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Hand*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Hand*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Hand*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Hand*>(Inven[input])->res;
								}
								if (Inven[input]->type == CHEST)
								{
									strcount -= dynamic_cast<Chest*>(Inven[input])->str;
									dexcount -= dynamic_cast<Chest*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Chest*>(Inven[input])->tol;
									teccount -= dynamic_cast<Chest*>(Inven[input])->tec;
									rescount -= dynamic_cast<Chest*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Chest*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Chest*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Chest*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Chest*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Chest*>(Inven[input])->res;
								}
								if (Inven[input]->type == LEG)
								{
									strcount -= dynamic_cast<Leg*>(Inven[input])->str;
									dexcount -= dynamic_cast<Leg*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Leg*>(Inven[input])->tol;
									teccount -= dynamic_cast<Leg*>(Inven[input])->tec;
									rescount -= dynamic_cast<Leg*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Leg*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Leg*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Leg*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Leg*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Leg*>(Inven[input])->res;
								}
								if (Inven[input]->type == FOOT)
								{
									strcount -= dynamic_cast<Foot*>(Inven[input])->str;
									dexcount -= dynamic_cast<Foot*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Foot*>(Inven[input])->tol;
									teccount -= dynamic_cast<Foot*>(Inven[input])->tec;
									rescount -= dynamic_cast<Foot*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Foot*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Foot*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Foot*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Foot*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Foot*>(Inven[input])->res;
								}
								if (Inven[input]->type == RING)
								{
									strcount -= dynamic_cast<Ring*>(Inven[input])->str;
									dexcount -= dynamic_cast<Ring*>(Inven[input])->dex;
									tolcount -= dynamic_cast<Ring*>(Inven[input])->tol;
									teccount -= dynamic_cast<Ring*>(Inven[input])->tec;
									rescount -= dynamic_cast<Ring*>(Inven[input])->res;
									Pl.Str -= dynamic_cast<Ring*>(Inven[input])->str;
									Pl.Dex -= dynamic_cast<Ring*>(Inven[input])->dex;
									Pl.Tol -= dynamic_cast<Ring*>(Inven[input])->tol;
									Pl.Tec -= dynamic_cast<Ring*>(Inven[input])->tec;
									Pl.Res -= dynamic_cast<Ring*>(Inven[input])->res;
								}
								Pl.StatPoint();
								g_PlayerMoney += static_cast<int>(Inven[input]->price * 0.8f);
								Inven.erase(Inven.begin() + input);

							}
						}
					}

					continue;

				}

				//기술
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}

				//지역탐색
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "이 구역은 이미 수색했습니다." << endl;
						cout << "계속하려면 아무키나 누르시오";
						cin >> choosenum;
						continue;
					}
				}
				//몬스터 도감
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					Cute[battle8]->AllPrint();
					Cute[battle9]->AllPrint();
					Cute[battle10]->AllPrint();
					Cute[battle11]->AllPrint();
					Cute[battle12]->AllPrint();
					Cute[battle13]->AllPrint();
					Cute[battle14]->AllPrint();
					Cute[battle15]->AllPrint();
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// 다른차원의 공간 구역 진입


			system("cls");
			cout << "이곳은 뭐지? 문을 열었더니 자그마한 방하나가 나타났다" << endl << "그곳에는 어느 남성이 무언가를 열심히 두드리고 있었다" << endl 
				<< "그놈이 틀림없다. 나는 생각했다" << endl <<
				"그놈이 입을 열었다" << endl << "용케 여기까지 왔구나" << endl << "자 마지막 시험이다" 
				<< endl << "나는 무기를 들었다" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//전투
			Plbattlecount = 0;
			Mobattlecount = 0;
			Poisoncount = 0;
			Bleedcount = 0;
			PlBattleGage = 100;
			MoBattleGage = 100;
			battle16 = battle1;
			battle1 = 15;
			M_HEALTH = Cute[battle1]->m_Hp;
			P_HEALTH = Pl.Hp;
			P_STAMINA = Pl.Sm;
			P_DAMAGEDECLINE = Pl.Dd;
			cout << endl;
			cout << Cute[battle1]->name << "이(가) 나타났다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//배틀게이지 100되면 전투개시(플레이어에게 선공권은 줌)
				//내 턴
				if (PlBattleGage >= 100)
				{
					//스킬 막기 해제
					Pl.Dd = P_DAMAGEDECLINE;
					//배틀게이지 다시 0으로
					PlBattleGage = 0;
					//자가치유 및 자가스태미너 회복 및 독피해, 출혈피해
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Poisoncount = 0;
								Bleedcount = 0;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;
								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}


					Pl.Sm = Pl.Sm + Pl.SmRc;
					if (Pl.Sm > Pl.Tec + 50)
					{
						Pl.Sm = Pl.Tec + 50;
					}
					while (1)
					{
						system("cls");
						cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 내상태창보기  ||  2 공격하기  ||  3 기술사용  ||  4 아이템사용" << endl;
						cout << "플레이어" << endl;
						cout << "체력: " << Pl.Hp << '\t' << "당한독피해: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "당한출혈피해: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "스태미너: " << Pl.Sm << endl;
						cout << "공격속도: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//내 상태창보기
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "소지금: " << g_PlayerMoney << "G" << endl;
							cout << "내 아이템" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "번 아이템" << endl;
								Inven[i]->Print();
							}
							cout << "돌아가려면 아무키나 누르시오";
							cin >> choosenum;
							continue;
						}
						//공격
						if (input == 2)
						{
							cout << Cute[battle1]->name << "을 공격했다" << endl;
							cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "계속하려면 아무키나 누르시오";
							cin >> choosenum;
							break;
						}
						//기술
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "현재 기술이 없습니다." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 막기(sp20)  ||  2 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 2) && (Pl.Lv < 5))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else if ((Pl.Lv > 4) && (Pl.Lv < 10))
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 돌아가기" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
							else
							{
								cout << "1 막기(sp20)  ||  2 기절시키기(sp50)  ||  3 꿰뚫기(sp30) ||  4 장풍(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "상대의 다음공격을 막을 준비를 했다" << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "을 기절시켰다" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "을 꿰뚫었다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "에게 장풍을 날렸다" << endl;
									cout << "입힌 피해: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "피해 감소량: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//아이템 사용
						else
						{
							if (Inven.size() == 0)
							{
								cout << "아이템이 없습니다." << endl << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								continue;
							}
							else
							{
								count = 0;
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										count += 1;
									}
								}
								if (count == 0)
								{
									cout << "사용할수있는 아이템이 없습니다." << endl << endl;
									cout << "계속하려면 아무키나 누르시오";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "번 아이템" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 돌아가기  ||  2 아이템 사용" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "사용할 아이템을 선택해주세요" << endl;
									cin >> input;
									if (Inven[input]->name == "체력 포션")
									{
										cout << "체력 포션을 마셨다" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "스태미너 포션")
									{
										cout << "스태미너 포션을 마셨다" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "해독제")
									{
										cout << "해독제를 마셨다" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "붕대")
									{
										cout << "붕대를 둘렀다" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;

							}

						}




					}
					//플레이어 배틀카운트 증가
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//몬스터 턴
				if (MoBattleGage >= 100)
				{
					system("cls");
					//배틀게이지 다시 0으로
					MoBattleGage = 0;
					//몬스터 자가치유
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//턴
					cout << Plbattlecount + Mobattlecount << "턴" << endl << endl;
					//몬스터 공격
					cout << Cute[battle1]->name << "의 공격" << endl;

					cout << "입힌 공격피해: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "공격피해 감소량: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "입힌 독중첩" << Cute[battle1]->m_Poison << endl;
					cout << "입힌 출혈중첩" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "계속하려면 아무키나 누르시오";
					cin >> choosenum;

					//전투 끝(플레이어 패배)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "전투에서 패배했습니다..." << endl;
						cout << "1 전투 다시하기(1000G 감소)  ||  2 나가기" << endl;
						cout << "내 골드: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//전투 처음 진입상황으로 변수 조정
								Plbattlecount = 0;
								Mobattlecount = 0;
								PlBattleGage = 100;
								MoBattleGage = 100;
								Pl.Hp = P_HEALTH;
								Pl.Sm = P_STAMINA;
								Cute[battle1]->m_Hp = M_HEALTH;
								g_PlayerMoney -= 1000;

								continue;
							}
							else
							{
								cout << "돈이 충분하지 않습니다..." << endl;
								cout << "계속하려면 아무키나 누르시오";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//몬스터 배틀카운트 증가
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//배틀게이지 증가
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//전투 끝(플레이어 승리)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "이(가) 쓰러졌다" << endl;
				cout << "전리품: " << "10000G" << endl;
				cout << "경험치: " << "3000exp" << endl;
				cout << "체력, 스태미너를 회복합니다" << endl;
				Pl.Exp += 3000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "레벨업을 하였습니다." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "스탯이 오릅니다." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "여분경험치: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 10000;
			//스킬 막기 해제
			Pl.Dd = P_DAMAGEDECLINE;
			//체력, 스태미너 초기화
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;

			//몬스터 체력 초기화
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "이긴건가?" << endl;
			cout << "그 놈은 입에서 피를 흘리고 있었고 더 이상 움직이지 않았다" << endl;
			cout << "그 놈이 입을 열었다" << endl;
			cout << "넌 내 창조물이야, 대단해" << endl;
			cout << "용케 나까지 쓰러뜨렸구나" << endl;
			cout << "그 놈은 처음에 그 놈이 두드리던것의 어떤 스위치를 눌렀다" << endl;
			cout << "계속하려면 아무키나 누르시오";
			cin >> choosenum;


			
			

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			//아래 괄호가 while로 이어진 도입부로감
		}


	}
	

	if (input == 2)
	{
		cout << "크레딧: " << endl;
		cout << "sga 아카데미 |||||||||박용준||||||||||" << endl;
	}
	
	//힙 할당 데이터 제거 과정
	if (Inven.size() > 0)
	{
		for (int i = 0; i < Inven.size(); i++)
		{
			delete Inven[i];
		}
		Inven.clear();
		Inven.shrink_to_fit();
	}

	for (int i = 0; i < 40; i++)
	{
		if (Shop[i] != nullptr)
		{
			delete Shop[i];
		}
	}
	delete[] Shop;

	for (int i = 0; i < 16; i++)
	{
		if (Cute[i] != nullptr)
		{
			delete Cute[i];
		}
	}
	delete[] Cute;

	cout << "계속하려면 아무키나 누르시오";
	cin >> choosenum;

	return 0;
}