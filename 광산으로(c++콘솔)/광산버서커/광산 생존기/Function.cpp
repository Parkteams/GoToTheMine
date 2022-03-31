#include "stdafx.h"
#include "Function.h"

//�������� ���
//���� ȭ�� �����ֱ�
void PrintShop(int Type, Item ** Shop)
{
	switch(Type)
	{
        case ITEM:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)
				{
					cout << i << "�� ������" << endl;
					Shop[i]->Print(); //shop�� Item* �߻��� ���� (��ü���� �ƴ�)
				}
			}
			break;
		case WEAPON:
			for (int i = 0; i < 40; i++)
			{
				//if(Shop[i] != nullptr && Shop[i]->type == WEAPON)
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == WEAPON)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case HEAD:
			for (int i = 0; i < 40; i++)
			{
				//if(Shop[i] != nullptr && Shop[i]->type == WEAPON)
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == HEAD)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case HAND:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == HAND)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case CHEST:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == CHEST)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case LEG:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == LEG)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case FOOT:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == FOOT)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case RING:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == RING)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case TEM:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//��ü�� �����Ҷ���
				{
					if (Shop[i]->type == TEM)
					{
						cout << i << "�� ������" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
	}
}

void PrintSkill(int PL_LV)
{
	switch (PL_LV)
	{
	case 1:
		cout << "����� �����ϴ�" << endl;
		break;
	case 2:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		break;
	case 3:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		cout << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		break;
	case 4:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		cout << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		break;
	case 5:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		cout << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		cout << "��ձ�: �̹� ������ 3���� ���ظ� �����ϴ� / ���¹̳�: 30" << endl;
		break;
	case 10:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		cout << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		cout << "��ձ�: �̹� ������ 3���� ���ظ� �����ϴ� / ���¹̳�: 30" << endl;
		cout << "��ǳ: �̹� ������ 7���� ���ظ� �����ϴ� / ���¹̳�: 60" << endl;
		break;
	default:
		cout << "����: ���� �ڱ� ���ʰ� �ö����� �޴� ����: 0 / ���¹̳�: 20" << endl;
		cout << "������Ű��: ������ �ൿ�������� 0���� ����ϴ� / ���¹̳�: 50" << endl;
		cout << "��ձ�: �̹� ������ 3���� ���ظ� �����ϴ� / ���¹̳�: 30" << endl;
		break;

	}
}
