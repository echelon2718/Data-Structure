#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Graph {
	int numVertices;
	vector< vector<int> > adjMatrix;
	
	public:
		Graph(int vertices);
		void addEdge(int src, int dest);
		void BFS(int startVertex, int endVertex);
		void printGraph();
};

Graph::Graph(int vertices) {
	numVertices = vertices;
	adjMatrix = vector < vector<int> > (numVertices, vector <int> (numVertices, 0));
}

void Graph::addEdge(int src, int dest) {
	adjMatrix[src][dest] = 1;
}

void Graph::BFS(int startVertex, int endVertex) {
	vector<bool> visited(adjMatrix.size(), false);
    vector<int> q;
    q.push_back(startVertex);

    visited[startVertex] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];
        cout << "[Vertex " << vis << "]" << endl;
        if (vis == endVertex) break;
        q.erase(q.begin());
        
        for (int i = 0; i < adjMatrix[vis].size(); i++) {
            if (adjMatrix[vis][i] == 1 && (!visited[i])) {
                q.push_back(i);
                visited[i] = true;
            }
        }
    }
    cout << "END" << endl;
}

void Graph::printGraph() {
	for (int i = 0; i < numVertices; i++) {
		if (i < 10) cout << i << "  : ";
		else cout << i << " : ";
		for (int j = 0; j < numVertices; j++) {
			if (adjMatrix[i][j] == 0) cout << ". ";
			else cout << adjMatrix[i][j] << " ";
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
    cout << "ADJACENCY MATRIX REPRESENTATION: " << endl;
    g.printGraph();
    
    int dest;
    cout << "Masukkan tempat tujuan: ";
    cin >> dest;
    cout << "\nGRAPH BFS ALGORITHM FROM 0 TO " << dest << endl;
    g.BFS(0, dest);
}
