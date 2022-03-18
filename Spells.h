#ifndef SPELLS_H_
#define SPELLS_H_
#include <iostream>

using namespace std;

class Spell{
protected:
	string name;
	int price;
	int levelReq;
	int minDamage;
	int maxDamage;
	int mpCost;
public:
	string getName();
	int getPrice();
	int getLevelReq();
	int getMinDamage();
	int getMaxDamage();
	int getMpCost();
};

class IceSpell: public Spell{
private:
	int damageReduction;
public:
	IceSpell(string/*name*/, int/*price*/, int/*levelReq*/, int/*minDamage*/, int/*maxDamage*/, int/*mpcost*/,int/*dmgReduction*/);
	int getDamageReduction();
};
class FireSpell: public Spell{
private:
	int defenceReduction;
public:
	FireSpell(string/*name*/, int/*price*/, int/*levelReq*/, int/*minDamage*/, int/*maxDamage*/, int/*mpcost*/,int/*defReduction*/);
	int getDefenceReduction();
};
class LightningSpell: public Spell{
private:
	int dodgeReduction;
public:
	LightningSpell(string/*name*/, int/*price*/, int/*levelReq*/, int/*minDamage*/, int/*maxDamage*/, int/*mpcost*/,double/*dodgeReduction*/);
	int getDodgeReduction();
};

#endif
