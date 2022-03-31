#include "stdafx.h"
#include "Function.h"

//상점관련 기능
//상점 화면 보여주기
void PrintShop(int Type, Item ** Shop)
{
	switch(Type)
	{
        case ITEM:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)
				{
					cout << i << "번 아이템" << endl;
					Shop[i]->Print(); //shop은 Item* 추상적 접근 (구체적이 아닌)
				}
			}
			break;
		case WEAPON:
			for (int i = 0; i < 40; i++)
			{
				//if(Shop[i] != nullptr && Shop[i]->type == WEAPON)
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == WEAPON)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case HEAD:
			for (int i = 0; i < 40; i++)
			{
				//if(Shop[i] != nullptr && Shop[i]->type == WEAPON)
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == HEAD)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case HAND:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == HAND)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case CHEST:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == CHEST)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case LEG:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == LEG)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case FOOT:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == FOOT)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case RING:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == RING)
					{
						cout << i << "번 아이템" << endl;
						Shop[i]->Print();
					}
				}
			}
			break;
		case TEM:
			for (int i = 0; i < 40; i++)
			{
				if (Shop[i] != nullptr)//객체가 존재할때만
				{
					if (Shop[i]->type == TEM)
					{
						cout << i << "번 아이템" << endl;
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
		cout << "기술이 없습니다" << endl;
		break;
	case 2:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		break;
	case 3:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		cout << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		break;
	case 4:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		cout << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		break;
	case 5:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		cout << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		cout << "꿰뚫기: 이번 공격이 3배의 피해를 입힙니다 / 스태미너: 30" << endl;
		break;
	case 10:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		cout << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		cout << "꿰뚫기: 이번 공격이 3배의 피해를 입힙니다 / 스태미너: 30" << endl;
		cout << "장풍: 이번 공격이 7배의 피해를 입힙니다 / 스태미너: 60" << endl;
		break;
	default:
		cout << "막기: 다음 자기 차례가 올때까지 받는 피해: 0 / 스태미너: 20" << endl;
		cout << "기절시키기: 몬스터의 행동게이지를 0으로 만듭니다 / 스태미너: 50" << endl;
		cout << "꿰뚫기: 이번 공격이 3배의 피해를 입힙니다 / 스태미너: 30" << endl;
		break;

	}
}
