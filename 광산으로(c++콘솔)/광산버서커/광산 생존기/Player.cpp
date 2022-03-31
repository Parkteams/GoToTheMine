#include "stdafx.h"
#include "Player.h"

void Player::PlayerPrint()
{
	cout << "레벨: " << Lv << endl;
	cout << "전투력" << endl;
	cout << "공격력: " << Att << '\t' << "체력: " << Hp << endl;
	cout << "치유량: " << HpRc << '\t' << "스태미너: " << Sm << endl;
	cout << "스태미너회복량" << SmRc << endl;
	cout << "공격속도" << AttSp << '\t' << "피해감소량" << Dd << endl;
	cout << endl;
	cout << "스탯" << endl;
	cout << "타격력: " << Str << '\t' << "민첩함" << Dex << endl;
	cout << "인내심: " << Tol << '\t' << "기술" << Tec << endl;
	cout << "뚝심: " << Res << endl;
}

void Player::StatPoint()
{
	Att = Str * 2 + 100;
	Hp = Tol * 50 + 1000;
	HpRc = Tol;
	Sm = Tec + 50;
	SmRc = Tec;
	AttSp = Dex + 10;
	Dd = Res;
}
