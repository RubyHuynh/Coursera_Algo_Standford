#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
	adj[s] .push_back(d);
	adj[d] .push_back(s);
}

void dump(vector<int> adj[], int v) {
	for (int d = 0; d < v; d++) {
		cout << "\n Vertex " << d << " connects to :";
		for (auto x : adj[d]) {
			cout << ", " << x;
		}
		cout << "\n";
	}
}

int main() {
	int v = 5;
	vector<int> g[v];
	
	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 0, 3);
	addEdge(g, 1, 2);
	dump(g, v);
	return 0;
}
