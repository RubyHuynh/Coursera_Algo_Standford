#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;

void addEdge(vector<int> g[], int s, int d) {
	g[s].push_back(d);
}

void dfs(vector<int> g[], int idx, int V) {
	int explored[V] = {0};
	stack<int> s;
	explored[idx] = 1;
	s.push(idx);
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		cout << u << ", ";
		for (auto w : g[u]) {
			if (!explored[w]) {
				explored[w] = 1;
				s.push(w);
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

	cout << "DFS: ";
	dfs(adj, 0, V);
	return 0;
}
