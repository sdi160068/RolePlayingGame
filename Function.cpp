#include <ctime>
#include <cstdlib>
#include "Function.h"
#include "Grid.h"
#include <iostream>
#include "Market.h"
#include "Entities.h"

using namespace std;

void Move(){
	int potionChoice;
	Party player;
	Market market;
	Grid G;
	int W,L;
	unsigned int i;
	player.heroCreation();
	W = (G.get_Width() / 2);
	L = (G.get_Length() / 2);
	char method;
	cout << endl;
	G.print(W,L);
	cout << endl << "Move with 'w','s','a','d'  OR   press 'q' to quit" << endl << endl;
//	while(method != 'q'){
	while(1){
		cout << "PRESS KEY :  ";
		cin >> method;
		cout << endl << endl << endl << endl ;
		switch(method){
			case 'w':
				--W;
				G.print(W,L);
				if((G.get_Point(W,L) == 3)){
                    method = player.battleStart();
                    G.print(W,L);}
				break;
			case 's':
				++W;
				G.print(W,L);
				if((G.get_Point(W,L) == 3)){
                    method = player.battleStart();
                    G.print(W,L);}
				break;
			case 'a':
				--L;
				G.print(W,L);
				if((G.get_Point(W,L) == 3)){
                    method = player.battleStart();
                    G.print(W,L);}
				break;
			case 'd':
				++L;
				G.print(W,L);
				if((G.get_Point(W,L) == 3)){
                    method = player.battleStart();
					G.print(W,L);}
				break;
			case 'q':
				break;
			case 'z':
				break;
			case 'c':
				player.checkStats();break;
			case 'i':
				player.checkInventory();break;
			case 'p':
				G.print(W,L);break;
			case 'u':						//use potion
				for(i=0; i < player.amountOfCharacters; i++){
					for(unsigned int l=0; l<player.inventory.potions.size(); l++){
						cout<< l+1 <<". "<<player.inventory.potions[l].getName()<<": +"<<player.inventory.potions[l].getStrBuff()<<" Str, +"<<player.inventory.potions[l].getDexBuff()<<" Dex, +"<< player.inventory.potions[l].getAgiBuff()<<" Agi, " << player.inventory.potions[l].getHpRestore()<<" Hp restore, "<<player.inventory.potions[l].getMpRestore()<<" Mp restore\n";
					}
					if (player.inventory.potions.size()==0){
						cout<< "There are no potions in the party's inventory to use\n";
					}
					else{
						cout<<"Which potion will they use?"<<endl;
						cin >> potionChoice;
						player.character[i].usePotion(player.inventory.potions[potionChoice-1]);
						player.inventory.potions.erase(player.inventory.potions.begin()+potionChoice-1);
						}
				}
			case 'e':
				for(i=0; i < player.amountOfCharacters; i++){
					cout << "Change " << player.character[i].getName() << "'s Equipement" << endl; 
					player.character[i].changeEquipment(player.inventory, player.character[i].equipment);}
				break;
			case 'm':
				if((G.get_Point(W+1,L) == 2) || (G.get_Point(W-1,L) == 2) || (G.get_Point(W,L-1) == 2) || (G.get_Point(W,L+1) == 2)){
					method = market.buy_Items(&player);
					G.print(W,L);
					market.~Market();}
			else {
	            cout << "||||||||||||||||||||||||||||||||||||||||||||||" << endl;
        	    cout << "               W R O N G   K E Y              " << endl;
        	    cout << "||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				}break;
			default:
				cout << "||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				cout << "               W R O N G   K E Y              " << endl;
				cout << "||||||||||||||||||||||||||||||||||||||||||||||" << endl;
				break;
	}
	if((G.get_Point(W+1,L) == 2) || (G.get_Point(W-1,L) == 2) || (G.get_Point(W,L-1) == 2) || (G.get_Point(W,L+1) == 2))
		cout << endl << "  P R E S S  'm'  F O R  M A R K E T    " << endl << endl;
        else
		cout << endl << endl << endl;
	}
	cout << "  Y O U   E X I T  F R O M   T H E  G A M E  \n\n" << endl;
}
