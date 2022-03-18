#ifndef MARKET_H_
#define MARKET_H_

#include "Items.h"
#include "Entities.h"
#include "Spells.h"

using namespace std;

class Market{
public:
	Market();
	~Market();
///////////////////////////////////////////////////////////
	void set_Items();
	void get_Items();
	void get_Weapon();
	void get_Armor();
	void get_Potion();
	void get_IceSpell();
	void get_FireSpell();
	void get_LightningSpell();
	void sell_Items(Party*);
//	void buy_Items(Party,Grid,int,int);
        char buy_Items(Party*);
private:
	Weapon* weapon;
	Armor* armor;
	Potion* potion;
	IceSpell* icespell;
	FireSpell* firespell;
	LightningSpell* lightningspell;
};

#endif
