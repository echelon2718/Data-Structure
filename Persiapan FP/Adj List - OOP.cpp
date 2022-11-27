#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;

class Graph {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

    public:
        Graph(int vertices);
	    void addEdge(int src, int dest);
	    void BFS(int startVertex, int endVertex);
	    void printGraph();
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int> [vertices];
}

void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

void Graph::BFS(int startVertex, int endVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);
    
    list<int> ::iterator i;

    while (!queue.empty()) {
        int currVertex = queue.front();
        cout << "[Vertex " << currVertex << "]\n";
        if (currVertex == endVertex) break;
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
    cout << "END" << endl;
}

void Graph::printGraph() {
	list<int> ::iterator i;
	for (int it = 0; it < numVertices; it++) {
		cout << "Vertex [" << it << "]"; 
		for (i = adjLists[it].begin(); i != adjLists[it].end(); ++i) {
			cout << " -> [" << *i << "]";
		}
		cout << endl;
	}
}

int main() {
    Graph g(22);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(1, 6);

    g.addEdge(2, 4);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(2, 9);

    g.addEdge(3, 10);
    g.addEdge(3, 11);

    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(4, 12);

    g.addEdge(5, 1);
    g.addEdge(5, 4);
    g.addEdge(5, 6);

    g.addEdge(6, 1);
    g.addEdge(6, 5);

    g.addEdge(7, 2);

    g.addEdge(8, 13);
    g.addEdge(8, 14);
    g.addEdge(8, 15);
    g.addEdge(8, 16);

    g.addEdge(9, 2);
    g.addEdge(9, 17);

    g.addEdge(11, 19);

    g.addEdge(12, 18);

    g.addEdge(14, 15);

    g.addEdge(15, 16);

    g.addEdge(16, 17);
    g.addEdge(16, 19);
	
    g.addEdge(17, 12);
    g.addEdge(17, 14);

    g.addEdge(18, 19);
    g.addEdge(18, 20);
    
    g.addEdge(20, 18);
    g.addEdge(20, 21);
    cout << "ADJACENCY LIST REPRESENTATION:" << endl;
    g.printGraph();
    
    int dest;
    cout << "Masukkan tempat tujuan: ";
    cin >> dest;
    cout << "\nGRAPH BFS ALGORITHM FROM 0 TO " << dest << ":" << endl;
    g.BFS(0, dest);

    return 0;
}
