CC=g++
CFLAGS=-Wall
OBJECTS=Main.o Grid.o Function.o Party.o Items.o Entities.o Spells.o Market.o

prog: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -g -o prog

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c Main.cpp -o Main.o

Grid.o: Grid.cpp
	$(CC) $(CFLAGS) -c Grid.cpp -o Grid.o

Function.o: Function.cpp
	$(CC) $(CFLAGS) -c Function.cpp -o Function.o

Party.o: Party.cpp
	$(CC) $(CFLAGS) -c Party.cpp -o Party.o

Items.o: Items.cpp
	$(CC) $(CFLAGS) -c Items.cpp -o Items.o

Entities.o: Entities.cpp
	$(CC) $(CFLAGS) -c Entities.cpp -o Entities.o

Spells.o: Spells.cpp
	$(CC) $(CFLAGS) -c Spells.cpp -o Spells.o

Market.o: Market.cpp
	$(CC) $(CFLAGS) -c Market.cpp -o Market.o

.PHONY: clean

clean:
	rm -f prog *.o

