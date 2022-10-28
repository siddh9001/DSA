#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void topological_sort(int u, vector<vector<int>>& graph, int V, vector<bool>& visited,vector<int>& ans){
    visited[u] = true;

    for(int v = 0; v < V; v++){
        if(graph[u][v] == 1 && visited[v] == false){
            topological_sort(v, graph, V, visited, ans);
        }
    }
    ans.push_back(u);
}

main()
{
    int V,E;
    cout << "Enter the number of vertices : ";
    cin >> V;
    cout << "Enter the number of edges : ";
    cin >> E;

    vector<vector<int>> graph(V, vector<int>(V));

    for(int i=0;i<E;i++){
        cout << "Enter Edge " << i+1 <<", u & v : ";
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    vector<bool> visited(V, false);
    topological_sort(0, graph, V, visited, ans);

    cout << "Topological Sorting order is  : ";
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }

}