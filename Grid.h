#ifndef GRID_H_
#define GRID_H_

class Grid{
	public:
		Grid();					// Constructor of Grid
		~Grid();				// Destructor of Grid
		void  print(int&,int&);			// Print the map,Point of Hero,Shops etc
		void  print_map(int,int);		// Just print the map without move
		void set_map();				// set map
		void set_Monster(int,int);			//Set point of monster in map
		int get_Length();
		int get_Width();
		int get_Point(int, int);		// Hero's Point
	private:
		int Length,Width;			//Map's Length and Width
		int** map;				//The map
};

#endif
