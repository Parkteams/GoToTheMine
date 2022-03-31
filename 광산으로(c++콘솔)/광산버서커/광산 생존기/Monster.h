#pragma once

class Monster
{
public:
	Monster();
	virtual ~Monster();
	Monster(int M_ATT, int M_ATTSP, int M_HP, int M_HPRC, int M_DD, int M_POISON, int M_BLEED);
	int         m_Att;
	int			m_Attsp;
	int			m_Hp;
	int			m_HpRc;
	int			m_Dd;
	int			m_Poison;
	int			m_Bleed;
	string      name;
	string		kind;

	void Print();

	void AllPrint();

};