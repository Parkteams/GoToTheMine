#include "stdafx.h"
#include "Inven.h"


Item::Item()
{
	type = ITEM;
}

Item::Item(const Item & copy)
{
	type = copy.type;
	name = copy.name;
	price = copy.price;
}

Item::~Item()
{
}

Weapon::Weapon()
{
	type = WEAPON;
}

Weapon::~Weapon()
{
}

Weapon::Weapon(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = WEAPON;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Head::Head()
{
	type = HEAD;
}

Head::~Head()
{
}

Head::Head(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = HEAD;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Hand::Hand()
{
	type = HAND;
}

Hand::~Hand()
{
}

Hand::Hand(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = HAND;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Chest::Chest()
{
	type = CHEST;
}

Chest::~Chest()
{
}

Chest::Chest(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = CHEST;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Leg::Leg()
{
	type = LEG;
}

Leg::~Leg()
{
}

Leg::Leg(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = LEG;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Foot::Foot()
{
	type = FOOT;
}

Foot::~Foot()
{
}

Foot::Foot(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = FOOT;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Ring::Ring()
{
	type = RING;
}

Ring::~Ring()
{
}

Ring::Ring(int STR, int DEX, int TOL, int TEC, int RES)
{
	type = RING;
	str = STR;
	dex = DEX;
	tol = TOL;
	tec = TEC;
	res = RES;
}

Tem::Tem()
{
	type = TEM;
}

Tem::~Tem()
{
}

Tem::Tem(int PREC, int BREC, int HREC, int SREC)
{
	type = TEM;
	prec = PREC;
	brec = BREC;
	hrec = HREC;
	srec = SREC;
}

void Item::Print()
{
	cout << "ÀÌ¸§: " << name << endl;
	cout << "°¡°Ý: " << price << endl << endl;
}

void Weapon::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " "<< "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É "  << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}

void Head::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}

void Hand::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}


void Chest::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}

void Leg::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}


void Foot::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}

void Ring::Print()
{
	cout << name << " " << price << endl;
	cout << "Å¸°Ý·Â " << str << " " << "¹ÎÃ¸ÇÔ " << dex << " " << "ÀÎ³»½É " << tol << " " << "±â¼ú " << tec << " " << "¶Ò½É " << res << endl << endl;
}

void Tem::Print()
{
	cout << name << " " << price << endl;
	cout << "ÇØµ¶·® " << prec << " " << "ÁöÇ÷·® " << brec << " " << "Ã¼·ÂÈ¸º¹·® " << hrec << " " << "½ºÅÂ¹Ì³ÊÈ¸º¹·® " << srec << endl << endl;

}
