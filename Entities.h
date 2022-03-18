#ifndef ENTITIES_H_
#define ENTITIES_H_

#include <vector>
#include "Items.h"
#include "Spells.h"

using namespace std;

class Living{
protected:
	string name;
	int level;
	int maxHealthPower;
	int healthPower;
public:
	Living();
	void setName(string);
	int getLevel();
	string getName();
	int getHP();
	void setHP(int);
	int getMaxHP();
};

class Hero: public Living{
private:
	double experience;
	int maxExperience;
	int money;
protected:
	int maxMagicPower;
	int magicPower;
	int strength;
	int dexterity;
	int agility;
	
	double strMultiplier; //multipliers refer to the bonuses you get from each class
	double dexMultiplier;
	double agiMultiplier;
public:
	Hero();
	int getStr();
	int getDex();
	int getAgi();
	void levelUp();
	int getMP();
	int getMaxMP();
	void setMP(int);
	int getXP();
	int getMaxXP();
	void setXP(int);
	void usePotion(Potion);
	int getMoney();
	void setMoney(int);
};

class Warrior: public Hero{
public:
	Warrior();
};
class Sorcerer: public Hero{
public:
	Sorcerer();
};
class Paladin: public Hero{
public:
	Paladin();
};

class Monster: public Living{
protected:
	int minDamage;
	int maxDamage;
	int defence;
	int dodge;
	
	double dmgMultiplier;
	double defMultiplier;
	double dodgeMultiplier;
public:
	void setLevel(int);
	int getMinDamage();
	int getMaxDamage();
	int getDefence();
	int getDodge();
	void setMinDamage(int);
	void setMaxDamage(int);
	void setDefence(int);
	void setDodge(int);
};

class Dragon: public Monster{
public:
	Dragon();
};
class Exoskeleton: public Monster{
public:
	Exoskeleton();
};
class Spirit: public Monster{
public:
	Spirit();
};

class Inventory{
public:
	vector<Weapon> weapons;
	vector<Armor> armors;
	vector<Potion> potions;
	vector<IceSpell> iceSpells;
	vector<FireSpell> fireSpells;
	vector<LightningSpell> lightningSpells;
	int totalMoney;
	Inventory();
};

class Equipment: public Inventory{
public:
	Weapon mainHand;
	Weapon offHand;
	Weapon TH_helper; /*This helps us when we equip weapons*/
	Weapon emptyH;		/*This also helps us when we equip weapons*/
	Armor armor;
	Armor armorH;	/*This helps when equipping armor*/
	Equipment();
	int getHandsOccupied();
};

class Character{
private:
	Warrior warrior;
	Sorcerer sorcerer;
	Paladin paladin;
	int heroClass; /*1=Warrior, 2=Sorcerer, 3=Paladin*/
public:
	Equipment equipment;
	void setHeroClass(int);
	void setName(string);
	int getLevel();
	int getStr();
	int getDex();
	int getAgi();
	string getName();
	string getClass();
	int getTotalWeaponDamage();
	int getDefence();
	int getHP();
	int getMaxHP();
	int getMP();
	int getMaxMP();
	void setHP(int);
	void setMP(int);
	int getXP();
	int getMaxXP();
	void setXP(int);
	void usePotion(Potion);
	bool hasFainted();
	int getMoney();
	void setMoney(int);
	void changeEquipment(Inventory, Equipment);
};


class Enemy{
private:
	Dragon dragon;
	Exoskeleton exoskeleton;
	Spirit spirit;
	int monsterType; /*1=Dragon, 2=Exoskeleton, 3=Spirit*/
public:
	void setName(string);
	void setLevel(int);
	string getMonsterType();
	int getLevel();
	int getHP();
	int getMaxHP();
	string getName();
	void setHP(int);
	Enemy();
	int getMinDamage();
	int getMaxDamage();
	int getDefence();
	int getDodge();
	void setMinDamage(int);
	void setMaxDamage(int);
	void setDefence(int);
	void setDodge(int);
	bool hasFainted();
	static bool groupHasFainted(vector<Enemy>,int);
};

class Party{
public:
	vector<Character> character;
	Inventory inventory;
	void checkInventory();
	unsigned int amountOfCharacters;
	void heroCreation();
	void checkStats();
	int getLevelSum();
	char battleStart();
	bool partyHasFainted();
	void displayStats(vector<Enemy>,int);
};

#endif



