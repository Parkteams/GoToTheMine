#include "stdafx.h"
#include "Player.h"

void Player::PlayerPrint()
{
	cout << "����: " << Lv << endl;
	cout << "������" << endl;
	cout << "���ݷ�: " << Att << '\t' << "ü��: " << Hp << endl;
	cout << "ġ����: " << HpRc << '\t' << "���¹̳�: " << Sm << endl;
	cout << "���¹̳�ȸ����" << SmRc << endl;
	cout << "���ݼӵ�" << AttSp << '\t' << "���ذ��ҷ�" << Dd << endl;
	cout << endl;
	cout << "����" << endl;
	cout << "Ÿ�ݷ�: " << Str << '\t' << "��ø��" << Dex << endl;
	cout << "�γ���: " << Tol << '\t' << "���" << Tec << endl;
	cout << "�ҽ�: " << Res << endl;
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
