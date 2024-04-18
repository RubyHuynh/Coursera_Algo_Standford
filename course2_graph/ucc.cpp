#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;


void addEdge(vector<int> g[], int s, int d) {
	g[s].push_back(d);
}

void bfs(vector<int> g[], int s, vector<int> &explored) {
	queue<int> q;
	explored[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ", ";
		for (auto w : g[u]) {
			if (!explored[w]) {
				explored[w] = 1;
				q.push(w);
			}
		}
	}
		
}

int ucc(vector<int> g[], int V) {
	vector<int> explored(V);
	int ret = 0;
	for (int i = 0; i < V; i++) {
		if (!explored[i]) {
			bfs(g, i, explored);
			cout << "\n done 1 pieces, total " << ++ret;
			cout <<"\n";
		}
	}
	return ret;
}

int main() {
	int V = 12;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 2);
	addEdge(adj, 3, 4);
	addEdge(adj, 3, 7);
	addEdge(adj, 4, 5);
	addEdge(adj, 4, 6);
	addEdge(adj, 4, 7);
	addEdge(adj, 5, 6);
	addEdge(adj, 6, 7);
	addEdge(adj, 8, 9);
	addEdge(adj, 8, 10);
	addEdge(adj, 11, 11);
		
	cout << "DONE UCC " << ucc(adj, V);
	cout << "\n";
	return 0;
}
