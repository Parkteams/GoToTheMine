#pragma once
class Player
{
public:
	//����ġ
	int Exp = 0;

	//�÷��̾� ����
	int Lv = 1;

	int Str = 10 + 2 * Lv;
	int Dex = 10 + Lv;
	int Tol = 0 + 2 * Lv;
	int Tec = 10 + 2*Lv;
	int Res = 0 + Lv;

	//�÷��̾� ������
	int Att = Str * 2 + 100;
	int Hp = Tol * 50 + 1000;
	int HpRc = Tol;
	int Sm = Tec + 50;
	int SmRc = Tec;
	int AttSp = Dex + 10;
	int Dd = Res;

	//�÷��̾� ����â
	void PlayerPrint();

	//���� ��ȭ������ �ɷ�ġ �缳��
	void StatPoint();


};

