#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 100;
struct GRAPH {
	int vertex;
	int arr[MAX][MAX];
};

void readFileToGraph(string fn, GRAPH& g);
void printGraph( GRAPH g);
void printLevelVertexGraph(GRAPH g);
bool checkGraph(GRAPH g);
int countEdgeOfGraph(GRAPH g);
bool isUndirectedGraph(GRAPH g);
void infoVertexOfGraph(GRAPH g);
void coutVectorInfoVertex(vector<int> v);
int main() {
	
	GRAPH g;
	readFileToGraph("dothi.txt", g);
	printGraph(g);
	checkGraph(g) ? cout << "Day la do thi hop le" << endl : cout << "Day la do thi khong hop le" << endl;
	cout << "So canh cua do thi la: " << countEdgeOfGraph(g) << endl;
	printLevelVertexGraph(g);
	isUndirectedGraph(g);
	infoVertexOfGraph(g);
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
void printGraph(GRAPH g) {
	cout << "So dinh cua do thi la: " << g.vertex << endl;
	for (int i = 0; i < g.vertex; i++) {
		for (int j = 0; j < g.vertex; j++) {
			cout << g.arr[i][j] << " ";
		}
		cout << endl;
	}
}
void printLevelVertexGraph(GRAPH g) {
	for (int i = 0; i < g.vertex; i++) {
		int vertex = 0;
		for (int j = 0; j < g.vertex; j++) {
			vertex += g.arr[i][j];
		}
		wcout << "Bac cua dinh "<<i+1<<" là: "<<vertex<<endl;
		vertex = 0;
	}
}

bool checkGraph(GRAPH g) {

	for (int i = 0; i < g.vertex; i++) {
		if (g.arr[i][i] != 0)return false;
	}

	return true;
}
int countEdgeOfGraph(GRAPH g) {
	int edge = 0;
	for (int i = 0; i < g.vertex; i++) {
		for (int j = 0; j < g.vertex; j++) {
			edge += g.arr[i][j];
		}
	}

	return edge / 2;
}

bool isUndirectedGraph(GRAPH g) {
	for (int i = 0; i < g.vertex; i++) {
		for (int j = 0; j < g.vertex; j++) {
			if (g.arr[i][j] != g.arr[j][i])return false;
		}
	}

	return true;
}

void infoVertexOfGraph(GRAPH g) {
	
	int maxVertex = 0;
	int minVertex = 0;
	vector<int> evenVertex, oddVertex, isolatedVertex, hangVertex;
	for (int i = 0; i < g.vertex; i++) {
		int vertex = 0;
		for (int j = 0; j < g.vertex; j++) {
			vertex += g.arr[i][j];
		}
		if (maxVertex < vertex)maxVertex = i;
		if (i == 0)minVertex = vertex;
		if (minVertex > vertex)minVertex = i;

		if (vertex % 2 == 0)evenVertex.push_back(i+1);
		if(vertex %2 !=0)oddVertex.push_back(i +1);
		if (vertex == 1)isolatedVertex.push_back(i+1);
		if (vertex == 0)hangVertex.push_back(i+1);
		
	}

	cout << "Dinh co bac lon nhat la: " << maxVertex << endl;
	cout << "Dinh co bac nho nhat la: " << minVertex << endl;
	cout << "Cac dinh bac chan la: "; 
	coutVectorInfoVertex(evenVertex);
	cout << endl;
	cout << "Cac dinh bac le la: "; 
	coutVectorInfoVertex(oddVertex);
	cout << endl;
	cout << "Cac dinh co lap la: "; 
	coutVectorInfoVertex(isolatedVertex);
	cout << endl;
	cout << "Cac dinh treo la: "; 
	coutVectorInfoVertex(hangVertex);
	cout << endl;

}
void coutVectorInfoVertex(vector<int> v) {
	if (v.size() > 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		return;
	}

	cout << "Khong co dinh nao";
}