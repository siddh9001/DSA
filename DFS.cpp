#include<iostream>
#include<vector>
using namespace std;
// void dfs(vector<int> adj[], int s, int n, vector<bool>& vis){
//     vis[s] = true;
//     cout << s << " ";

//     for(auto it = adj[s].begin(); it != adj[s].end(); it++)
//     {
//         if(!vis[*it])
//             dfs(adj, *it, n, vis);
//     }
// }
// int main()
// {
//     vector<int> adj[1005];
//     int n,m;
//     cout << "Enter no of vertices: ";
//     cin >> n;
//     cout << "Enter no. of Edges: ";
//     cin >> m;

//     vector<bool> vis(n+1 , false);

//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cout << "enter u & v";
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     dfs(adj, 1, n, vis);
// }

void DFS(int start, int v, vector<int> adj[], vector<bool>& visited){

    visited[start] = true;
    cout << start <<  " ";

    for(auto nbr:adj[start]){
        if(!visited[nbr]){
            DFS(nbr, v, adj, visited);
        }
    }
}

int main(){
    int v, e;
    cout << "Enter the number of vertices : ";
    cin >> v;
    cout << "Enter the number of edges : ";
    cin >> e;

    vector<int> adj[v];
    vector<bool> visited(v, false);

    for(int i=0;i<e;i++){
        int u, v;
        cout << "Enter the u : ";
        cin >> u;
        cout << "Enter the v : ";
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(0, v, adj, visited);
}