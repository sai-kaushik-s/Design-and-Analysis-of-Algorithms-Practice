all: graph

graph: main.o DFS1.o DFS2.o DFS3.o BFS1.o BFS2.o BFS3.o Spath.o Lpath.o Max_MST.o Bipartite.o Test_ArtiPoint.o Bridges.o Prims.o KruskalMST.o myalgo_MST.o
	g++ main.o DFS1.o DFS2.o DFS3.o BFS1.o BFS2.o BFS3.o Spath.o Lpath.o Max_MST.o Bipartite.o Test_ArtiPoint.o Bridges.o Prims.o KruskalMST.o myalgo_MST.o -o graph
	
main.o: main.cpp
	g++ -c main.cpp

DFS1.o: DFS1.cpp
	g++ -c DFS1.cpp
	
DFS2.o: DFS2.cpp
	g++ -c DFS2.cpp

DFS3.o: DFS3.cpp
	g++ -c DFS3.cpp
	
BFS1.o: BFS1.cpp
	g++ -c BFS1.cpp
	
BFS2.o: BFS2.cpp
	g++ -c BFS2.cpp

BFS3.o: BFS3.cpp
	g++ -c BFS3.cpp

Spath.o: Spath.cpp
	g++ -c Spath.cpp

Lpath.o: Lpath.cpp
	g++ -c Lpath.cpp	

Max_MST.o: Max_MST.cpp
	g++ -c Max_MST.cpp

Bipartite.o: Bipartite.cpp
	g++ -c Bipartite.cpp

Test_ArtiPoint.o: Test_ArtiPoint.cpp
	g++ -c Test_ArtiPoint.cpp

Bridges.o: Bridges.cpp
	g++ -c Bridges.cpp

Prims.o: Prims.cpp
	g++ -c Prims.cpp

KruskalMST.o: KruskalMST.cpp
	g++ -c KruskalMST.cpp

myalgo_MST.o: myalgo_MST.cpp
	g++ -c myalgo_MST.cpp
	
clean:
	rm -rf *o sorting2
