#pragma once
class Player
{
public:
	//경험치
	int Exp = 0;

	//플레이어 스탯
	int Lv = 1;

	int Str = 10 + 2 * Lv;
	int Dex = 10 + Lv;
	int Tol = 0 + 2 * Lv;
	int Tec = 10 + 2*Lv;
	int Res = 0 + Lv;

	//플레이어 전투력
	int Att = Str * 2 + 100;
	int Hp = Tol * 50 + 1000;
	int HpRc = Tol;
	int Sm = Tec + 50;
	int SmRc = Tec;
	int AttSp = Dex + 10;
	int Dd = Res;

	//플레이어 상태창
	void PlayerPrint();

	//스탯 변화에따른 능력치 재설정
	void StatPoint();


};

