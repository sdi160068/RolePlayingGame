#include <iostream>
#include <cstdlib>
#include "Entities.h"

using namespace std;

Living::Living(){
	level=1;
	maxHealthPower=50;
	healthPower=maxHealthPower;
}
void Living::setName(string a){
	name=a;
}
int Living::getLevel(){
	return level;
}
string Living::getName(){
	return name;
}
int Living::getHP(){
	return healthPower;
}
int Living::getMaxHP(){
	return maxHealthPower;
}
void Living::setHP(int a){
	healthPower+= a;
	if (healthPower>maxHealthPower) healthPower=maxHealthPower;
	if (healthPower<0) healthPower=0;
}

Hero::Hero(){
	maxMagicPower=50;
	magicPower=maxMagicPower;
	money=0;
	experience=0;
	maxExperience=100;
}
void Hero::levelUp(){
	level++;
	magicPower=maxMagicPower;
	healthPower=maxHealthPower;
	experience-=maxExperience;
	strength += 1 * strMultiplier;
	dexterity += 1 * dexMultiplier;
	agility += 1 * strMultiplier;
}
int Hero::getStr(){
	return strength;
}
int Hero::getDex(){
	return dexterity;
}
int Hero::getAgi(){
	return agility;
}
int Hero::getMP(){
	return magicPower;
}
int Hero::getMaxMP(){
	return maxMagicPower;
}
void Hero::setMP(int a){
	magicPower+= a;
}
int Hero::getXP(){
	return experience;
}
int Hero::getMaxXP(){
	return maxExperience;
}
void Hero::setXP(int a){
	experience+=a;
	if (experience>=maxExperience) levelUp();
}
void Hero::usePotion(Potion potion){
	strength+= potion.getStrBuff()*strMultiplier;
	dexterity+= potion.getDexBuff()*dexMultiplier;
	agility+= potion.getAgiBuff()*agiMultiplier;
	healthPower+= potion.getHpRestore();
	if (healthPower>maxHealthPower) healthPower=maxHealthPower;
	magicPower+= potion.getMpRestore();
	if (magicPower>maxMagicPower) magicPower=maxMagicPower;
	cout<<"Potion used"<<endl;
}
int Hero::getMoney(){
	return money;
}
void Hero::setMoney(int a){
	money+=a;
}

Warrior::Warrior(){
	strMultiplier=2.0;
	dexMultiplier=1.0;
	agiMultiplier=2.0;
	
	strength=10;
	dexterity=5;
	agility=10;
}
Sorcerer::Sorcerer(){
	strMultiplier=1.0;
	dexMultiplier=2.0;
	agiMultiplier=2.0;
	
	strength=5;
	dexterity=10;
	agility=10;
}
Paladin::Paladin(){
	strMultiplier=2.0;
	dexMultiplier=2.0;
	agiMultiplier=1.0;
	
	strength=10;
	dexterity=5;
	agility=10;
}

void Monster::setLevel(int a){
	level=a;
	/*Sets base values*/
	minDamage=1;
	maxDamage=2;
	defence=1;
	dodge=1;
	
	/*Applies level on the stats*/
	minDamage+= level*1;
	maxDamage+= level*1.5; /*maxDamage is declared as int but it's ok*/
	defence+= level*1;
	dodge+= level*1;
	
	/*Applies monsters' stat boosts*/
	minDamage*= dmgMultiplier;
	maxDamage*= dmgMultiplier;
	defence*= defMultiplier;
	dodge*= dodgeMultiplier;
}
int Monster::getMinDamage(){
	return minDamage;
}
int Monster::getMaxDamage(){
	return maxDamage;
}
int Monster::getDefence(){
	return defence;
}
int Monster::getDodge(){
	return dodge;
}
void Monster::setMinDamage(int a){
	minDamage+=a;
}
void Monster::setMaxDamage(int a){
	maxDamage+=a;
}
void Monster::setDefence(int a){
	defence+=a;
}
void Monster::setDodge(int a){
	dodge+=a;
}
	
Dragon::Dragon(){
	dmgMultiplier=2.0;
	defMultiplier=1.0;
	dodgeMultiplier=1.0;
}
Exoskeleton::Exoskeleton(){
	dmgMultiplier=1.0;
	defMultiplier=2.0;
	dodgeMultiplier=1.0;
}
Spirit::Spirit(){
	dmgMultiplier=1.0;
	defMultiplier=1.0;
	dodgeMultiplier=2.0;
}


void Character::setName(string a){
	switch(heroClass){
		case 1:
			warrior.setName(a);
			break;
		case 2:
			sorcerer.setName(a);
			break;
		case 3:
			paladin.setName(a);
			break;
	}
}
void Character::setHeroClass(int a){
	heroClass=a;
}
string Character::getName(){
	string heroName;
	switch(heroClass){
		case 1:
			heroName = warrior.getName();
			break;
		case 2:
			heroName = sorcerer.getName();
			break;
		case 3:
			heroName = paladin.getName();
			break;
	}
	return heroName;
}
int Character::getLevel(){
	int heroLevel;
	switch(heroClass){
		case 1:
			heroLevel = warrior.getLevel();
			break;
		case 2:
			heroLevel = sorcerer.getLevel();
			break;
		case 3:
			heroLevel = paladin.getLevel();
			break;
	}
	return heroLevel;
}
int Character::getStr(){
	int heroStr;
	switch(heroClass){
		case 1:
			heroStr = warrior.getStr();
			break;
		case 2:
			heroStr = sorcerer.getStr();
			break;
		case 3:
			heroStr = paladin.getStr();
			break;
	}
	return heroStr;
}
int Character::getDex(){
	int heroDex;
	switch(heroClass){
		case 1:
			heroDex = warrior.getDex();
			break;
		case 2:
			heroDex = sorcerer.getDex();
			break;
		case 3:
			heroDex = paladin.getDex();
			break;
	}
	return heroDex;
}
int Character::getAgi(){
	int heroAgi;
	switch(heroClass){
		case 1:
			heroAgi = warrior.getAgi();
			break;
		case 2:
			heroAgi = sorcerer.getAgi();
			break;
		case 3:
			heroAgi = paladin.getAgi();
			break;
	}
	return heroAgi;
}
int Character::getTotalWeaponDamage(){
	int totalDmg;
	totalDmg = equipment.mainHand.getDamage() + equipment.offHand.getDamage();
	return totalDmg;
}
int Character::getDefence(){
	return equipment.armor.getDefence();
}
string Character::getClass(){
	string heroClassStr;
	switch(heroClass){
		case 1:
			heroClassStr="Warrior";
			break;
		case 2:
			heroClassStr="Sorcerer";
			break;
		case 3:
			heroClassStr="Paladin";
			break;
	}
	return heroClassStr;
}
int Character::getMaxHP(){
	int maxHP;
	switch(heroClass){
		case 1:
			maxHP=warrior.getMaxHP();
			break;
		case 2:
			maxHP=sorcerer.getMaxHP();
			break;
		case 3:
			maxHP=paladin.getMaxHP();
			break;
	}
	return maxHP;
}
int Character::getHP(){
	int HP;
	switch(heroClass){
		case 1:
			HP=warrior.getHP();
			break;
		case 2:
			HP=sorcerer.getHP();
			break;
		case 3:
			HP=paladin.getHP();
			break;
	}
	return HP;
}
int Character::getMP(){
	int MP;
	switch(heroClass){
		case 1:
			MP=warrior.getMP();
			break;
		case 2:
			MP=sorcerer.getMP();
			break;
		case 3:
			MP=paladin.getMP();
			break;
	}
	return MP;
}
int Character::getMaxMP(){
	int maxMP;
	switch(heroClass){
		case 1:
			maxMP=warrior.getMaxMP();
			break;
		case 2:
			maxMP=sorcerer.getMaxMP();
			break;
		case 3:
			maxMP=paladin.getMaxMP();
			break;
	}
	return maxMP;
}
void Character::setHP(int a){
	switch(heroClass){
		case 1:
			warrior.setHP(a);
			break;
		case 2:
			sorcerer.setHP(a);
			break;
		case 3:
			paladin.setHP(a);
			break;
	}
}
void Character::setMP(int a){
	switch(heroClass){
		case 1:
			warrior.setMP(a);
			break;
		case 2:
			sorcerer.setMP(a);
			break;
		case 3:
			paladin.setMP(a);
			break;
	}
}
int Character::getXP(){
	int xp;
	switch(heroClass){
		case 1:
			xp=warrior.getXP();
			break;
		case 2:
			xp=sorcerer.getXP();
			break;
		case 3:
			xp=paladin.getXP();
			break;
	}
	return xp;
}
int Character::getMaxXP(){
	int maxxp;
	switch(heroClass){
		case 1:
			maxxp=warrior.getMaxXP();
			break;
		case 2:
			maxxp=sorcerer.getMaxXP();
			break;
		case 3:
			maxxp=paladin.getMaxXP();
			break;
	}
	return maxxp;
}
void Character::setXP(int a){
	switch(heroClass){
		case 1:
			warrior.setXP(a);
			break;
		case 2:
			sorcerer.setXP(a);
			break;
		case 3:
			paladin.setXP(a);
			break;
	}
}
void Character::usePotion(Potion potion){
	switch(heroClass){
		case 1:
			warrior.usePotion(potion);
			break;
		case 2:
			sorcerer.usePotion(potion);
			break;
		case 3:
			paladin.usePotion(potion);
			break;
	}
}
bool Character::hasFainted(){
	if(this->getHP()<=0)
		return 1;
	else
		return 0;
}
int Character::getMoney(){
	int moneyAmount;
	switch(heroClass){
		case 1:
			moneyAmount=warrior.getMoney();
			break;
		case 2:
			moneyAmount=sorcerer.getMoney();
			break;
		case 3:
			moneyAmount=paladin.getMoney();
			break;
	}
	return moneyAmount;
}
void Character::setMoney(int a){
	switch(heroClass){
	case 1:
		warrior.setMoney(a);
		break;
	case 2:
		sorcerer.setMoney(a);
		break;
	case 3:
		paladin.setMoney(a);
		break;
	}
}
void Character::changeEquipment(Inventory inventory, Equipment equipment){
	cout<<"[[[Inventory]]]\n";
	if (inventory.weapons.size()!=0){
		for(int i=0; i<inventory.weapons.size(); i++){
			cout << inventory.weapons[i].getName() << ": " << inventory.weapons[i].getHands() << "-handed | +" << inventory.weapons[i].getDamage() << " damage | Lvl. Requirement: " << inventory.weapons[i].getLevelReq() << endl;
		}
	}
	else
		cout <<"NO WEAPONS"<<endl;
	if (inventory.armors.size()!=0){
		for(int i=0; i<inventory.armors.size(); i++){
			cout << inventory.armors[i].getName() << ": +" << inventory.armors[i].getDefence() << " defence | Lvl. Requirement: " << inventory.armors[i].getLevelReq() << endl;
		}
	}
	else
		cout<<"NO ARMORS"<<endl;
	cout<<"[[[Current Equipment]]]\n";
	cout << equipment.mainHand.getName() << ": " << equipment.mainHand.getHands() << "-handed | +" << equipment.mainHand.getDamage() << " damage\n";
	if (equipment.offHand.getName()=="emptyhand") ;
	else
		cout << equipment.offHand.getName() << ": " << equipment.offHand.getHands() << "-handed | +" << equipment.offHand.getDamage() << " damage\n";
	cout << equipment.armor.getName() << ": +" << equipment.armor.getDefence() << " defence\n\n";
	
	char choice;
	int weaponChoice;
	int armorChoice;
	int handChoice;
	bool weaponLoop;
	bool armorLoop;
	do{
		cout << "You will change your \n1. Weapon\n2. Armor\n3. No changes\n" << endl;
		cin>>choice;
		switch(choice){
			case '1':
				if (inventory.weapons.size()!=0){
					cout << "[[[Weapons]]]\n";
					for(int i=0; i<inventory.weapons.size(); i++){
						cout << i+1 << ". "<<inventory.weapons[i].getName() << ": " << inventory.weapons[i].getHands() << "-handed | +" << inventory.weapons[i].getDamage() << " damage | Lvl. Requirement: " << inventory.weapons[i].getLevelReq() << endl;
					}
					cout << "Which weapon do you want to equip?\n";
					do{
					
						cin>>weaponChoice;
						if (weaponChoice>inventory.weapons.size()+1){
							cout<<"Enter a valid number"<<endl;
							weaponLoop=true;
						}
						else{
							weaponLoop=false;
							if(inventory.weapons[weaponChoice-1].getLevelReq() > this->getLevel()){
								cout<<"Insufficient character level"<<endl;
							}
							else if(inventory.weapons[weaponChoice-1].getHands()==2){
								equipment.TH_helper=inventory.weapons[weaponChoice-1];
								inventory.weapons[weaponChoice-1]=equipment.mainHand;
								equipment.mainHand=equipment.TH_helper;
								if(equipment.offHand.getName()=="emptyhand");
								else{
									inventory.weapons.push_back(equipment.offHand);
									equipment.offHand=equipment.emptyH;
								}
							}
							else{
								do{
									cout << "Do you want to replace your 1. First or your 2. Second weapon?" << endl;
									cin >> handChoice;
								}while (handChoice!=1 && handChoice!=2);
								if(handChoice==1){
									equipment.TH_helper=inventory.weapons[weaponChoice-1];
									inventory.weapons[weaponChoice-1]=equipment.mainHand;
									equipment.mainHand=equipment.TH_helper;
								}
								else{
									equipment.TH_helper=inventory.weapons[weaponChoice-1];
									inventory.weapons[weaponChoice-1]=equipment.offHand;
									equipment.offHand=equipment.TH_helper;
								}
							}
						}
						cout<<"Done"<<endl;
					}while(weaponLoop);
				}
				else
					cout << "What part of 'NO WEAPONS' do you not understand?"<<endl;
				break;
			case '2':
				if (inventory.armors.size()!=0){
					for(int i=0; i<inventory.armors.size(); i++){
						cout << i+1 << ". " <<inventory.armors[i].getName() << ": +" << inventory.armors[i].getDefence() << " defence | Lvl. Requirement: " << inventory.armors[i].getLevelReq() << endl;
					}
					cout << "Which armor do you want to equip?\n";
					do{
						cin>>armorChoice;
						if(armorChoice>inventory.weapons.size()+1){
							cout<<"Enter a valid number"<<endl;
							armorLoop=true;
						}
						else{
							armorLoop=false;
							if(inventory.armors[armorChoice-1].getLevelReq() > this->getLevel()){
								cout<<"Insufficient character level"<<endl;
							}
							else{
								equipment.armorH=inventory.armors[armorChoice-1];
								inventory.armors[armorChoice-1]=equipment.armor;
								equipment.armor=equipment.armorH;
							}
						}
					}while(armorLoop);
				}
				else
					cout << "What part of 'NO ARMORS' do you not understand?"<<endl;
				break;
			case '3':
				break;
			default:
				break;
		}
	}while(choice!='1' && choice!='2' && choice!='3');	
}

/* Enemy::section -----------------------------------------------------------------*/

Enemy::Enemy(){
	monsterType = (rand() % 3) + 1; /*Number between 1 and 3*/
}
void Enemy::setName(string a){
	switch(monsterType){
		case 1:
			dragon.setName(a);
			break;
		case 2:
			exoskeleton.setName(a);
			break;
		case 3:
			spirit.setName(a);
			break;
	}
}
void Enemy::setLevel(int a){
	switch(monsterType){
		case 1:
			dragon.setLevel(a);
			break;
		case 2:
			exoskeleton.setLevel(a);
			break;
		case 3:
			spirit.setLevel(a);
			break;
	}
}
string Enemy::getMonsterType(){
	string monsterTypeStr;
	switch(monsterType){
		case 1:
			monsterTypeStr="Dragon";
			break;
		case 2:
			monsterTypeStr="Exoskeleton";
			break;
		case 3:
			monsterTypeStr="Spirit";
			break;
	}
	return monsterTypeStr;
}
int Enemy::getHP(){
	int HP;
	switch(monsterType){
		case 1:
			HP=dragon.getHP();
			break;
		case 2:
			HP=exoskeleton.getHP();
			break;
		case 3:
			HP=spirit.getHP();
			break;
	}
	return HP;
}
int Enemy::getMaxHP(){
	int maxHP;
	switch(monsterType){
		case 1:
			maxHP=dragon.getMaxHP();
			break;
		case 2:
			maxHP=exoskeleton.getMaxHP();
			break;
		case 3:
			maxHP=spirit.getMaxHP();
			break;
	}
	return maxHP;
}
string Enemy::getName(){
	string name;
	switch(monsterType){
		case 1:
			name=dragon.getName();
			break;
		case 2:
			name=exoskeleton.getName();
			break;
		case 3:
			name=spirit.getName();
			break;
	}
	return name;
}
void Enemy::setHP(int a){
	switch(monsterType){
		case 1:
			dragon.setHP(a);
			break;
		case 2:
			exoskeleton.setHP(a);
			break;
		case 3:
			spirit.setHP(a);
			break;
	}
}
int Enemy::getLevel(){
	int level;
	switch(monsterType){
		case 1:
			level=dragon.getLevel();
			break;
		case 2:
			level=exoskeleton.getLevel();
			break;
		case 3:
			level=spirit.getLevel();
			break;
	}
	return level;
}
int Enemy::getMinDamage(){
	int minDamage;
	switch(monsterType){
		case 1:
			minDamage=dragon.getMinDamage();
			break;
		case 2:
			minDamage=exoskeleton.getMinDamage();
			break;
		case 3:
			minDamage=spirit.getMinDamage();
			break;
	}
	return minDamage;
}
int Enemy::getMaxDamage(){
	int maxDamage;
	switch(monsterType){
		case 1:
			maxDamage=dragon.getMaxDamage();
			break;
		case 2:
			maxDamage=exoskeleton.getMaxDamage();
			break;
		case 3:
			maxDamage=spirit.getMaxDamage();
			break;
	}
	return maxDamage;
}
int Enemy::getDefence(){
	int defence;
	switch(monsterType){
		case 1:
			defence=dragon.getDefence();
			break;
		case 2:
			defence=exoskeleton.getDefence();
			break;
		case 3:
			defence=spirit.getDefence();
			break;
	}
	return defence;
}
int Enemy::getDodge(){
	int dodge;
	switch(monsterType){
		case 1:
			dodge=dragon.getDodge();
			break;
		case 2:
			dodge=exoskeleton.getDodge();
			break;
		case 3:
			dodge=spirit.getDodge();
			break;
	}
	return dodge;
}
void Enemy::setMinDamage(int a){
	switch(monsterType){
		case 1:
			dragon.setMinDamage(a);
			break;
		case 2:
			exoskeleton.setMinDamage(a);
			break;
		case 3:
			spirit.setMinDamage(a);
			break;
	}
}
void Enemy::setMaxDamage(int a){
	switch(monsterType){
		case 1:
			dragon.setMaxDamage(a);
			break;
		case 2:
			exoskeleton.setMaxDamage(a);
			break;
		case 3:
			spirit.setMaxDamage(a);
			break;
	}
}
void Enemy::setDefence(int a){
	switch(monsterType){
		case 1:
			dragon.setDefence(a);
			break;
		case 2:
			exoskeleton.setDefence(a);
			break;
		case 3:
			spirit.setDefence(a);
			break;
	}
}
void Enemy::setDodge(int a){
	switch(monsterType){
		case 1:
			dragon.setDodge(a);
			break;
		case 2:
			exoskeleton.setDodge(a);
			break;
		case 3:
			spirit.setDodge(a);
			break;
	}
}
bool Enemy::hasFainted(){
	if(this->getHP()<=0)
		return 1;
	else
		return 0;
}
bool Enemy::groupHasFainted(vector<Enemy> enemy, int amountOfEnemies){
	int amountOfFaintedEnemies=0;
	bool hasIndeedFainted=false;
	for(int i=0; i<amountOfEnemies; i++){
		if(enemy[i].hasFainted()) amountOfFaintedEnemies++;
	}
	if (amountOfFaintedEnemies==amountOfEnemies) hasIndeedFainted=true;
	return hasIndeedFainted;
}

