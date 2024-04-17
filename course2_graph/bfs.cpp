#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;

void addEdge(vector<int> g[], int s, int d) {
	g[s].push_back(d);
}

void bfs(vector<int> g[], int s, int v) {
	int explored[v] = {0};
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
	cout << "\n";
}

int main() {
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 3);

	cout << "BFS: ";
	bfs(adj, 2, V);
	bfs(adj, 0, V);
	return 0;
}
