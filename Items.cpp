#include <iostream>
#include "Items.h"

string Item::getName(){
	return name;
}
int Item::getPrice(){
	return price;
}
int Item::getLevelReq(){
	return levelReq;
}


Weapon::Weapon(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*damage*/ d, int/*hands*/ e){
	name=a;
	price=b;
	levelReq=c;
	damage=d;
	hands=e;
}
Weapon::Weapon(){
}
Weapon::Weapon(const Weapon &weap){
	name=weap.name;
	price=weap.price;
	levelReq=weap.levelReq;
	damage=weap.damage;
	hands=weap.hands;
}
int Weapon::getDamage(){
	return damage;
}
int Weapon::getHands(){
	return hands;
}


Armor::Armor(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*defence*/ d){
	name=a;
	price=b;
	levelReq=c;
	defence=d;
}
Armor::Armor(){
}
Armor::Armor(const Armor &arm){
	name=arm.name;
	price=arm.price;
	levelReq=arm.levelReq;
	defence=arm.defence;
}
int Armor::getDefence(){
	return defence;
}


Potion::Potion(string/*name*/ a, int/*price*/ b, int/*levelReq*/ c, int/*hpRestore*/ d, int/*mpRestore*/ e, int/*strBuff*/ f, int/*dexBuff*/ g, int/*agiBuff*/ h){
	name=a;
	price=b;
	levelReq=c;
	hpRestore=d;
	mpRestore=e;
	strBuff=f;	
	dexBuff=g;
	agiBuff=h;
}
int Potion::getHpRestore(){
	return hpRestore;
}
int Potion::getMpRestore(){
	return mpRestore;
}
int Potion::getStrBuff(){
	return strBuff;
}
int Potion::getDexBuff(){
	return dexBuff;
}
int Potion::getAgiBuff(){
	return agiBuff;
}
	
	
	
	
