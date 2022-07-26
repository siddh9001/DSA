#include <iostream> //number of connected components
#include<vector>
using  namespace std;
vector<int> adj[1005];
bool v[1005];
void dfs(int s,int n)
{
    v[s]=1;
    for(auto &i:adj[s]){
        if(v[i]==0)dfs(i,n);
    }
}
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0){ x++; dfs(i,n);}
    }
    printf("%d ",x);
}