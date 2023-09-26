#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 100;
vector<int> adj[1001];

bool visited[1001];
struct GRAPH {
	int vertex;
	int arr[MAX][MAX];
};

void readFileToGraph(string fn, GRAPH& g);

void dfs(int v, vector<int>& component);

void isConnectedGraph(GRAPH g);
int main() {
	
	GRAPH g;
	readFileToGraph("dothi.txt", g);

	isConnectedGraph(g);
	return 0;
}

void readFileToGraph(string fn, GRAPH& g) {
	ifstream file;
	file.open(fn);

	if (file.is_open()) {
		file >> g.vertex;
		for (int i = 0; i < g.vertex; i++) {
			for (int j = 0; j < g.vertex; j++) {
				file >> g.arr[i][j];
			}
		}
	}
	else cout << "Can't open file : " << fn;
}
void dfs(int v, vector<int>& component) {
	visited[v] = true;
	
	
	
	component.push_back(v);
	for (int x : adj[v]) {
		if (!visited[x]) {
			dfs(x, component);
		}
	}
}


void isConnectedGraph(GRAPH g) {
	int indexConnected = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < g.vertex; i++) {
		for (int j = 0; j < g.vertex; j++) {
			if (g.arr[i][j] != 0) {
				
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<vector<int>> connectedComponents; 

	for (int i = 0; i < g.vertex; i++) {
		if (!visited[i]) {
			++indexConnected;
			vector<int> component; 
			dfs(i, component);
			connectedComponents.push_back(component);
		}
	}

	if (indexConnected != 1) {
		cout << "KHONGLIENTHONG" << endl;
		cout << indexConnected << endl;
		for (int i = 0; i < connectedComponents.size(); i++) {
			
			for (int j = 0; j < connectedComponents[i].size(); j++) {
				cout << connectedComponents[i][j] << " ";
			}
			cout << endl;
		}
	}
	else cout << "LIENTHONG";
}