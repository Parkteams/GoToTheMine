#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

Monster::Monster(int M_ATT, int M_ATTSP, int M_HP, int M_HPRC, int M_DD, int M_POISON, int M_BLEED)
{
	m_Att = M_ATT;
	m_Attsp = M_ATTSP;
	m_Hp = M_HP;
	m_HpRc = M_HPRC;
	m_Dd = M_DD;
	m_Poison = M_POISON;
	m_Bleed = M_BLEED;
	string      name;
	string		kind;
}

void Monster::Print()
{
	cout << "종족: " << kind << endl;
	cout << "이름: " << name << endl;
	cout << "체력: " << m_Hp << endl;
	cout << "공격속도: " << m_Attsp << endl;
}

void Monster::AllPrint()
{
	cout << "종족: " << kind << endl;
	cout << "이름: " << name << endl;
	cout << "체력: " << m_Hp << endl;
	cout << "공격력: " << m_Att << endl;
	cout << "공격속도: " << m_Attsp << endl;
	cout << "치유량: " << m_HpRc << endl;
	cout << "피해감소량: " << m_Dd << endl;
	cout << "독게이지: " << m_Poison << endl;
	cout << "출혈게이지: " << m_Bleed << endl << endl;
}
