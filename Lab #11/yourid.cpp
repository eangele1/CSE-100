#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> component, order;
int vertices, edges, temp1, temp2, i, j, k, value, vecSwitch;

void DFS(vector <int> graph[], int n, bool visit[], int vecSwitch) {
	visit[n] = true;
	i = 0;
	while(i < graph[n].size()) {
		if (!visit[graph[n][i]]) {
			DFS(graph, graph[n][i], visit, vecSwitch);
		}
		switch (vecSwitch) {
			case 0:
			order.push_back(n);
			break;

			default:
			component.push_back(n);
			break;
		}
		i++;
	}
}

int main() {

	cin >> vertices >> edges;

	vector <int> arr;
	vector <int> adj_verts[500];
	vector <int> rev[500];

	vector <vector <int>> Strong_Con_Comp;

	bool visit[500] = {false};

	i = 0;
	while(i < vertices) {
		arr.push_back(i);
		i++;
	}

	i = 0;
	do {
		cin >> temp1 >> temp2;
		adj_verts[temp1].push_back(temp2);
		i++;
	} while (i < edges);

	i = 0;
	vecSwitch = 0;
	while(i < vertices) {
		if (!visit[i]) {
			DFS(adj_verts, i, visit, vecSwitch);
		}
		i++;
	}

	i = 0;
	while(i < vertices) {
		j = 0;
		while(j < adj_verts[i].size()) {
			rev[adj_verts[i][j]].push_back(i);
			j++;
		}
		i++;
	}

	i = 0;
	while(i < vertices){
		visit[i] = false;
		i++;
	}

	std::vector<int> r(order.rbegin(), order.rend());
	order.swap(r);

	i = 0;
	vecSwitch = 1;
	while(i < order.size()) {
		if (!visit[order[i]]) {
			component.clear();
			DFS(rev, order[i], visit, vecSwitch);
			Strong_Con_Comp.push_back(component);
		}
		i++;
	}

	i = 0;
	while(i < Strong_Con_Comp.size()) {
		j = 0;
		while(j < Strong_Con_Comp[i].size()) {
			value = Strong_Con_Comp[i][j];
			k = 0;
			while(k < vertices) {
				if (arr[k] == value) {
					arr[k] = *min_element(Strong_Con_Comp[i].begin(), Strong_Con_Comp[i].end());
				}
				k++;
			}
			j++;
		}
		i++;
	}

	i = 0;
	while(i < vertices) {
		cout << arr[i] << endl;
		i++;
	}

	return 0;
}
