#pragma once

enum ITEM_TYPE
{
	ITEM = 1,
	WEAPON,
	HEAD,
	HAND,
	CHEST,
	LEG,
	FOOT,
	RING,
	TEM
};

class Item
{
public:
	Item();
	Item(const Item& copy);
	virtual ~Item();
	int         price;
	string      name;
	ITEM_TYPE   type;

	virtual void Print();

};

class Weapon : public Item
{

public:
	Weapon();

	~Weapon();
	Weapon(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Head : public Item
{

public:
	Head();

	~Head();
	Head(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Hand : public Item
{

public:
	Hand();

	~Hand();
	Hand(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Chest : public Item
{

public:
	Chest();

	~Chest();
	Chest(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Leg : public Item
{

public:
	Leg();

	~Leg();
	Leg(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Foot : public Item
{

public:
	Foot();

	~Foot();
	Foot(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Ring : public Item
{

public:
	Ring();

	~Ring();
	Ring(int STR, int DEX, int TOL, int TEC, int RES);
	int		str;
	int		dex;
	int		tol;
	int		tec;
	int		res;
	void Print();
};

class Tem : public Item
{

public:
	Tem();

	~Tem();
	Tem(int PREC, int BREC, int HREC, int SREC);
	int prec;
	int brec;
	int hrec;
	int srec;
	void Print();
};