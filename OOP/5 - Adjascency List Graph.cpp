#include <iostream>
#include <list>
using namespace std;

class Graph {
	int V;
	list<int>* adjList;
	bool* visited;
	
	public:
		Graph(int initVertices);
		void AddEdge(int src, int dest);
		void BFS(int startVertex);
};

Graph::Graph(int initVertices) {
	V = initVertices;
	adjList = new list<int>[initVertices];
}

void Graph::AddEdge(int src, int dest) {
	adjList[src].push_back(dest);
	adjList[dest].push_back(src);
}

void Graph::BFS(int startVertex) {
	visited = new bool[V];
	for (int it = 0; it < V; it++) {
		visited[it] = false;
	}
	
	list<int> queue;
	
	visited[startVertex] = true;
	queue.push_back(startVertex);
	
	list<int>::iterator i;
	
	while (!queue.empty()) {
		int currV = queue.front();
		cout << "(V" << currV << ")" << endl;
		queue.pop_front();
		
		for (i = adjList[currV].begin(); i != adjList[currV].end(); i++) {
			int adjVertex = *i;
			if (!visited[adjVertex]) {
				visited[adjVertex] = true;
				queue.push_back(adjVertex);
			}
		}
	}
}

int main() {
	Graph g(5);
	g.AddEdge(4, 2);
	g.AddEdge(4, 3);
	g.AddEdge(2, 1);
	g.AddEdge(2, 3);
	g.AddEdge(1, 3);
	g.AddEdge(0, 1);
	g.BFS(4);
}
