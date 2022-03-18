#ifndef ITEMS_H_
#define ITEMS_H_

#include <iostream>

using namespace std;

class Item{
protected:
	string name;
	int price;
	int levelReq;
public:
	string getName();
	int getPrice();
	int getLevelReq();
};

class Weapon: public Item{
private:
	int damage;
	int hands;
public:
	Weapon(string/*name*/, int/*price*/, int/*levelReq*/, int/*damage*/, int/*hands*/);
	Weapon();
	Weapon(const Weapon&);
	int getDamage();
	int getHands();
};
class Armor: public Item{
private:
	int defence;
public:
	Armor(string/*name*/, int/*price*/, int/*levelReq*/, int/*defence*/);
	Armor();
	Armor(const Armor&);
	int getDefence();
};
class Potion: public Item{
private:
	int hpRestore;
	int mpRestore;
	int strBuff;	
	int dexBuff;
	int agiBuff;
public:
	Potion(string/*name*/, int/*price*/, int/*levelReq*/, int/*hpRestore*/, int/*mpRestore*/, int/*strBuff*/, int/*dexBuff*/, int/*agiBuff*/);
	int getHpRestore();
	int getMpRestore();
	int getStrBuff();
	int getDexBuff();	
	int getAgiBuff();
};

#endif
