#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;

void addEdge(vector<int> g[], int s, int d) {
	g[s].push_back(d);
}

void bfs(vector<int> g[], int s, int v, int dest) {
	int explored[v] = {0};
	int dist[v] = {0};
	bool found = 0;
	queue<int> q;
	explored[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << ", ";
		if (u == dest) {
			cout << "level: " << dist[u];
			found = 1;
			break;
		}
		for (auto w : g[u]) {
			if (!explored[w]) {
				explored[w] = 1;
				q.push(w);
				dist[w] = dist[u] + 1;
			}
		}
	}
	if (!found) cout << "not found path p";
	cout << "\n ";
}

int main() {
	int V = 10;
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

	bfs(adj, 2, V, 3);
	bfs(adj, 0, V, 2);
	bfs(adj, 0, V, 3);
	bfs(adj, 0, V, 6);
	return 0;
}
