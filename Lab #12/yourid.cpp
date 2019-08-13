#include <iostream>
#include <vector>

using namespace std;

int vertices, edges, u, x, y, w, i, j;

int Min_Key(int key[], bool MST[]){

	int minValue = 2147483647;
	int pointer = 0;

	int index = 0;

	while(index < vertices){
		if(!MST[index] && key[index] < minValue){
			minValue = key[index];
			pointer = index;
		}
		index++;
	}

	return pointer;
}

void Min_Span_Tree(){

	vector<vector<int>> graph(vertices, vector<int> (vertices, 0));

	i = 0;

	while(i < vertices){
		j = 0;
		while(j < vertices){
			graph[i][j] = 0;
			j++;
		}
		i++;
	}

	i = 0;
	while(i < edges){

		cin >> x >> y >> w;

		graph[x][y] = graph[y][x] = w;

		i++;
	}

	int weight[vertices], key[vertices];
	bool MST[vertices];

	i = 0;
	while(i < vertices){

		key[i] = 2147483647;
		MST[i] = false;

		i++;
	}

	i = 0;
	while(i < vertices - 1){

		u = Min_Key(key, MST);

		MST[u] = true;

		j = 0;

		while(j < vertices){

			if(graph[u][j] && !MST[j] && graph[u][j] < key[j]){

				weight[j] = u;
				key[j] = graph[u][j];

			}
			j++;
		}
		i++;
	}

	i = 1;
	while(i < vertices){
		cout << weight[i] << endl;
		i++;
	}

}

int main(){
	cin >> vertices >> edges;
	Min_Span_Tree();
	return 0;
}
