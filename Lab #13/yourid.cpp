#include <iostream>

using namespace std;

int numberVertex, numberEdges, tmpVertex, tmpEdge, weight;

struct Edge {
	int u, v, w;
};

struct Graph {
	int V, E;
	struct Edge *edge;
};

void display(int arr[], int size, bool negative) {
	if(negative){
		cout << "TRUE" << endl;
		int i = 0;
		while(i < size){
			switch (arr[i]) {
				case 2147483647:
				cout << "INFINITY" << endl;
				break;
				
				default:
				cout << arr[i] << endl;
				break;
			}
			i++;
		}
	}
}

void BellmanFord(struct Graph *graph, int source) {
	
	bool negative = true;
	
	int totalVertex = graph->V;
	int totalEdges = graph->E;
	int distance[totalVertex];

	int u, v, w;
	
	int i = 0;
	while(i < totalVertex) {
		distance[i] = 2147483647;
		
		i++;
	}
	
	distance[source] = 0;

	i = 1;
	while(i <= totalVertex - 1) {
		int j = 0;
		while(j < totalEdges) {
			u = graph->edge[j].u;
			v = graph->edge[j].v;
			w = graph->edge[j].w;
			if(distance[u] != 2147483647 && distance[v] > distance[u] + w) {
				distance[v] = distance[u] + w;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while(i < totalEdges) {
		u = graph->edge[i].u;
		v = graph->edge[i].v;
		w = graph->edge[i].w;
		if(distance[u] != 2147483647 && distance[v] > distance[u] + w) {
			cout << "FALSE" << endl;
			negative = false;
			return;
		}
		i++;
	}
	
	display(distance, totalVertex, negative);
}

int main() {
	
	cin >> numberVertex >> numberEdges;
	
	struct Graph* graph = new Graph();
	
	graph->V = numberVertex;
	graph->E = numberEdges;
	graph->edge = new Edge[numberEdges];
	
	int x = 0;
	
	while(x < numberEdges){
		
		cin >> tmpVertex >> tmpEdge >> weight;
		
		graph->edge[x].u = tmpVertex;
		graph->edge[x].v = tmpEdge;
		graph->edge[x].w = weight;
		
		x++;
	}
	
	BellmanFord(graph, 0);
	
	return 0;
}
