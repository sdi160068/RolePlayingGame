#include "Spells.h"

string Spell::getName(){
	return name;
}
int Spell::getPrice(){
	return price;
}
int Spell::getLevelReq(){
	return levelReq;
}
int Spell::getMinDamage(){
	return minDamage;
}
int Spell::getMaxDamage(){
	return maxDamage;
}
int Spell::getMpCost(){
	return mpCost;
}


IceSpell::IceSpell(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*minDamage*/ d, int/*maxDamage*/ e, int/*mpcost*/ f, int/*dmgReduction*/ g){
	name=a;
	price=b;
	levelReq=c;
	minDamage=d;
	maxDamage=e;
	mpCost=f;
	damageReduction=g;
}
int IceSpell::getDamageReduction(){
	return damageReduction;
}

FireSpell::FireSpell(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*minDamage*/ d, int/*maxDamage*/ e, int/*mpcost*/ f, int/*defReduction*/ g){
	name=a;
	price=b;
	levelReq=c;
	minDamage=d;
	maxDamage=e;
	mpCost=f;
	defenceReduction=g;	
}
int FireSpell::getDefenceReduction(){
	return defenceReduction;
}

LightningSpell::LightningSpell(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*minDamage*/ d, int/*maxDamage*/ e, int/*mpcost*/ f, double/*dodgeReduction*/ g){
	name=a;
	price=b;
	levelReq=c;
	minDamage=d;
	maxDamage=e;
	mpCost=f;
	dodgeReduction=g;	
}
int LightningSpell::getDodgeReduction(){
	return dodgeReduction;
}
