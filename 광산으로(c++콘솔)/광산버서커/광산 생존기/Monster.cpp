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
	cout << "����: " << kind << endl;
	cout << "�̸�: " << name << endl;
	cout << "ü��: " << m_Hp << endl;
	cout << "���ݼӵ�: " << m_Attsp << endl;
}

void Monster::AllPrint()
{
	cout << "����: " << kind << endl;
	cout << "�̸�: " << name << endl;
	cout << "ü��: " << m_Hp << endl;
	cout << "���ݷ�: " << m_Att << endl;
	cout << "���ݼӵ�: " << m_Attsp << endl;
	cout << "ġ����: " << m_HpRc << endl;
	cout << "���ذ��ҷ�: " << m_Dd << endl;
	cout << "��������: " << m_Poison << endl;
	cout << "����������: " << m_Bleed << endl << endl;
}
