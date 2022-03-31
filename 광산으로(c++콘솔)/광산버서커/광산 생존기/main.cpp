#include"stdafx.h"
#include "Inven.h"
#include "Function.h"
#include "Monster.h"
#include "Windows.h"



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���� ����������
//�κ��丮
vector<Item*>Inven;


//�÷��̾� ��
int g_PlayerMoney = 1000;


//�÷��̾� ����
Player Pl;

//�������� ����
int strcount = 0;
int dexcount = 0;
int tolcount = 0;
int teccount = 0;
int rescount = 0;

//��ų ����
void SkillOpen(int PL_LV)
{
	switch (PL_LV)
	{
	case 2:
		cout << "����2�� �Ǿ� ��� ���⸦ �����մϴ�" << endl << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl << "����� ���ݰ� ���� �����ִ�" << endl;
		break;
	case 3:
		cout << "����3�� �Ǿ� ��� ������Ű�⸦ �����մϴ�" << endl << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		break;
	case 5:
		cout << "����5�� �Ǿ� ��� ��ձ⸦ �����մϴ�" << endl << "��ձ�: �̹� ������ 3���� ���ظ� �����ϴ� / ���¹̳�: 30" << endl;
		break;
	case 10:
		cout << "�ְ� ������ �����߽��ϴ�." << endl;
		cout << "����10�� �Ǿ� ��� ��ǳ�� �����մϴ�" << endl << "��ǳ: �̹� ������ 7���� ���ظ� �����ϴ� / ���¹̳�: 60" << endl;
		break;
	}
}

//������ ���ſ����� �ɷ�ġ �缳��
void ItemPoint()
{
	Pl.Str = Pl.Str + strcount;
	Pl.Dex = Pl.Dex + dexcount;
	Pl.Tol = Pl.Tol + tolcount;
	Pl.Tec = Pl.Tec + teccount;
	Pl.Res = Pl.Res + rescount;
}


//����Ž��
void Searching(int CASE)
{
	switch (CASE)
	{
	case 0:
		cout << "����� ����ġ���� �ݺ��� �߰��մϴ�" << endl;
		cout << "ã�ƺ��� �װ����� ���� �־����ϴ�" << endl;
		cout << "500G�� ȹ���մϴ�" << endl;
		g_PlayerMoney += 500;
		break;
	case 1:
		cout << "����� ����ġ���� �ݺ��� �߰��մϴ�" << endl;
		cout << "ã�ƺ��� �װ����� �����ۿ� �������ϴ�. " << endl;
		cout << "�׶� �ڿ��� ���ڱ� Ȳ�ݸ��並 �θ� ������ ��Ÿ������ �� ���ָӴϸ� �������ϴ�." << endl;
		cout << "500G�� �ҽ��ϴ�" << endl;
		g_PlayerMoney -= 500;
		break;
	case 2:
		cout << "����� ����� ������ �߰��մϴ�" << endl;
		cout << "�������� ���� �������ϴ� " << endl;
		cout << "�ҽ��� ���������� 2 �þ�ϴ�" << endl;
		Pl.Res += 2;
		Pl.StatPoint();
		break;
	case 3:
		cout << "����� �������� ������ �߰��մϴ�" << endl;
		cout << "������ ���� �������ϴ� " << endl;
		cout << "Ÿ�ݷ��� ���������� 2 �þ�ϴ�" << endl;
		Pl.Str += 2;
		Pl.StatPoint();
		break;
	case 4:
		cout << "����� ����ġ���� �ݺ��� �߰��մϴ�" << endl;
		cout << "ã�ƺ��� �װ����� �����ۿ� �������ϴ�. " << endl;
		cout << "�׶� �ڿ��� ���ڱ� Ȳ�ݸ��並 �θ� ������ ��Ÿ������ �� ���ָӴϸ� �������ϴ�." << endl;
		cout << "500G�� �ҽ��ϴ�" << endl;
		g_PlayerMoney -= 500;
		break;
	case 5:
		cout << "����� ����ġ���� �ݺ��� �߰��մϴ�" << endl;
		cout << "ã�ƺ��� �װ����� ��û�� ���� �־����ϴ�. " << endl;
		cout << "1000G�� ȹ���մϴ�" << endl;
		g_PlayerMoney += 1000;
		break;
	}
}


int main()
{

	srand(static_cast<unsigned int>(time(NULL)));


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���� ����
	Monster** Cute;
	Cute = new Monster*[16];

	for (int i = 0; i < 16; i++)
	{
		Cute[i] = nullptr;
	}

	Monster* pCuteMonster;

	pCuteMonster = new Monster(100,30,300,30,10,5,0);
	pCuteMonster->kind = "�𵥵�";
	pCuteMonster->name = "���̷����ó(��)";
	//����
	Cute[0] = pCuteMonster;

	pCuteMonster = new Monster(0, 20, 400, 30, 10, 80, 0);
	pCuteMonster->kind = "�𵥵�";
	pCuteMonster->name = "����(��)";
	//�ص��� �ʼ�  ��1
	Cute[1] = pCuteMonster;

	pCuteMonster = new Monster(80,25,800,10,20,0,100);
	pCuteMonster->kind = "�𵥵�";
	pCuteMonster->name = "��������Ʈ(����)";
	//�ش� �ʼ�  ��2
	Cute[2] = pCuteMonster;

	pCuteMonster = new Monster(150, 80, 500, 0, 0, 0, 0);
	pCuteMonster->kind = "�ΰ�";
	pCuteMonster->name = "�ڰ�(�ӵ�)";
	//���� �ʼ� ��3
	Cute[3] = pCuteMonster;

	pCuteMonster = new Monster(220, 20, 1000, 10, 10, 0, 0);
	pCuteMonster->kind = "�ΰ�";
	pCuteMonster->name = "�������(����)";
	//�ӵ�, ��3
	Cute[4] = pCuteMonster;

	pCuteMonster = new Monster(600, 20, 1400, 200, 20, 100, 0);
	pCuteMonster->kind = "�ΰ�";
	pCuteMonster->name = "������θӸ�(�ʰ���, �����, ����)";
	//������Ű�� or ���� �ʼ�, �ص��� �ʼ�, ��4
	Cute[5] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1200, 10, 0, 0, 50);
	pCuteMonster->kind = "���";
	pCuteMonster->name = "��� ����(����)";
	//�ش� �ʼ� ��5
	Cute[6] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1300, 10, 0, 0, 50);
	pCuteMonster->kind = "���";
	pCuteMonster->name = "������ ���(����)";
	//����, �ش� �ʼ�  ��5
	Cute[7] = pCuteMonster;

	pCuteMonster = new Monster(300, 30, 2000, 30, 0, 0, 100);
	pCuteMonster->kind = "���";
	pCuteMonster->name = "��� è�Ǿ�(����, ����)";
	//����, �ش�, ��ձ� �ʼ� ��6
	Cute[8] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1000, 10, 0, 0, 0);
	pCuteMonster->kind = "�ں�Ʈ";
	pCuteMonster->name = "�ں�Ʈ ������(��)";
	//����, �ص���, ��ձ� �ʼ� ��7
	Cute[9] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 1500, 0, 0, 0, 0);
	pCuteMonster->kind = "�ں�Ʈ";
	pCuteMonster->name = "�ں�Ʈ ������(����, �ӵ�)";
	//����, �ص���, ��ձ� �ʼ� ��7
	Cute[10] = pCuteMonster;

	pCuteMonster = new Monster(200, 90, 2000, 0, 0, 0, 0);
	pCuteMonster->kind = "�ں�Ʈ";
	pCuteMonster->name = "�ں�Ʈ ���(����, ���ӵ�)";
	//���� ���� �ʼ� ��8
	Cute[11] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 2000, 80, 30, 0, 0);
	pCuteMonster->kind = "�����";
	pCuteMonster->name = "����� ����(�ܴ���, �����)";
	//����, ��ձ� �ʼ� ��9
	Cute[12] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 3000, 100, 30, 0, 50);
	pCuteMonster->kind = "�����";
	pCuteMonster->name = "����� ������(�ܴ���, �����, ��)";
	//����, �ص���, ��ձ� �ʼ� ��9
	Cute[13] = pCuteMonster;

	pCuteMonster = new Monster(100, 30, 5000, 150, 30, 0, 0);
	pCuteMonster->kind = "�����";
	pCuteMonster->name = "Ʈ���������(�ܴ���, �����, ��)";
	//����, �ص���, ��ձ� �ʼ� ��10
	Cute[14] = pCuteMonster;

	pCuteMonster = new Monster(1000, 90, 10000, 0, 50, 50, 100);
	pCuteMonster->kind = "�Ǹ�";
	pCuteMonster->name = "������(����, ���ӵ�, ������, �ʵ�, �ܴ���)";
	//���� ��10
	Cute[15] = pCuteMonster;

	//���͵� ���� ����
	int battle1, battle2, battle3, battle4, battle5, battle6, battle7, battle8, battle9, battle10
		, battle11, battle12, battle13, battle14, battle15, battle16;


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//���� ����
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
	pShopTem->name = "ü�� ����";
	pShopTem->price = 300;

	Shop[1] = pShopTem;

	pShopTem = new Tem(0, 0, 0, 30);
	pShopTem->name = "���¹̳� ����";
	pShopTem->price = 300;

	Shop[2] = pShopTem;

	pShopTem = new Tem(1000,0,0,0);
	pShopTem->name = "�ص���";
	pShopTem->price = 300;

	Shop[3] = pShopTem;

	pShopTem = new Tem(0,1000,0,0);
	pShopTem->name = "�ش�";
	pShopTem->price = 300;

	Shop[4] = pShopTem;

	pShopWeapon = new Weapon(2, 5, 0, 0, 0);
	pShopWeapon->name = "�������� ����";
	pShopWeapon->price = 500;

	Shop[8] = pShopWeapon;

	pShopWeapon = new Weapon(3, 4, 0, 0, 0);
	pShopWeapon->name = "������ ��հ�";
	pShopWeapon->price = 500;

	Shop[9] = pShopWeapon;

	pShopWeapon = new Weapon(7, 0, 0, 2, 0);
	pShopWeapon->name = "��ɲ��� â";
	pShopWeapon->price = 500;

	Shop[10] = pShopWeapon;

	pShopWeapon = new Weapon(6, 10, 0, 0, 0);
	pShopWeapon->name = "����ŷ�� ��յ���";
	pShopWeapon->price = 2000;

	Shop[11] = pShopWeapon;

	pShopWeapon = new Weapon(8, 8, 0, 0, 0);
	pShopWeapon->name = "���ڱ��� ũ�缼�̴�";
	pShopWeapon->price = 2000;

	Shop[12] = pShopWeapon;

	pShopWeapon = new Weapon(15, 0, 0, 5, 0);
	pShopWeapon->name = "��������� ��â";
	pShopWeapon->price = 2000;

	Shop[13] = pShopWeapon;

	pShopWeapon = new Weapon(20, 30, 0, 0, 5);
	pShopWeapon->name = "���ظ�,";
	pShopWeapon->price = 10000;

	Shop[14] = pShopWeapon;

	pShopWeapon = new Weapon(25, 25, 20, 0, 0);
	pShopWeapon->name = "������";
	pShopWeapon->price = 10000;

	Shop[15] = pShopWeapon;

	pShopWeapon = new Weapon(40, 10, 0, 10, 0);
	pShopWeapon->name = "��Ÿ�Ǿ�";
	pShopWeapon->price = 10000;

	Shop[16] = pShopWeapon;

	pShopWeapon = new Weapon(100,100,100,100,100);
	pShopWeapon->name = "����Į����";
	pShopWeapon->price = 100000000;

	Shop[17] = pShopWeapon;

	pShopHand = new Hand(0, 3, 3, 0, 1);
	pShopHand->name = "�����尩";
	pShopHand->price = 500;

	Shop[18] = pShopHand;

	pShopHand = new Hand(0, 5, 8, 0, 3);
	pShopHand->name = "������ �ȸ� ����";
	pShopHand->price = 2000;

	Shop[19] = pShopHand;

	pShopHand = new Hand(0, 30, 30, 0, 10);
	pShopHand->name = "������";
	pShopHand->price = 10000;

	Shop[20] = pShopHand;

	pShopHead = new Head(0, 0, 5, 0, 2);
	pShopHead->name = "ö����";
	pShopHead->price = 500;

	Shop[21] = pShopHead;

	pShopHead = new Head(0, 0, 15, 0, 5);
	pShopHead->name = "�ǹ� �︧";
	pShopHead->price = 2000;

	Shop[22] = pShopHead;

	pShopHead = new Head(0, 0, 50, 0, 10);
	pShopHead->name = "���� ������";
	pShopHead->price = 10000;

	Shop[23] = pShopHead;

	pShopChest = new Chest(0, 0, 6, 0, 2);
	pShopChest->name = "�������䰩";
	pShopChest->price = 500;

	Shop[24] = pShopChest;

	pShopChest = new Chest(0, 0, 15, 0, 5);
	pShopChest->name = "���������䰩";
	pShopChest->price = 2000;

	Shop[25] = pShopChest;

	pShopChest = new Chest(0, 0, 60, 0, 10);
	pShopChest->name = "��ü��(��)";
	pShopChest->price = 10000;

	Shop[26] = pShopChest;

	pShopLeg = new Leg(0, 0, 6, 0, 2);
	pShopLeg->name = "����������";
	pShopLeg->price = 500;

	Shop[27] = pShopLeg;

	pShopLeg = new Leg(0, 0, 15, 0, 5);
	pShopLeg->name = "�������谩��";
	pShopLeg->price = 2000;

	Shop[28] = pShopLeg;

	pShopLeg = new Leg(0, 0, 60, 0, 10);
	pShopLeg->name = "��ü��(��)";
	pShopLeg->price = 10000;

	Shop[29] = pShopLeg;

	pShopFoot = new Foot(0, 0, 5, 0, 2);
	pShopFoot->name = "������ȭ";
	pShopFoot->price = 500;

	Shop[30] = pShopFoot;

	pShopFoot = new Foot(0, 0, 15, 0, 5);
	pShopFoot->name = "���̷н���";
	pShopFoot->price = 2000;

	Shop[31] = pShopFoot;

	pShopFoot = new Foot(0, 0, 50, 0, 10);
	pShopFoot->name = "����Ʈ��Ŀ";
	pShopFoot->price = 10000;

	Shop[32] = pShopFoot;

	pShopRing = new Ring(0, 0, 8, 15, 0);
	pShopRing->name = "ö ����";
	pShopRing->price = 500;

	Shop[33] = pShopRing;

	pShopRing = new Ring(0, 0, 15, 25, 0);
	pShopRing->name = "������ ����";
	pShopRing->price = 2000;

	Shop[34] = pShopRing;

	pShopRing = new Ring(0, 0, 50, 45, 10);
	pShopRing->name = "�Ҹ��� ����";
	pShopRing->price = 8000;

	Shop[35] = pShopRing;






	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	




	//�������� ����
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

	//���Ӱ��� ����
	int input;
	int choosenum;
	int playcount = 0;
	int count = 0;
	bool istrue = true;

	//Ȩȭ����� ����
	int FindCount = 0;



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







	cout << "ȸ����;;;;;;;;;;;;;;;;;" << endl;
	cout << "1 �����ϱ�" << endl << "2 ũ����" << endl << "3 ������" << endl;

	cin >> input;

	if (input == 1)
	{
		while (istrue)
		{
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//���Ժ� ����
			system("cls");


			cout << "����� ���� ������ ��� �ܵ����� �������־���." << endl;
			/*Sleep(2000);*/
			cout << "����� ����� �������� ����غ��������� ����̳����ʴ´�." << endl;
			/*Sleep(2000);*/
			cout << "������ ���Ѱ���, ���� ������ ���� �ǰ� ���� �����ߴ�." << endl;
			/*Sleep(2000);*/
			cout << "����� ����� ��ü�������ϰ�, �������� ���ߴ�." << endl << endl;

			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			cout << endl;

			cout << "�������� ���ϴ� ���� ���δ�." << endl
				<< "�������� ������ ������ �����غ��̴� ���� �������ҵ��ϴ�." << endl << endl;

			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//���� �Դ� �� ����
			system("cls");
			/*Sleep(2000);*/
			cout << "������ �����ߴ�" << endl;
			/*Sleep(2000);*/
			cout << "������ �ƹ��� ������ ������ ����δ�." << endl;
			/*Sleep(2000);*/
			cout << "������ �������� �������� ��ġ �������ϱ�� �ߴ��� ���������־���." << endl;
			/*Sleep(2000);*/
			cout << "������ ���� �ð��� �� ������ ������ �������� ������ �˼��־���." << endl;
			/*Sleep(3000);*/
			cout << "���������� �ƴ϶� ���ڰ� �İ� ���°��̿��ٴ°���." << endl;



			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}
						
						}



						
					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			
			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "ù��° ������ �Ǹ��� ��ġ�̽��ϴ�" << endl << "���� Ȩȭ���� �����帮�ڽ��ϴ�." << endl << "Ȩ ȭ�鿡�� ������ Ȯ��, �����̿�" << endl << "���,  ����Ž��, ���� ������ �̿��ϽǼ� �ֽ��ϴ�." << "��ſ� �����Ͻñ⸦ �ٶ��ϴ�." << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ���� ���Ժ� �������� ���� ��" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			//����1-2���� ����
			system("cls");
			/*Sleep(2000);*/
			cout << "������ ������ ��Ʋ°�̴�" << endl;
			/*Sleep(2000);*/
			cout << "���� ���̷������ ���� �Ⱥ��̱� �����ߴ�" << endl;
			/*Sleep(2000);*/
			cout << "�׶� �ڿ��� ���ֹ��� ���� ���� �Ҹ��� ��ȴ�" << endl;




			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "300exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 300;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "���⼭ ��� ������ �ϰ� ����?" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ���� ���� ���" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//����1-3���� ����
			system("cls");
			/*Sleep(2000);*/
			cout << "������ �������� ����° ���� ������ ���� ���̴µ��ϴ�" << endl;
			/*Sleep(2000);*/
			cout << "���� �ⱸ�� ���� �ٿ����� ������ ���� ���� �翴��" << endl;
			/*Sleep(2000);*/
			cout << "�񼮿� ���������� ���� �ɰ����� ���� ����ġ�� ���� ��밡 ���Դ�" << endl;
			/*Sleep(2000);*/
			cout << "��������Ʈ��" << endl;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "���� ���������� ���� �̰� �������̱�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ������ ��" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			// ��� (1-1) ���� ����

		
			system("cls");
			cout << "������ ���� ������ �꿡 �����ߴ�" << endl << "������ �� ���� ���� ��ü���� ���� ������" << endl <<
				"��ü�� ���� ǥ�ø� ���� �� ���� �ϳ� ������ ���������� �ұ��� �ȵ��ϴ�" << endl <<
				"�����ؾ߰ڴٰ� ������ ���� �ڿ��� �ܰ��� �� �������� ���� ���ƴ�" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "400exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 400;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "����� ���ٺ��� �ϳ��� ���Ͱ�������. ���⼭ ���� �ؾ߰ڴ�." << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: �� ���� ����� ����" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// ��� (1-2) ���� ����


			system("cls");
			cout << "����� �� ���ο� �Դ�" << endl << "�� ��������� Ƣ����ٵ�......" << endl <<
				"�� ������ ���ڸ��� �Ŵ��� ü���� ������ ���Դ�" << endl <<
				"���ݷ��� ����� ���غ��δ�" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "����� �� �����̴�. ���� ȣ���� ������. ���⼭ �޽��� ���ؾ߰ڴ�." << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: �� ���� ������ ȣ����" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// ��� (1-3) ���� ����


			system("cls");
			cout << "����� ������ �ٷ� �տ� ���̴� �� �ⱸ���� �Դ�" << endl << "������ �ع��̱�" << endl <<
				"�׶� �̷� ���� ������ �ϴµ� �� ���� ������ ���Դ�" << endl;/* <<*/
				/*"���ݷ��� ����� ���غ��δ�" << endl;*/

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "200exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 200;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "���� �����Ա����� �Դ�." << endl;
			cout << "������ ���� ������� ���� �Ѱɱ�?" << endl << "�׶� �� ������ ������ �����Ҹ��� ��¦ �鸰�� �ߴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ���� ��" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// ���� (1-1) ���� ����


			system("cls");
			cout << "���꿡 ���Դ�" << endl << "���� ������ �������� �ϳ� ���ߵǴ� ������ ������ ������ ��� �� ����� �����ߴ�" << endl <<
				"�Ա��� �� �Ƿ� ���� ���� ���� ���Դ�" << endl << "�츮�� �ǵ帮��� ���Ҵ�. �װ͸�ŭ�� �ȵƴµ� �ǵ帮��� ���Ҵ�." << endl << "���� �װ� �ٽ� �̰��� �� �װ��� ���ٶ�����" << endl
				<< "�ƹ��� �� ���� �����ڴ� �ٽô� ������ ������......" << endl << "��Ȳ�� �� ���� ������� �����Դ�." << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "300exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 300;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "������ ������ ������ ���ٺ���, ���� �̰� �κε��� ����ѵ��� �ްԽ��� �߰��ߴ�." << endl;
			cout << "�̰����� ��� �����ؾ߰ڴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����1�� ����� �ްԽ�" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
				if (input == 5)
				{
					Cute[battle1]->AllPrint();
					Cute[battle2]->AllPrint();
					Cute[battle3]->AllPrint();
					Cute[battle4]->AllPrint();
					Cute[battle5]->AllPrint();
					Cute[battle6]->AllPrint();
					Cute[battle7]->AllPrint();
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// ���� (1-2) ���� ����


			system("cls");
			cout << "������ �ſ� �����" << endl << "�������� ���� ���� �̾�����" << endl <<
				"�׶� ���ݱ��� �׿��Դ� ������� Ȯ���� �ٸ��� ���� ���� ���� ���Ƽ���" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "700exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 700;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "ü���� �Ѱ迡 ���ߴ�" << endl;
			cout << "�̰����� ��� �����ؾ߰ڴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����1�� ���" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








			// ���� (1-3) ���� ����


			system("cls");
			cout << "���� �� ����?" << endl << "�׶� �� ������ �������� �̷������ �ƴ϶�� ���� �˼��־���." << endl <<
				"�������� ���̱�" << endl << "�� �տ��� ���� �̰��� ���������� ���ٴ� ���� ǥ���� ��ġ�� �Ѹ��� ��Ÿ����.";

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "2000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 2000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "�ʹ� ������������" << endl;
			cout << "������������ ��� �޽��ؾ߰ڴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����2��������" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////









			// ���� (2-1) ���� ����


			system("cls");
			cout << "���ϱ�" << endl << "�̰����ʹ� ����� ������� �ƴ϶�°��� ��������." << endl <<
				"�������� �ʹ� ���� �۾Ҵ�." << endl << "�׷�, �̰��� �ΰ����� ������ ���� �� ����� �������ӿ� Ʋ������" << endl << "�� ����� �ƴϳ��ٸ��� ��Ÿ����";

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "�� ��������� ����Ѹ��� �� �������� �ִ� �ʺ� ���̿���" << endl;
			cout << "�׶� �ں�Ʈ���� ���µ��� ���� ���Դ�" << endl;
			cout << "�ں�Ʈ���� ���� ���鼭 �� �׿� ����̵ȵ��ϴ�." << endl;
			cout << "�׷� ���� ���� ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����2Ī �ں�Ʈ���ǹ�(����?)" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








			// ���� (2-2) ���� ����


			system("cls");
			cout << "��������" << endl << "������ �ʹ� ����ߴ�" << endl << "�ں�Ʈ ��鵵 ���㸶�� ������ ���Դ�" << endl <<
				"�׶� ���� �͹��� �� �ں�Ʈ �Ѹ����� �ٰ��Դ�" << endl << "���غ��δ�" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "400exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 400;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "�̹浵 ���� ���鼭 �� �׿� ����̵ȵ��ϴ�." << endl;
			cout << "�׷� ���� ���⵵ ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����2�� �ҽ��� �ں�Ʈ���� �� �ٸ� ��(����)" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// ���� (2-3) ���� ����


			system("cls");
			cout << "����2�� ��Ʈ�Ӹ��� ������ �ϳ��� �߰��ߴ�" << endl << "�� ���� �ƴϳ��ٸ���" << endl << "��û���� ���غ��̴� �ں�Ʈ �Ѹ����� ��Ű���־���" << endl <<
				"�̰��� �ȵ��°� �����Ŵ� �ΰ�.." << endl << "���� �ȴٰ� ������ �׳��� �Ѽ��� ���� ���� �ٰ����� �����ߴ�" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "��ô ���ѳ��̿���" << endl;
			cout << "�������� �������� ������ �غ� �ؾ߰ڴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����2�� ������ ��" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






			// ��� (1-1) ���� ����


			system("cls");
			cout << "����!..�Ӹ��� �����Ͱ���" << endl << "�������� ������ �� ���� �����Ҹ��� ���� ũ�Ե���´�" << endl << "�� �� ���� ���̱� ���� �̰��� �°ɰ��̴�" << endl <<
				"�׶� �������� �ǹ����� ����� Ƣ��Դ�" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "����ߵ�...." << endl;
			cout << "���� �ʻ������� �׳�� ������ ���� ������ � ���� ����. ������ �̰��� ���� ���µ��ϴ�." << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����� ���" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// ��� (1-2) ���� ����


			system("cls");
			cout << "������ ���� ��������" << endl << "���� �̼��� �Ҿ��" << endl << "���� ���߰ڴ�" << endl <<
				"�׶� Ư���ϰ� ���� �����ڸ� �� ��ä���� ����Ű� ��Ÿ����" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "2000G" << endl;
				cout << "����ġ: " << "1000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 1000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 2000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "����, ü�� ��� �Ѱ迡 ���ߴ�" << endl;
			cout << "���� �ʻ������� ó���� ������ ������ �ٸ� ���� ã�� ����. ������ �̰����� ���� ���µ��ϴ�." << endl;
			cout << "�׶� ���� ���� �̷����� �� ����������� ������ �����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����� ���2" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			// ��� (1-3) ���� ����


			system("cls");
			cout << "���� �Ҿ��� �̼��� ȸ���ϰ� �ִ°Ͱ���" << endl << "���ϱ�?" << endl << "�׳��� ������ ���� ���� ���̻� ���� �ʴµ��ϴ�" << endl <<
				"�� �׳��� �����Ͱ���" << endl << "�׶� �Ӹ� �ΰ��� �ظ��� ������ ����ų��� ��Ÿ����" << endl << "�׳��� �ƴϳ�" << endl << "���� ���⸦ �����" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "5000G" << endl;
				cout << "����ġ: " << "3000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 3000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 5000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "�Կ��� �ǰ� �����ĳ��Դ�" << endl;
			cout << "ü�������� �Ѱ迡 ���ߴ�" << endl;
			cout << "Ʈ��������Ű� ��Ű�� �ִ����� ������ �Ŵ��� �庮�� ��Ÿ����" << endl;
			cout << "�� �ؿ� ���� ������ ���ϳ��� ������" << endl;
			cout << "�׳��� �� ���� ������ ������ �����Ͱ���" << endl;
			cout << "���� ������ ���� �����ߴ�" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			//Ȩ ȭ��
			FindCount = 0;
			istrue = true;
			while (istrue)
			{
				system("cls");
				cout << "������ġ: ����� �Ŵ��� �庮 �� ���� �� ��" << endl;
				cout << "1 ����â  ||  2 ����  ||  3 ���  ||  4 ����Ž��  ||  5 ���� ����  ||  6 ������������" << endl;

				cout << "�Ͻ� �ൿ�� �Է����ּ���" << endl;
				cin >> input;
				//����â
				if (input == 1)
				{
					system("cls");
					Pl.PlayerPrint();
					cout << "������: " << g_PlayerMoney << "G" << endl;
					cout << "�� ������" << endl;
					for (int i = 0; i < Inven.size(); i++)
					{
						cout << i << "�� ������" << endl;
						Inven[i]->Print();
					}
					cout << "���ư����� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				//����
				if (input == 2)
				{
					while (istrue)
					{
						system("cls");
						cout << "������: " << g_PlayerMoney << "G" << endl;
						cout << "�� ������" << endl;
						for (int i = 0; i < Inven.size(); i++)
						{
							cout << i << "�� ������" << endl;
							Inven[i]->Print();
						}

						cout << "1 �����ϱ�  ||  2 Ȩȭ������" << endl;
						cin >> input;
						if (input == 2)
						{
							break;
						}

						cout << "============================" << endl;

						cout << "������ ���Ű� ȯ�� �մϴ�." << endl;
						cout << "1.���κ��� , 2. ���� , 3. ���� ,4. �ȸ�ȣ��" << endl;
						cout << "5. �䰩, 6.����, 7.�Ź�, 8. ���� 9. ��ȭ" << endl;

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
						cout << "1.���� 2. �Ǹ�" << endl;

						cin >> input;

						//����
						if (input == 1)
						{
							cout << "�����Ͻ� �������� �Է��ϼ���" << endl;

							cin >> input;

							if (Shop[input]->price > g_PlayerMoney)
							{
								cout << "���� �����մϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "���Ⱑ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�ȸ�ȣ�밡 �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�䰩�� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "�Ź��� �̹� �ֽ��ϴ�" << endl;
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

										//������ ������ �ɷ�ġ ����
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
										cout << "������ �̹� �ֽ��ϴ�" << endl;
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
						//�ȱ�
						else
						{
							cout << "�Ǹ� �Ͻ� �������� �Է��ϼ���(0.8��)" << endl;
							cin >> input;
							if (input >= Inven.size())
							{
								cout << "�ش� �������� ���������ʽ��ϴ�" << endl;
							}
							else
							{
								//�Ǹ��� ������ �ɷ�ġ ����
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

				//���
				if (input == 3)
				{
					system("cls");
					PrintSkill(Pl.Lv);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}

				//����Ž��
				if (input == 4)
				{
					if (FindCount == 0)
					{
						system("cls");
						Searching(rand() % 6);
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						FindCount += 1;
						continue;
					}
					else
					{
						cout << "�� ������ �̹� �����߽��ϴ�." << endl;
						cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
						cin >> choosenum;
						continue;
					}
				}
				//���� ����
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
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;
					continue;
				}
				else
				{
					break;
				}
			}


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



			// �ٸ������� ���� ���� ����


			system("cls");
			cout << "�̰��� ����? ���� �������� �ڱ׸��� ���ϳ��� ��Ÿ����" << endl << "�װ����� ��� ������ ���𰡸� ������ �ε帮�� �־���" << endl 
				<< "�׳��� Ʋ������. ���� �����ߴ�" << endl <<
				"�׳��� ���� ������" << endl << "���� ������� �Ա���" << endl << "�� ������ �����̴�" 
				<< endl << "���� ���⸦ �����" << endl;

















			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			//����
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
			cout << Cute[battle1]->name << "��(��) ��Ÿ����" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;
			/*Sleep(1000);*/
			while (Cute[battle1]->m_Hp >= 0)
			{
				system("cls");
				//��Ʋ������ 100�Ǹ� ��������(�÷��̾�� �������� ��)
				//�� ��
				if (PlBattleGage >= 100)
				{
					//��ų ���� ����
					Pl.Dd = P_DAMAGEDECLINE;
					//��Ʋ������ �ٽ� 0����
					PlBattleGage = 0;
					//�ڰ�ġ�� �� �ڰ����¹̳� ȸ�� �� ������, ��������
					Pl.Hp = Pl.Hp + Pl.HpRc - Cute[battle1]->m_Poison*Poisoncount - Cute[battle1]->m_Bleed*Bleedcount;
					if (Pl.Hp > Pl.Tol * 10 + 1000)
					{
						Pl.Hp = Pl.Tol * 10 + 1000;
					}

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
						cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
						Cute[battle1]->Print();
						cout << endl;

						cout << "1 ������â����  ||  2 �����ϱ�  ||  3 ������  ||  4 �����ۻ��" << endl;
						cout << "�÷��̾�" << endl;
						cout << "ü��: " << Pl.Hp << '\t' << "���ѵ�����: " << Cute[battle1]->m_Poison*Poisoncount << '\t' << "������������: " << Cute[battle1]->m_Bleed*Bleedcount << endl;
						cout << "���¹̳�: " << Pl.Sm << endl;
						cout << "���ݼӵ�: " << Pl.AttSp << endl;

						cin >> input;
						system("cls");
						//�� ����â����
						if (input == 1)
						{
							Pl.PlayerPrint();
							cout << "������: " << g_PlayerMoney << "G" << endl;
							cout << "�� ������" << endl;
							for (int i = 0; i < Inven.size(); i++)
							{
								cout << i << "�� ������" << endl;
								Inven[i]->Print();
							}
							cout << "���ư����� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							continue;
						}
						//����
						if (input == 2)
						{
							cout << Cute[battle1]->name << "�� �����ߴ�" << endl;
							cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) << endl;
							cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) << endl;
							Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100);

							cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
							cin >> choosenum;
							break;
						}
						//���
						if (input == 3)
						{
							if (Pl.Lv < 2)
							{
								cout << "���� ����� �����ϴ�." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								continue;
							}
							else if ((Pl.Lv > 1) && (Pl.Lv < 3))
							{
								cout << "1 ����(sp20)  ||  2 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ���ư���" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * 3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * 3;

									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
								cout << "1 ����(sp20)  ||  2 ������Ű��(sp50)  ||  3 ��ձ�(sp30) ||  4 ��ǳ(sp60)" << endl;
								cin >> input;
								if (input == 1)
								{
									cout << "����� ���������� ���� �غ� �ߴ�" << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									Pl.Dd = 100;
									Pl.Sm -= 20;
									continue;
								}
								else if (input == 2)
								{
									cout << Cute[battle1]->name << "�� �������״�" << endl;
									MoBattleGage = 0;
									Pl.Sm -= 50;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 3)
								{
									cout << Cute[battle1]->name << "�� ��վ���" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)3 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)3;
									Pl.Sm -= 30;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else if (input == 4)
								{
									cout << Cute[battle1]->name << "���� ��ǳ�� ���ȴ�" << endl;
									cout << "���� ����: " << (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									cout << "���� ���ҷ�: " << (float)Pl.Att * (((float)Cute[battle1]->m_Dd) / (float)100) * (float)7 << endl;
									Cute[battle1]->m_Hp -= (float)Pl.Att * (((float)100 - (float)Cute[battle1]->m_Dd) / (float)100) * (float)7;
									Pl.Sm -= 60;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									break;
								}
								else
								{
									continue;
								}
							}
						}
						//������ ���
						else
						{
							if (Inven.size() == 0)
							{
								cout << "�������� �����ϴ�." << endl << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
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
									cout << "����Ҽ��ִ� �������� �����ϴ�." << endl << endl;
									cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
									cin >> choosenum;
									continue;
								}
								for (int i = 0; i < Inven.size(); i++)
								{
									if (Inven[i]->type == TEM)
									{
										cout << i << "�� ������" << endl;
										Inven[i]->Print();
									}
								}
								cout << "1 ���ư���  ||  2 ������ ���" << endl;
								cin >> input;
								if (input == 1)
								{
									continue;
								}
								else
								{
									cout << "����� �������� �������ּ���" << endl;
									cin >> input;
									if (Inven[input]->name == "ü�� ����")
									{
										cout << "ü�� ������ ���̴�" << endl;
										Pl.Hp = Pl.Hp + 400;
										if (Pl.Hp > Pl.Tol * 10 + 1000)
										{
											Pl.Hp = Pl.Tol * 10 + 1000;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "���¹̳� ����")
									{
										cout << "���¹̳� ������ ���̴�" << endl;
										Pl.Sm = Pl.Sm + 30;
										if (Pl.Sm > Pl.Tec + 50)
										{
											Pl.Sm = Pl.Tec + 50;
										}
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ص���")
									{
										cout << "�ص����� ���̴�" << endl;
										Poisoncount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
									else if (Inven[input]->name == "�ش�")
									{
										cout << "�ش븦 �ѷ���" << endl;
										Bleedcount = 0;
										Inven.erase(Inven.begin() + input);
										continue;
									}
								}
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;

							}

						}




					}
					//�÷��̾� ��Ʋī��Ʈ ����
					Plbattlecount += 1;
				}


				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


				//���� ��
				if (MoBattleGage >= 100)
				{
					system("cls");
					//��Ʋ������ �ٽ� 0����
					MoBattleGage = 0;
					//���� �ڰ�ġ��
					Cute[battle1]->m_Hp = Cute[battle1]->m_Hp + Cute[battle1]->m_HpRc;
					if (Cute[battle1]->m_Hp > M_HEALTH)
					{
						Cute[battle1]->m_Hp = M_HEALTH;
					}
					//��
					cout << Plbattlecount + Mobattlecount << "��" << endl << endl;
					//���� ����
					cout << Cute[battle1]->name << "�� ����" << endl;

					cout << "���� ��������: " << (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100) << endl;
					cout << "�������� ���ҷ�: " << (float)Cute[battle1]->m_Att * (((float)Pl.Dd) / (float)100) << endl;
					cout << "���� ����ø" << Cute[battle1]->m_Poison << endl;
					cout << "���� ������ø" << Cute[battle1]->m_Bleed << endl;
					Pl.Hp -= (float)Cute[battle1]->m_Att * (((float)100 - (float)Pl.Dd) / (float)100);
					cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
					cin >> choosenum;

					//���� ��(�÷��̾� �й�)
					if (Pl.Hp <= 0)
					{
						system("cls");
						cout << "�������� �й��߽��ϴ�..." << endl;
						cout << "1 ���� �ٽ��ϱ�(1000G ����)  ||  2 ������" << endl;
						cout << "�� ���: " << g_PlayerMoney << endl;
						cin >> choosenum;
						if (choosenum == 1)
						{
							if (g_PlayerMoney >= 1000)
							{
								//���� ó�� ���Ի�Ȳ���� ���� ����
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
								cout << "���� ������� �ʽ��ϴ�..." << endl;
								cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
								cin >> choosenum;
								return 0;
							}
						}

						else
						{
							return 0;
						}

					}

					//���� ��Ʋī��Ʈ ����
					Mobattlecount += 1;
					Poisoncount += 1;
					Bleedcount += 1;
				}

				//��Ʋ������ ����
				PlBattleGage += Pl.AttSp;
				MoBattleGage += Cute[battle1]->m_Attsp;
			}

			//���� ��(�÷��̾� �¸�)
			if (Cute[battle1]->m_Hp <= 0)
			{
				system("cls");
				cout << Cute[battle1]->name << "��(��) ��������" << endl;
				cout << "����ǰ: " << "10000G" << endl;
				cout << "����ġ: " << "3000exp" << endl;
				cout << "ü��, ���¹̳ʸ� ȸ���մϴ�" << endl;
				Pl.Exp += 3000;
				if (Pl.Lv < 11)
				{
					if (Pl.Exp >= 1000)
					{
						Pl.Exp = 0;
						Pl.Lv += 1;
						cout << "�������� �Ͽ����ϴ�." << endl;
						cout << Pl.Lv << "LV" << endl;
						cout << "������ �����ϴ�." << endl;
						SkillOpen(Pl.Lv);
					}
				}
			}
			cout << "���а���ġ: " << Pl.Exp << "exp" << endl;

			g_PlayerMoney = g_PlayerMoney + 10000;
			//��ų ���� ����
			Pl.Dd = P_DAMAGEDECLINE;
			//ü��, ���¹̳� �ʱ�ȭ
			Pl.Hp = Pl.Tol * 10 + 1000;;
			Pl.Sm = Pl.Tec + 50;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;

			//���� ü�� �ʱ�ȭ
			Cute[battle1]->m_Hp = M_HEALTH;



			system("cls");
			cout << "�̱�ǰ�?" << endl;
			cout << "�� ���� �Կ��� �Ǹ� �긮�� �־��� �� �̻� �������� �ʾҴ�" << endl;
			cout << "�� ���� ���� ������" << endl;
			cout << "�� �� â�����̾�, �����" << endl;
			cout << "���� ������ �����߷ȱ���" << endl;
			cout << "�� ���� ó���� �� ���� �ε帮������ � ����ġ�� ������" << endl;
			cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
			cin >> choosenum;


			
			

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




			//�Ʒ� ��ȣ�� while�� �̾��� ���Ժηΰ�
		}


	}
	

	if (input == 2)
	{
		cout << "ũ����: " << endl;
		cout << "sga ��ī���� |||||||||�ڿ���||||||||||" << endl;
	}
	
	//�� �Ҵ� ������ ���� ����
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

	cout << "����Ϸ��� �ƹ�Ű�� �����ÿ�";
	cin >> choosenum;

	return 0;
}