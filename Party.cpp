#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Items.h"
#include "Entities.h"

using namespace std;

Inventory::Inventory(){
	IceSpell snowball("Snowball",0,0,1,3,1,1);
	iceSpells.push_back(snowball);
	FireSpell embers("Ember",0,0,1,3,1,1);
	fireSpells.push_back(embers);
	LightningSpell lilspark("Spark",0,0,1,3,1,1);
	lightningSpells.push_back(lilspark);
	totalMoney=0;
}

Equipment::Equipment(){
	Weapon woodensword("Wooden Sword", 0, 0, 1, 1), emptyhand("emptyhand", 0, 0, 0, 0);
	Armor rags("Rags", 0, 0, 1);
	mainHand=woodensword;
	offHand=emptyhand;
	TH_helper=emptyhand;
	emptyH=emptyhand;
	armor=rags;
}
int Equipment::getHandsOccupied(){
	int handsOccupied=0;
	handsOccupied = mainHand.getHands() + offHand.getHands();
	return handsOccupied;
}


void Party::heroCreation(){
	cout << "Welcome to The Game!\nHow many heroes do you want to create?(You can have 1, 2 or 3 heroes)" << endl;
	char tempChar;
	cin >> tempChar;
	while (tempChar!='1' && tempChar!='2' && tempChar!='3'){
		cout << "You must enter '1', '2' or '3'" << endl;
		cin >> tempChar;
	}
	amountOfCharacters = tempChar - 48;
	
	cout << "A hero can be\n(1) a Warrior, an agile hard-hitting fighter \n(2) a Sorcerer, an agile cunning spellcaster \n(3) a Paladin, who uses both weapons and magic at the cost of mobility" << endl;
	
	for(unsigned int i=0; i<amountOfCharacters; i++){
		Character newChar;
		character.push_back(newChar);
		cout << "\nWhat will be your " << i+1 << "th hero?" <<endl;
		char j;
		do{
			cin >> j;
			switch (j) {
				case '1': 
					character[i].setHeroClass(1);
		  			break;
				case '2':
	  				character[i].setHeroClass(2);
	  				break;
	  			case '3':
	  				character[i].setHeroClass(3);
	  				break;
				default:
	  				cout << "Enter '1' for Warrior, '2' for Sorcerer or '3' for Paladin" << endl;
	  				break;
			}
		}while (j!='1' && j!='2' && j!='3');
		cout << "And what will their name be? (please don't use spaces)" << endl;
		string heroName;
		cin >> heroName;
		character[i].setName(heroName);
		cout << endl;
	}
}

void Party::checkInventory(){
	for(unsigned int i=0; i<amountOfCharacters; i++){
		cout << "[[[" << character[i].getName() << "'s equipped items]]]\n";
		cout << character[i].equipment.mainHand.getName() << ": " << character[i].equipment.mainHand.getHands() << "-handed | +" << character[i].equipment.mainHand.getDamage() << " damage\n";
		if (character[i].equipment.offHand.getName()=="emptyhand") ;
		else
			cout << character[i].equipment.offHand.getName() << ": " << character[i].equipment.offHand.getHands() << "-handed | +" << character[i].equipment.offHand.getDamage() << " damage\n";
		cout << character[i].equipment.armor.getName() << ": +" << character[i].equipment.armor.getDefence() << " defence\n\n";
	}
	cout << "[[[Shared Inventory]]]" << endl;
	if (inventory.weapons.size()!=0){
		for(unsigned int i=0; i<inventory.weapons.size(); i++){
			cout << inventory.weapons[i].getName() << ": " << inventory.weapons[i].getHands() << "-handed | +" << inventory.weapons[i].getDamage() << " damage | Lvl. Requirement: " << inventory.weapons[i].getLevelReq() << endl;
		}
	}
	else
		cout <<"NO WEAPONS"<<endl;
	if (inventory.armors.size()!=0){
		for(unsigned int i=0; i<inventory.armors.size(); i++){
			cout << inventory.armors[i].getName() << ": +" << inventory.armors[i].getDefence() << " defence | Lvl. Requirement: " << inventory.armors[i].getLevelReq() << endl;
		}
	}
	else
		cout<<"NO ARMORS"<<endl;
	if (inventory.potions.size()!=0){
		for(unsigned int i=0; i<inventory.potions.size(); i++){
			cout<<inventory.potions[i].getName()<<": +"<<inventory.potions[i].getStrBuff()<<" Str, +"<<inventory.potions[i].getDexBuff()<<" Dex, +"<< inventory.potions[i].getAgiBuff()<<" Agi, "
			<<inventory.potions[i].getHpRestore()<<" Hp restore, "<<inventory.potions[i].getMpRestore()<<" Mp restore\n";
		}
	}
	else
		cout<<"NO POTIONS"<<endl;
	if (inventory.fireSpells.size()!=0){
		for(unsigned int i=0; i<inventory.fireSpells.size(); i++){
			cout<<inventory.fireSpells[i].getName()<<": "<<inventory.fireSpells[i].getMinDamage()<<"-"<<inventory.fireSpells[i].getMaxDamage()<<" damage | "<<inventory.fireSpells[i].getMpCost()<<" MP cost, -"<<inventory.fireSpells[i].getDefenceReduction()<<" enemy defence\n";
		}
	}
	else
		cout<<"NO FIRESPELLS"<<endl;
	if (inventory.iceSpells.size()!=0){
		for(unsigned int i=0; i<inventory.iceSpells.size(); i++){
			cout<<inventory.iceSpells[i].getName()<<": "<<inventory.iceSpells[i].getMinDamage()<<"-"<<inventory.iceSpells[i].getMaxDamage()<<" damage | "<<inventory.iceSpells[i].getMpCost()<<" MP cost, -"<<inventory.iceSpells[i].getDamageReduction()<<" enemy damage\n";
		}
	}
	else
		cout<<"NO ICESPELLS"<<endl;
	if (inventory.lightningSpells.size()!=0){
		for(unsigned int i=0; i<inventory.lightningSpells.size(); i++){
			cout<<inventory.lightningSpells[i].getName()<<": "<<inventory.lightningSpells[i].getMinDamage()<<"-"<<inventory.lightningSpells[i].getMaxDamage()<<" damage | "
			<<inventory.lightningSpells[i].getMpCost()<<" MP cost, -"<<inventory.lightningSpells[i].getDodgeReduction()<<"% enemy dodge\n\n";
		}
	}
	else
		cout<<"NO LIGHTNINGSPELLS"<<endl<<endl;
	
}

void Party::checkStats(){
	for(unsigned int i=0; i<amountOfCharacters; i++){
		cout << "[[[" << character[i].getName() << " ("<< character[i].getClass() <<") Lvl. " << character[i].getLevel() << "]]]\n";
		cout << "HP: "<<character[i].getHP()<<"/"<<character[i].getMaxHP()<<" | MP: "<<character[i].getMP()<<"/"<<character[i].getMaxMP()<<" | XP: "<<character[i].getXP()<<"/"<<character[i].getMaxXP()<< endl;
		cout << "STRENGTH: " << character[i].getStr() << endl;
		cout << "DEXTERITY: " << character[i].getDex() << endl;
		cout << "AGILITY: " << character[i].getAgi() << endl;
		cout << "WEAPON DAMAGE: " << character[i].getTotalWeaponDamage() << endl;
		cout << "ARMOR DEFENCE: " << character[i].getDefence() << endl;
		cout << "MONEY: " << character[i].getMoney() << "G" << endl <<endl;
	}
}
int Party::getLevelSum(){
	int levelSum=0;
	for(unsigned int i=0; i<amountOfCharacters; i++){
		levelSum+=character[i].getLevel();
	}
	return levelSum;
}
bool Party::partyHasFainted(){
	unsigned int amountOfFaintedCharacters=0;
	bool hasFainted=false;
	for(unsigned int i=0; i<amountOfCharacters; i++){
		if(character[i].hasFainted()) amountOfFaintedCharacters++;
	}
	if (amountOfFaintedCharacters==amountOfCharacters) hasFainted=true;
	return hasFainted;
}
void Party::displayStats(vector<Enemy> enemy, int amountOfEnemies){
	this->checkStats();
	for(int i=0; i<amountOfEnemies; i++){
		cout << "[[[" << enemy[i].getName() << " ("<< enemy[i].getMonsterType() <<") Lvl. " << enemy[i].getLevel() << "]]]\n";
		cout << "HP: "<< enemy[i].getHP() << "/" << enemy[i].getMaxHP() << endl;
		cout << "DAMAGE: " << enemy[i].getMinDamage() << "-" << enemy[i].getMaxDamage()<< endl;
		cout << "DEFENCE: " << enemy[i].getDefence() << endl;
		cout << "DODGE CHANCE: " << enemy[i].getDodge() << "%\n\n";
	}
}

char Party::battleStart(){
	srand(time(NULL));
	bool endOfFight;
	char command;
	char target;
	bool loop;
	bool victory;
	bool choiceLoop;
	char magicChoice;
	int spellChoice;
	int potionChoice;
	int hitChance;
	int damageDealt;
	int randomSpellDamage;
	int randomPhysicalDamage;
	int heroLevelSum;
	int monsterLevel;
	int monsterLevelSum;
	int monsterLevelVariance;
	unsigned int amountOfEnemies;
	vector<Enemy> enemy;
	heroLevelSum = getLevelSum();
	monsterLevelSum = heroLevelSum;
	amountOfEnemies = (rand() % 3) + 1; /*A number between 1 and 3*/
	monsterLevel = monsterLevelSum / amountOfEnemies;
	monsterLevelVariance = (rand() % 5) - 2; /*A number between -2 and +2*/
	monsterLevel += monsterLevelVariance;
	if (monsterLevel<0) monsterLevel = (-1) * monsterLevel; /*Just in case something goes wrong*/ 
	
	for(unsigned int i=0; i<amountOfEnemies; i++){
		Enemy newEnemy;
		newEnemy.setName("Monster");
		newEnemy.setLevel(monsterLevel);
		enemy.push_back(newEnemy);
	}
	
	endOfFight=false;
	while(true){
		/*Party's turn to attack*/
		if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
			victory=true;
			endOfFight=true;
			break;
		}
		else if (Party::partyHasFainted()){
			victory=false;
			endOfFight=true;
		}
		for(unsigned int k=0; k<amountOfCharacters; k++){
			if(!character[k].hasFainted()){
				cout<<"\n\n_____________________\n";
				for(unsigned int i=0; i<amountOfCharacters; i++){
					cout << character[i].getName() << " ("<< character[i].getClass() << " Lvl." << character[i].getLevel() <<") [HP: " << character[i].getHP() << "/" << character[i].getMaxHP() << "  MP: " << character[i].getMP() <<"/" << character[i].getMaxMP() << "]\n";
				}
				cout << "\n\n";
				for(unsigned int j=0; j<amountOfEnemies; j++){
					cout << j+1 << ". " << enemy[j].getName() << " ("<< enemy[j].getMonsterType() << " Lvl." << enemy[j].getLevel() <<") [HP: " << enemy[j].getHP() << "/" << enemy[j].getMaxHP() << "]\n";
				}
				cout<<"______________________\n";
				cout<<"What will " << character[k].getName() << " do?" <<endl;
				do{
					cout<<"1. attack\n" <<"2. castSpell\n" <<"3. use\n" <<"4. Change Equipment\n"<<"5. displayStats\n"<<"q. quitGame\n\n";
					choiceLoop=false;
					cin >> command;
					switch(command){
						case '1': /*Attack choice*/
							cout<<"Attack which monster?"<<endl;
							do{
								cin >> target;
								switch(target){
									case '1':
										if(enemy[0].hasFainted()){
											cout<<"Target has already fainted"<<endl;
											loop=true;
										} 
										else if ((character[k].getStr() + character[k].getTotalWeaponDamage()) > enemy[0].getDefence()){
											loop=false;
											hitChance=rand() % 100;
											if (hitChance>=enemy[0].getDodge()){
												damageDealt= character[k].getStr() + character[k].getTotalWeaponDamage() - enemy[0].getDefence();
												enemy[0].setHP((-1)*damageDealt);
												cout << character[k].getName() << " dealt "<< damageDealt<<" damage"<<endl;
											}
											else
												cout << "The monster dodged the attack"<<endl;
										}
										else{
											cout << "The defences of "<< enemy[0].getName() <<" are too high and negated " << character[k].getName()<<"'s attack"<<endl;
											loop=false;
										}
										if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
											victory=true;
											endOfFight=true;
											break;
										}
										else if (Party::partyHasFainted()){
											victory=false;
											endOfFight=true;
											break;
										}
										break;
									case '2':
										if(2>amountOfEnemies){
											loop=true;
										}
										else if(enemy[1].hasFainted()){
											cout<<"Target has already fainted"<<endl;
											loop=true;
										} 
										else if (character[k].getStr() + character[k].getTotalWeaponDamage() > enemy[1].getDefence()){
											loop=false;
											hitChance=rand() % 100;
											if (hitChance>=enemy[1].getDodge()){
												damageDealt= character[k].getStr() + character[k].getTotalWeaponDamage() - enemy[1].getDefence();
												enemy[1].setHP((-1)*damageDealt);
												cout << character[k].getName() << " dealt "<< damageDealt<<" damage"<<endl;
											}
											else
												cout << "The monster dodged the attack"<<endl;
										}
										else{
											cout << "The defences of "<< enemy[1].getName() <<" are too high and negated " << character[k].getName()<<"'s attack"<<endl;
											loop=false;
										}
										if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
											victory=true;
											endOfFight=true;
											break;
										}
										else if (Party::partyHasFainted()){
											victory=false;
											endOfFight=true;
											break;
										}
										break;
									case '3':
										if(3>amountOfEnemies){
											loop=true;
										}
										else if(enemy[2].hasFainted()){
											cout<<"Target has already fainted"<<endl;
											loop=true;
										} 
										else if (character[k].getStr() + character[k].getTotalWeaponDamage() > enemy[2].getDefence()){
											loop=false;
											hitChance=rand() % 100;
											if (hitChance>=enemy[2].getDodge()){
												damageDealt= character[k].getStr() + character[k].getTotalWeaponDamage() - enemy[2].getDefence();
												enemy[2].setHP((-1)*damageDealt);
												cout << character[k].getName() << " dealt "<< damageDealt<<" damage"<<endl;
											}
											else
												cout << "The monster dodged the attack"<<endl;
										}
										else{
											cout << "The defences of "<< enemy[2].getName() <<" are too high and negated " << character[k].getName()<<"'s attack"<<endl;
											loop=false;
										}
										if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
											victory=true;
											endOfFight=true;
											break;
										}
										else if (Party::partyHasFainted()){
											victory=false;
											endOfFight=true;
											break;
										}
										break;
									default:
										cout << "Choose a valid number"<<endl;
										loop=true;
										break;
								}
								if(endOfFight==true) break;
							}while(loop);
				  			break;
						case '2': /*Magic choice*/
							cout<<"What school of magic will they use?"<<endl;
							cout<<"1. Ice\n" << "2. Fire\n" << "3. Lightning\n";
							cin>>magicChoice;
							switch(magicChoice){
								case '1'://------------------------------------------------------------------------------------------------------------------------------------------------------------------
									for(unsigned int l=0; l<inventory.iceSpells.size(); l++){
										cout<<l+1<<". "<<inventory.iceSpells[l].getName()<<": "<<inventory.iceSpells[l].getMinDamage()<<"-"<<inventory.iceSpells[l].getMaxDamage()<<" BASE damage | "<<inventory.iceSpells[l].getMpCost()<<" MP cost, -"<<inventory.iceSpells[l].getDamageReduction()<<" enemy damage\n";
									}
									cout<<"Which spell will they use?"<<endl;
									cin>>spellChoice;
									do{
										cout<<"On which monster will they cast the spell?"<<endl;
										cin >> target;
										switch(target){
											case '1':
												if(enemy[0].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.iceSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[0].getDodge()){
														randomSpellDamage=rand() % (inventory.iceSpells[spellChoice-1].getMaxDamage() - inventory.iceSpells[spellChoice-1].getMinDamage() + 1) +inventory.iceSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[0].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[0].setHP((-1)*damageDealt);
														enemy[0].setMinDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														enemy[0].setMaxDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Damage by "<< inventory.iceSpells[spellChoice-1].getDamageReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											case '2':
												if(2>amountOfEnemies){
													loop=true;
												}
												else if(enemy[1].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.iceSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[1].getDodge()){
														randomSpellDamage=rand() % (inventory.iceSpells[spellChoice-1].getMaxDamage() - inventory.iceSpells[spellChoice-1].getMinDamage() + 1) +inventory.iceSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[1].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[1].setHP((-1)*damageDealt);
														enemy[1].setMinDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														enemy[1].setMaxDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Damage by "<< inventory.iceSpells[spellChoice-1].getDamageReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											case '3':
												if(3>amountOfEnemies){
													loop=true;
												}
												else if(enemy[2].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.iceSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[2].getDodge()){
														randomSpellDamage=rand() % (inventory.iceSpells[spellChoice-1].getMaxDamage() - inventory.iceSpells[spellChoice-1].getMinDamage() + 1) +inventory.iceSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[2].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[2].setHP((-1)*damageDealt);
														enemy[2].setMinDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														enemy[2].setMaxDamage((-1) * inventory.iceSpells[spellChoice-1].getDamageReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Damage by "<< inventory.iceSpells[spellChoice-1].getDamageReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											default:
												cout << "Choose a valid number"<<endl;
												loop=true;
												break;
										}
										if(endOfFight==true) break;
									}while(loop);
									break;
								case '2'://---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
									for(unsigned int l=0; l<inventory.fireSpells.size(); l++){
										cout<<l+1<<". "<<inventory.fireSpells[l].getName()<<": "<<inventory.fireSpells[l].getMinDamage()<<"-"<<inventory.fireSpells[l].getMaxDamage()<<" BASE damage | "<<inventory.fireSpells[l].getMpCost()<<" MP cost, -"<<inventory.fireSpells[l].getDefenceReduction()<<" enemy defence\n";
									}
									cout<<"Which spell will they use?"<<endl;
									cin>>spellChoice;
									do{
										cout<<"On which monster will they cast the spell?"<<endl;
										cin >> target;
										switch(target){
											case '1':
												if(enemy[0].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.fireSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[0].getDodge()){
														randomSpellDamage=rand() % (inventory.fireSpells[spellChoice-1].getMaxDamage() - inventory.fireSpells[spellChoice-1].getMinDamage() + 1) +inventory.fireSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[0].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[0].setHP((-1)*damageDealt);
														enemy[0].setDefence((-1) * inventory.fireSpells[spellChoice-1].getDefenceReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Defence by "<< inventory.fireSpells[spellChoice-1].getDefenceReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;//---------------------------adsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
											case '2':
												if(2>amountOfEnemies){
													loop=true;
												}
												else if(enemy[1].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.fireSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[1].getDodge()){
														randomSpellDamage=rand() % (inventory.fireSpells[spellChoice-1].getMaxDamage() - inventory.fireSpells[spellChoice-1].getMinDamage() + 1) +inventory.fireSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[1].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[1].setHP((-1)*damageDealt);
														enemy[1].setDefence((-1) * inventory.fireSpells[spellChoice-1].getDefenceReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Defence by "<< inventory.fireSpells[spellChoice-1].getDefenceReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											case '3':
												if(3>amountOfEnemies){
													loop=true;
												}
												else if(enemy[2].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.fireSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[2].getDodge()){
														randomSpellDamage=rand() % (inventory.fireSpells[spellChoice-1].getMaxDamage() - inventory.fireSpells[spellChoice-1].getMinDamage() + 1) +inventory.fireSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[2].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[2].setHP((-1)*damageDealt);
														enemy[2].setDefence((-1) * inventory.fireSpells[spellChoice-1].getDefenceReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Defence by "<< inventory.fireSpells[spellChoice-1].getDefenceReduction() <<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											default:
												cout << "Choose a valid number"<<endl;
												loop=true;
												break;
										}
										if(endOfFight) break;
									}while(loop);
									break;
								case '3':
									for(unsigned int l=0; l<inventory.lightningSpells.size(); l++){
										cout<<l+1<<". "<<inventory.lightningSpells[l].getName()<<": "<<inventory.lightningSpells[l].getMinDamage()<<"-"<<inventory.lightningSpells[l].getMaxDamage()<<" BASE damage | "
											<<inventory.lightningSpells[l].getMpCost()<<" MP cost, -"<<inventory.lightningSpells[l].getDodgeReduction()<<"% enemy dodge\n\n";
									}
									cout<<"Which spell will they use?"<<endl;
									cin>>spellChoice;
									do{
										cout<<"On which monster will they cast the spell?"<<endl;
										cin >> target;
										switch(target){
											case '1':
												if(enemy[0].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.lightningSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[0].getDodge()){
														randomSpellDamage=rand() % (inventory.lightningSpells[spellChoice-1].getMaxDamage() - inventory.lightningSpells[spellChoice-1].getMinDamage() + 1) +inventory.lightningSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[0].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[0].setHP((-1)*damageDealt);
														enemy[0].setDodge((-1) * inventory.lightningSpells[spellChoice-1].getDodgeReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Dodge chance by "<< inventory.lightningSpells[spellChoice-1].getDodgeReduction() <<"%"<<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;//---------------------------adsaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
											case '2':
												if(2>amountOfEnemies){
													loop=true;
												}
												else if(enemy[1].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.lightningSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[1].getDodge()){
														randomSpellDamage=rand() % (inventory.lightningSpells[spellChoice-1].getMaxDamage() - inventory.lightningSpells[spellChoice-1].getMinDamage() + 1) +inventory.lightningSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[1].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[1].setHP((-1)*damageDealt);
														enemy[1].setDodge((-1) * inventory.lightningSpells[spellChoice-1].getDodgeReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Dodge chance by"<< inventory.lightningSpells[spellChoice-1].getDodgeReduction() <<"%"<<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											case '3':
												if(3>amountOfEnemies){
													loop=true;
												}
												else if(enemy[2].hasFainted()){
													cout<<"Target has already fainted"<<endl;
													loop=true;
												} 
												else{
													loop=false;
													character[k].setMP((-1)*inventory.lightningSpells[spellChoice-1].getMpCost());
													hitChance=rand() % 100;
													if (hitChance>=enemy[2].getDodge()){
														randomSpellDamage=rand() % (inventory.lightningSpells[spellChoice-1].getMaxDamage() - inventory.lightningSpells[spellChoice-1].getMinDamage() + 1) +inventory.lightningSpells[spellChoice-1].getMinDamage();
														damageDealt= character[k].getDex() * randomSpellDamage - enemy[2].getDefence();
														if (damageDealt<0) damageDealt=0;
														enemy[2].setHP((-1)*damageDealt);
														enemy[2].setDodge((-1) * inventory.lightningSpells[spellChoice-1].getDodgeReduction());
														cout << character[k].getName() << " dealt "<< damageDealt<<" magic damage and reduced the monster's Dodge chance by "<< inventory.lightningSpells[spellChoice-1].getDodgeReduction() <<"%"<<endl;
													}
													else
														cout << "The monster dodged the spell"<<endl;
												}
												if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
													victory=true;
													endOfFight=true;
													break;
												}
												else if (Party::partyHasFainted()){
													victory=false;
													endOfFight=true;
													break;
												}
												break;
											default:
												cout << "Choose a valid number"<<endl;
												loop=true;
												break;
										}
										if(endOfFight) break;
									}while(loop);
									break;
								default:
									break;
							}
			  				break;
			  			case '3':
			  				for(unsigned int l=0; l<inventory.potions.size(); l++){
								cout<< l+1 <<". "<<inventory.potions[l].getName()<<": +"<<inventory.potions[l].getStrBuff()<<" Str, +"<<inventory.potions[l].getDexBuff()<<" Dex, +"<< inventory.potions[l].getAgiBuff()<<" Agi, "
									<<inventory.potions[l].getHpRestore()<<" Hp restore, "<<inventory.potions[l].getMpRestore()<<" Mp restore\n";
							}
							if (inventory.potions.size()==0){
								cout<< "There are no potions in the party's inventory to use\n";
								choiceLoop=true;
							}
							else{
								cout<<"Which potion will they use?"<<endl;
								cin>>potionChoice;
								character[k].usePotion(inventory.potions[potionChoice-1]);
								inventory.potions.erase(inventory.potions.begin()+potionChoice-1);
							}
			  				break;
			  			case '4':
			  				character[k].changeEquipment(this->inventory, character[k].equipment);
			  				choiceLoop=true;
			  				break;
			  			case '5':
			  				cout<<"___________________________________________________________\n";
			  				displayStats(enemy,amountOfEnemies);
			  				cout<<"___________________________________________________________\n";
			  				choiceLoop=true;
			  				break;
						case 'q':
							return 'q';
							break;
						default:
			  				cout << "\nType 1, 2, 3, 4, 5 or q\n" << endl;
			  				choiceLoop=true;
			  				break;
					}
					if(endOfFight) break;
				}while(command!='1' && command!='2' && choiceLoop==true);
			}
			if(endOfFight) break;
		}
		if(endOfFight) break;
		
		/*Enemies' turn to attack*/
		if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
			victory=true;
			endOfFight=true;
			break;
		}
		else if (Party::partyHasFainted()){
			victory=false;
			endOfFight=true;
			break;
		}
		for(unsigned int k=0; k<amountOfEnemies; k++){
			if(enemy[k].getHP()>0){
				unsigned int l=0;
				do{
					if (!character[l].hasFainted()){
						loop=false;
						hitChance=rand() % 100;
						if (hitChance>=character[l].getAgi()){
							randomPhysicalDamage=rand() % (enemy[k].getMaxDamage() - enemy[k].getMinDamage() + 1) + enemy[k].getMinDamage();
							damageDealt= randomPhysicalDamage - character[l].getDefence();
							character[l].setHP((-1)*damageDealt);
								cout << enemy[k].getName() << " dealt "<< damageDealt<<" damage to "<< character[l].getName() <<endl;
						}
						else
							cout << character[l].getName() << " dodged "<< enemy[k].getName() <<"'s attack"<<endl;
					}
					else {
						loop=true;
						l++;
					}
					if (Enemy::groupHasFainted(enemy,amountOfEnemies)){
						victory=true;
						endOfFight=true;
						break;
					}
					else if (Party::partyHasFainted()){
						victory=false;
						endOfFight=true;
						break;
					}
					if(endOfFight) break;
				}while(loop);
				if(endOfFight) break;
			}
			if (endOfFight) break;
		}
		/*End of turn*/
		for(unsigned int k=0; k<amountOfCharacters; k++){
			if (!character[k].hasFainted()){
				if(character[k].getHP() != character[k].getMaxHP())	character[k].setHP(1);
				if(character[k].getMP() != character[k].getMaxMP())	character[k].setMP(1);
			}
		} /*regeneration sequence*/
		for(unsigned int k=0; k<amountOfEnemies; k++){
			if (!enemy[k].hasFainted())
				if(enemy[k].getHP() != enemy[k].getMaxHP())	enemy[k].setHP(1);
		}
		
		if(endOfFight) break;
		
	}
	
	/*battle has ended*/
	if (victory){
		cout<< "\n|||||||||||||||||||||||||";
		cout<< "\n||    V I C T O R Y    ||";
		cout<< "\n|||||||||||||||||||||||||\n\n";
		for(unsigned int i=0; i<amountOfCharacters; i++){
			character[i].setMoney(character[i].getLevel() * amountOfEnemies * 10);
			character[i].setXP(character[i].getLevel() * amountOfEnemies * 10);
			inventory.totalMoney+= character[i].getLevel() * amountOfEnemies * 10;
			cout<< character[i].getName() << " got " << character[i].getLevel() * amountOfEnemies * 10 << " gold and " << character[i].getLevel() * amountOfEnemies * 10<< " experience points\n";
			
		}
	}
	else
	{
		cout<< "\n|||||||||||||||||||||||||";
		cout<< "\n||     D E F E A T     ||";
		cout<< "\n|||||||||||||||||||||||||\n\n";
		for(unsigned int i=0; i<amountOfCharacters; i++){
			cout << character[i].getName() << " lost " << character[i].getMoney() / 2 << " gold"<<endl;
			inventory.totalMoney-= character[i].getMoney() / 2;
			character[i].setMoney( (-1) * (character[i].getMoney() / 2));
		}
	}
	for(unsigned int i=0; i<amountOfCharacters; i++)
		if (character[i].hasFainted()){
			character[i].setHP(character[i].getMaxHP() / 2);
			cout << character[i].getName() << "'s HP was restored to half"<<endl;
		}
	return 'z';
}