#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

class Vertex {
    protected:
        list<int> adj;
    
    public:
        void addEdge(int u, int v) {
            if(adj.empty()) adj.push_back(u);
            adj.push_back(v);
        }

        void showList() {
            list<int>::iterator it;
            for(it = adj.begin(); it != adj.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
};

class Graph {
    protected:
        int len;
        Vertex vertex[100];
        

    public:
        Graph(int length) {
            len = length;
        }

        AddEdgetoVertex(int u, int v){
            vertex[u].addEdge(u,v);
            vertex[v].addEdge(v,u);
        }

        showAllVertex() {
            for (int i = 0; i < len; i++) {
                vertex[i].showList();
            }
            
        }
};


int main() {
    Graph graph(5);

    graph.AddEdgetoVertex( 0, 1);
    graph.AddEdgetoVertex( 0, 4);
    graph.AddEdgetoVertex( 1, 2);
    graph.AddEdgetoVertex( 1, 3);
    graph.AddEdgetoVertex( 1, 4);
    graph.AddEdgetoVertex( 2, 3);
    graph.AddEdgetoVertex( 3, 4);

    graph.showAllVertex();
}
