// progrsm to fing the number of nodes present in a given tree 
#include <iostream>
#include <queue>
using namespace std;

void noOfNodes(vector<int> adj[], int n, int x, int source, int visited){
	queue<int> q;
	q.push(source);
	visited[source] = true;
	vector<int> level(n+1, 0);
	level[source] = 1;

	while(!q.empty()){
		int u = q.front(); 
		q.pop();
		for(auto v: adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v]=true;
				level[v] = level[u]+1;
			}
		}
	}

	int count = 0;
	for(int i=0;i<level.size();i++)
		if(level[i] == x)count++;

	cout << count;
}
int main() {
	int n;
	cin >> n;
	vector<int> adj[n+1];
	vector<bool> visited(n+1, false);
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int x;
	cin >> x;
	noOfNodes(adj, n, x, 1, visited);
}