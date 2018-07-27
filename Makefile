#MAKE FILE
all: create_folders
	g++ -Wall -fexceptions -O2 -Isrc -c main.cpp -o obj/main.o
	g++ -Wall -fexceptions -O2 -Isrc -c src/dataReader.cpp -o obj/dataReader.o
	g++ -Wall -fexceptions -O2 -Isrc -c src/edge.cpp -o obj/edge.o
	g++ -Wall -fexceptions -O2 -Isrc -c src/graph.cpp -o obj/graph.o
	g++ -Wall -fexceptions -O2 -Isrc -c src/node.cpp -o obj/node.o
	g++ -Wall -fexceptions -O2 -Isrc -c src/timestamp.cpp -o obj/timestamp.o
	
	g++  -o dijkstra-with-restricted-timetable obj/main.o obj/dataReader.o obj/edge.o obj/graph.o obj/node.o obj/timestamp.o  -s  
	
create_folders:
	mkdir obj/	

clean:
	rm -rf obj/
