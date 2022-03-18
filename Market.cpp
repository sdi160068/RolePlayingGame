#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Items.h"
#include "Market.h"
#include "Entities.h"
#include "Spells.h"


using namespace std;

Market::Market(){
	this->set_Items();
}
Market::~Market(){
	delete weapon;
	delete armor;
	delete potion;
	delete icespell;
	delete firespell;
	delete lightningspell;
}
void Market::set_Items(){
	srand(time(NULL));
    unsigned int i,p;
	p = 0;
	int Name;
	int Damage;
	int Defence;
	int Level;
	int Hands;
	int Price;
/////////////////  F O R   P O T I O N S  ///////////////////////////////
	int healthPower;
	int magicPower;
	int Strength;
	int Agility;
	int Dexterity;
///////////////// F O R   S P E L L S  ///////////////////////////////////
	int MinDamage;
	int MaxDamage;
	int Reduction;
	int MagicCost;
//////////////////////////////////////////////////////////////////////////

	string * name;
	name = new string[30];

///////////////////////     W  E  A  P  O  N  S     //////////////////////////////////////////

        ifstream We("Weapon.txt");
        while (true){
                string buf;
                We >> i >> buf;
                if ( We.eof() ) { break; }
                        name[p] = buf;
                p++;
	}
	We.clear();

	Name = rand()%30;				//Choice Name of Weapon
	Damage = rand()%10+1;				//About Damage
	Hands = rand()%2 + 1;				//Choice Hand's Number
	Level = Damage/2;				//Level
	Price = Damage*5;				//Price of Weapon
	Damage = Damage*Hands;				//Weapon's Damage

	weapon = new Weapon(name[Name],Price,Level,Damage,Hands);
///////////////////////     A  R  M  O  R  S     //////////////////////////////////////////

	p = 0;

	ifstream Ar("Armor.txt");
        while (true){
                string buf;
                Ar >> i >> buf;
                if ( Ar.eof() ) { break; }
                        name[p] = buf;
                p++;
        }
        Ar.clear();

        Name = rand()%30;                               //Choice Name of Armor
        Defence = rand()%10 + 1;                        //Defence
        Price = Defence*2;                              //Price
        Level = Defence/2;                              //Level

        armor = new Armor(name[Name],Price,Level,Defence);


///////////////////////     P  O  T  I  O  N  S     //////////////////////////////////////////

	p = 0;

        ifstream Po("Potion.txt");
        while (true){
                string buf;
                Po >> i >> buf;
                if ( Po.eof() ) { break; }
                        name[p] = buf;
                p++;

        }
	Po.clear();

	Name = rand()%30;							//Name of Potion
	Strength = rand()%7;							//Strength of Potion
        Agility = rand()%7;							//Agility of Potion
        Dexterity = rand()%7;							//Dexterity of Potion
	healthPower = rand()%10+1;						//HealthPower of Potion
        magicPower = rand() %10+1;						//MagicPower of Potion
	Level = 1;								//Level of Potion
	Price = (Strength + Agility + Dexterity + healthPower + magicPower)/2;	//Price of Potion

	potion = new Potion(name[Name],Price,Level,healthPower,magicPower,Strength,Dexterity,Agility);
///////////////////////     	I  C  E      S  P  E  L  L  S     //////////////////////////////////////////

	p = 0;

        ifstream Ic("IceSpells.txt");
        while (true){
                string buf;
                Ic >> i >> buf;
                if ( Ic.eof() ) { break; }
                        name[p] = buf;
                p++;

        }
	Ic.clear();

	Name = rand()%13;
	MaxDamage = rand()%5+1;
	MinDamage = rand()%MaxDamage;
	Level = (MaxDamage + MinDamage)/2;
	Price = (MaxDamage + MinDamage)*4;
	MagicCost = (MaxDamage + MinDamage)*2;
	Reduction = rand()%5+1;

	icespell = new IceSpell(name[Name],Price,Level,MinDamage,MaxDamage,MagicCost,Reduction);

///////////////////////         F  I  R  E    S  P  E  L  L  S    ///////////////////////////////////////////

	p = 0;

        ifstream Fi("FireSpells.txt");
        while (true){
                string buf;
                Fi >> i >> buf;
                if ( Fi.eof() ) { break; }
                        name[p] = buf;
                p++;

        }
        Fi.clear();

        Name = rand()%13;
        MaxDamage = rand()%5+1;
        MinDamage = rand()%MaxDamage;
        Level = (MaxDamage + MinDamage)/2;
        Price = (MaxDamage + MinDamage)*4;
        MagicCost = (MaxDamage + MinDamage)*2;
        Reduction = rand()%5+1;

        firespell = new FireSpell(name[Name],Price,Level,MinDamage,MaxDamage,MagicCost,Reduction);


///////////////////////   L  I  G  H  T  N  I  N  G      S  P  E  L  L  S    /////////////////////////////////

	p = 0;

        ifstream Li("LightningSpells.txt");
        while (true){
                string buf;
                Li >> i >> buf;
                if ( Li.eof() ) { break; }
                        name[p] = buf;
                p++;
        }
	Li.clear();

	Name = rand()%13;
	MaxDamage = rand()%5+1;
        MinDamage = rand()%MaxDamage;
        Level = (MaxDamage + MinDamage)/2;
        Price = (MaxDamage + MinDamage)*4;
	MagicCost = (MaxDamage + MinDamage)*2;
        Reduction = rand()%5+1;

	lightningspell = new LightningSpell(name[Name],Price,Level,MinDamage,MaxDamage,MagicCost,Reduction);

}

void Market::get_Items(){
	unsigned int i=1;
	cout << i;
	this->get_Weapon();
	i++;
	cout << i;
	this->get_Armor();
	i++;
	cout << i;
	this->get_Potion();
	i++;
	cout << i;
	this->get_IceSpell();
	i++;
	cout << i;
	this->get_FireSpell();
	i++;
	cout << i;
	this->get_LightningSpell();
}

void Market::get_Potion(){
	cout << "	Potion\n"<< endl;
        cout << "Name              : " << potion->getName() << endl;
        cout << "MP Restore        : " << potion->getMpRestore() << endl;
        cout << "HP Restore        : " << potion->getLevelReq() << endl;
        cout << "Strength          : " << potion->getStrBuff() << endl;
        cout << "Dexterity         : " << potion->getDexBuff() << endl;
        cout << "Agility           : " << potion->getAgiBuff() << endl;
	cout << "Level             : " << potion->getLevelReq() << endl;
        cout << "Price             : " << potion->getPrice() << endl;
        cout << endl;
}

void Market::get_Armor(){
	cout << "	Armor\n"<< endl;
        cout << "Name              : " << armor->getName() << endl;
        cout << "Defence           : " << armor->getDefence() << endl;
        cout << "Level             : " << armor->getLevelReq() << endl;
        cout << "Price             : " << armor->getPrice() << endl;
        cout << endl;
}

void Market::get_Weapon(){
	cout << "	Weapon\n"<< endl;
        cout << "Name              : " << weapon->getName() << endl;
        cout << "Damage            : " << weapon->getDamage() << endl;
	cout << "Hands             : " << weapon->getHands() << endl;
        cout << "Level             : " << weapon->getLevelReq() << endl;
        cout << "Price             : " << weapon->getPrice() << endl;
        cout << endl;
}

void Market::get_IceSpell(){
	cout << "	IceSpell\n"<< endl;
	cout << "Name              : " << icespell->getName() << endl;
	cout << "MaxDamage         : " << icespell->getMaxDamage() << endl;
	cout << "MinDamage         : " << icespell->getMinDamage() << endl;
	cout << "Damage Reduction  : " << icespell->getDamageReduction() << endl;
	cout << "MP Cost           : " << icespell->getMpCost() << endl;
	cout << "Level             : " << icespell->getLevelReq() << endl;
        cout << "Price             : " << icespell->getPrice() << endl;
        cout << endl;
}

void Market::get_FireSpell(){
        cout << "	FireSpell\n"<< endl;
        cout << "Name              : " << firespell->getName() << endl;
        cout << "MaxDamage         : " << firespell->getMaxDamage() << endl;
        cout << "MinDamage         : " << firespell->getMinDamage() << endl;
        cout << "Defence Reduction : " << firespell->getDefenceReduction() << endl;
        cout << "MP Cost           : " << firespell->getMpCost() << endl;
        cout << "Level             : " << firespell->getLevelReq() << endl;
        cout << "Price             : " << firespell->getPrice() << endl;
        cout << endl;
}

void Market::get_LightningSpell(){
        cout << "	LightningSpell\n"<< endl;
        cout << "Name              : " << lightningspell->getName() << endl;
        cout << "MaxDamage         : " << lightningspell->getMaxDamage() << endl;
        cout << "MinDamage         : " << lightningspell->getMinDamage() << endl;
        cout << "Dodge Reduction   : " << lightningspell->getDodgeReduction() << endl;
        cout << "MP Cost           : " << lightningspell->getMpCost() << endl;
        cout << "Level             : " << lightningspell->getLevelReq() << endl;
        cout << "Price             : " << lightningspell->getPrice() << endl;
        cout << endl;
}


char Market::buy_Items(Party* party){
	unsigned int i;
	cout << "       M   A   R   K   E   T     " << endl << endl;
	cout << "  I N V E N T O R Y " << endl;
        cout << endl;
	this->get_Items();
	cout << endl;
	cout << endl << " Choose an item or press 'e' to exit from Market" << endl;
	char parametr;
	cout << "\n\nPress Key : ";
	cin >> parametr;
	while(parametr != 'e' && parametr != 'q'){
		switch(parametr){
			case '1':
				this->get_Weapon();
				if(party->inventory.totalMoney > weapon->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - weapon->getPrice();
					party->inventory.weapons.push_back(*weapon);
					cout << "\n\nYou Buy " << weapon->getName() << endl;
					for(i=0; i< party->amountOfCharacters; i++)
						party->character[i].setMoney((-1)/party->amountOfCharacters);}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case '2':
				this->get_Armor();
				if(party->inventory.totalMoney > armor->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - armor->getPrice();
					party->inventory.armors.push_back(*armor);
					cout << "\n\nYou Buy " << armor->getName() << endl;
					for(i=0; i< party->amountOfCharacters; i++)
                                                party->character[i].setMoney((-1)/party->amountOfCharacters);}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case '3':
				this->get_Potion();
				if(party->inventory.totalMoney > potion->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - potion->getPrice();
					party->inventory.potions.push_back(*potion);
					cout << "\n\nYou Buy " << potion->getName() << endl;}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case '4':
				this->get_IceSpell();
				if(party->inventory.totalMoney > icespell->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - icespell->getPrice();
					party->inventory.iceSpells.push_back(*icespell);
					cout << "\n\nYou Buy " << icespell->getName() << endl;
					for(i=0; i< party->amountOfCharacters; i++)
                                                party->character[i].setMoney((-1)/party->amountOfCharacters);}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case '5':
				this->get_FireSpell();
				if(party->inventory.totalMoney > firespell->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - firespell->getPrice();
					party->inventory.fireSpells.push_back(*firespell);
					cout << "\n\nYou Buy " << firespell->getName() << endl;
					for(i=0; i< party->amountOfCharacters; i++)
                                                party->character[i].setMoney((-1)/party->amountOfCharacters);}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case '6':
				this->get_LightningSpell();
				if(party->inventory.totalMoney > lightningspell->getPrice()){
					party->inventory.totalMoney = party->inventory.totalMoney - lightningspell->getPrice();
					party->inventory.lightningSpells.push_back(*lightningspell);
					cout << "\n\nYou Buy a " << lightningspell->getName() << endl;
					for(i=0; i< party->amountOfCharacters; i++)
                                                party->character[i].setMoney((-1)/party->amountOfCharacters);}
				else
					cout << "\n\nYou don't have enouph gold ";
				break;
			case 'e':
				break;
			case 'i':
				party->checkInventory();
				break;
			case 'c':
				party->checkStats();
				break;
			case 'q':
				parametr = 'q';
				break;
			case 's':
				this->sell_Items(party);
				break;
			default:
                                cout << "\nWrong Key" << endl;
                                break;
		}
		cout << "\n\nPress Key : ";
		cin >> parametr;
	}
	return parametr;
}

void Market::sell_Items(Party* party){
	char method,thing;
	int k;
	Inventory inventory;
	inventory = party->inventory;
	cout << "\n\n\n  P R E S S  C A T E G O R Y  O F  T H I N G S  \n\n\n"<< endl;
	cout << "1	Weapon" << endl;
	cout << "2	Armor" << endl;
	cout << "3	Potion" << endl;
	cout << "4	IceSpell"<<endl;
	cout << "5	FireSpell"<< endl;
	cout << "6	LightningSpell" << endl;
	cout << "\n\nPress Key : ";
	cin >> method;
	while(method != 'e'){
		switch(method){
			case '1':
				cout << "  W  E  A  P  O  N  s\n\n";
				if (inventory.weapons.size()!=0){
					thing = 'k';
					while(thing!='e'){
						for(unsigned int i=0; i<inventory.weapons.size(); i++){
							cout << i+1 <<  inventory.weapons[i].getName() << ": " << inventory.weapons[i].getHands() << "-handed | +" << inventory.weapons[i].getDamage() << " damage | Lvl. Requirement: " << inventory.weapons[i].getLevelReq() << "  costs : " << inventory.weapons[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose a weapon to sell  : ";
						cin >> thing;
						k = thing - 48;
						inventory.weapons.erase (inventory.weapons.begin() + k);
						if (inventory.weapons.size()==0){
							cout << "Out of Weapons" << endl;
							break;}
					}
				}
				else
					cout <<"NO WEAPONS"<<endl;
				break;
			case '2':
				cout << "  A  R  M  O  R  S\n\n";
				if (inventory.armors.size()!=0){
					thing = 'k';
					while(thing!='e'){
						for(unsigned int i=0; i<inventory.armors.size(); i++){
							cout << i+1 << inventory.armors[i].getName() << ": +" << inventory.armors[i].getDefence() << " defence | Lvl. Requirement: " << inventory.armors[i].getLevelReq() <<  "  costs : " << inventory.armors[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose an armor to sell  : ";
                                                cin >> thing;
                                                k = thing - 48;
                                                inventory.armors.erase (inventory.armors.begin() + k);
                                                if (inventory.armors.size()==0){
                                                        cout << "Out of Armors" << endl;
                                                        break;}
					}
				}
				else
					cout<<"NO ARMORS"<<endl;
				break;
			case '3':
				cout << "  P  O  T  I  O  N  S\n\n";
				if (inventory.potions.size()!=0){
					thing = 'k';
                                        while(thing!='e'){
						for(unsigned int i=0; i<inventory.potions.size(); i++){
							cout <<  i+1 << inventory.potions[i].getName()<<": +"<<inventory.potions[i].getStrBuff()<<" Str, +"<<inventory.potions[i].getDexBuff()<<" Dex, +"<< inventory.potions[i].getAgiBuff()<< " Agi, " << inventory.potions[i].getHpRestore()<<" Hp restore, "<<inventory.potions[i].getMpRestore()<<" Mp restore" << "  costs : " << inventory.potions[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose a potion to sell  : ";
                                                cin >> thing;
                                                k = thing - 48;
                                                inventory.potions.erase (inventory.potions.begin() + k);
                                                if (inventory.potions.size()==0){
                                                        cout << "Out of Potions" << endl;
                                                        break;}
					}
				}
				else
					cout<<"NO POTIONS"<<endl;
				break;
			case '4':
				cout << "  I  C  E     S  P  E  L  L  S\n\n";
				if (inventory.iceSpells.size()!=0){
					thing = 'k';
                                        while(thing!='e'){
						for(unsigned int i=0; i<inventory.iceSpells.size(); i++){
							cout <<  i+1 << inventory.iceSpells[i].getName()<<": "<<inventory.iceSpells[i].getMinDamage()<<"-"<<inventory.iceSpells[i].getMaxDamage()<<" damage | "<<inventory.iceSpells[i].getMpCost()<<" MP cost, -"<<inventory.iceSpells[i].getDamageReduction()<<" enemy damage" << "  costs : " << inventory.iceSpells[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose a iceSpell to sell  : ";
                                                cin >> thing;
                                                k = thing - 48;
                                                inventory.iceSpells.erase (inventory.iceSpells.begin() + k);
                                                if (inventory.iceSpells.size()==0){
                                                        cout << "Out of IceSpells" << endl;
                                                        break;}
					}
				}
				else
					cout<<"NO ICESPELLS"<<endl;
				break;
			case '5':
				cout << "  F  I  R  E     S  P  E  L  L  S\n\n";
				if (inventory.fireSpells.size()!=0){
					thing = 'k';
                                        while(thing!='e'){
						for(unsigned int i=0; i<inventory.fireSpells.size(); i++){
							cout <<  i+1 << inventory.fireSpells[i].getName()<<": "<<inventory.fireSpells[i].getMinDamage()<<"-"<<inventory.fireSpells[i].getMaxDamage()<<" damage | "<<inventory.fireSpells[i].getMpCost()<<" MP cost, -"<<inventory.fireSpells[i].getDefenceReduction()<<" enemy defence\n" << "  costs : " << inventory.fireSpells[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose a fireSpell to sell  : ";
                                                cin >> thing;
                                                k = thing - 48;
                                                inventory.fireSpells.erase (inventory.fireSpells.begin() + k);
                                                if (inventory.fireSpells.size()==0){
                                                        cout << "Out of FireSpells" << endl;
                                                        break;}

					}
				}
				else
					cout<<"NO FIRESPELLS"<<endl;
				break;
			case '6':
				cout << "  L  I  G  H  T  N  I  N  G     S  P  E  L  L  S\n\n";
				if (inventory.lightningSpells.size()!=0){
					thing = 'k';
                                        while(thing!='e'){
						for(unsigned int i=0; i<inventory.lightningSpells.size(); i++){
							cout <<  i+1 << inventory.lightningSpells[i].getName()<<": "<<inventory.lightningSpells[i].getMinDamage()<<"-"<<inventory.lightningSpells[i].getMaxDamage()<<" damage | "<<inventory.lightningSpells[i].getMpCost()<<" MP cost, -"<<inventory.lightningSpells[i].getDodgeReduction()<<"% enemy dodge" << "  costs : " << inventory.lightningSpells[i].getPrice()/2 << endl;
						}
						cout <<"\n\nChoose a lightningSpell to sell  : ";
                                                cin >> thing;
                                                k = thing - 48;
                                                inventory.lightningSpells.erase (inventory.lightningSpells.begin() + k);
                                                if (inventory.lightningSpells.size()==0){
                                                        cout << "Out of FireSpells" << endl;
                                                        break;}

					}
				}
				else
					cout<<"NO LIGHTNINGSPELLS" << endl;
				break;
		}
		cout << "1      Weapon" << endl;
	        cout << "2      Armor" << endl;
	        cout << "3      Potion" << endl;
	        cout << "4      IceSpell"<<endl;
	        cout << "5      FireSpell"<< endl;
	        cout << "6      LightningSpell" << endl;
		cout << "\n\nPress Key : ";
        	cin >> method;
	}
}

