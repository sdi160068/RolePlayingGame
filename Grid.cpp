#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Function.h"
#include "Grid.h"
#include <iostream>

using namespace std;

Grid::Grid(){
	cout << "Map created" << endl;
	Width = 31;
        Length = 61;
	this->set_map();
}


Grid::~Grid(){
	delete[] map;}
void Grid::set_map(){
	int i,j;
	map =new int*[Width];
	for(i=0; i<Width; i++)
		map[i] = new int[Length];

	ifstream in("data.txt");
	int p = 0;
	while (true || p == 31){
		int i;
		char buf[Length];
		in >> i >> buf;
		if ( in.eof() ) { /*cerr << "EOF" << endl;*/ break; }
		for(j=0; j<Length; j++){
			map[p][j] = buf[j] - 48;
		}
		p++;
	}
	in.clear();


	map[Width/2][Length/2] = 0;
}

void Grid::print(int& la,int& lo){
	int i,j;
	static int La,Lo;
	if(map[la][lo] > 0){
		cout << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "      E r r o r , y o u  c a n ' t  g o  t h e r e     " << endl;
		cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
		la = La;		// If La of Hero is over of map , Hero stay in the last La
		lo = Lo;		// If Lo of Hero is over of map , Hero stay in the last Lo
	}
	this->set_Monster(la,lo);
	cout << endl;

///////////   P R I N T   M A P //////////////////////////////////////////////////////////////

	for(i=0; i<Width; i++){
                for(j=0; j<Length; j++){
                        if(i == la && j == lo){
                                cout << 'o';
			}
                        else{
				switch(map[i][j]){
					case 1:
						cout << 'X';break;
					case 2:
						cout << 'T';break;
					default:
						cout << ' ';break;
				}
			}

                }
	cout << endl;
	}
///////////////////////////////////////////////////////////////////////////////////////////////

	La =la;
	Lo =lo;
}

int Grid::get_Length(){return Length;}
int Grid::get_Width(){return Width;}
int Grid::get_Point(int La,int Lo){return map[La][Lo];}

void Grid::set_Monster(int La,int Lo){
	srand (time(NULL));
	int v;
	v = rand()%100;
        if(v <= 10){
                map[La][Lo] = 3;
        }

}

void Grid::print_map(int la,int lo){
	int i,j;
///////////   P R I N T   M A P //////////////////////////////////////////////////////////////

	for(i=0; i<Width; i++){
                for(j=0; j<Length; j++){
                        if(i == la && j == lo){
                                cout << 'o';
			}
                        else{
				switch(map[i][j]){
					case 1:
						cout << 'X';break;
					case 2:
						cout << 'T';break;
					default:
						cout << ' ';break;
				}
			}

                }
	cout << endl;
	}
///////////////////////////////////////////////////////////////////////////////////////////////

}
