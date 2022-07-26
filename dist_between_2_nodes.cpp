#include <bits/stdc++.h> //distance btw 2 node in a graph
using  namespace std;
vector<int> adj[1005];
bool v[1005];
int q[1005],dist[1005],f=0,r=-1;
void bfs(int s,int d,int n)
{
    if(s==d)printf("0");
    q[++r]=s; v[s]=1;dist[s]=0;
    while(f<=r)
    {
        int x=q[f++];
        for(auto &i:adj[x])
        {
            if(v[i]==0)
            {
                q[++r]=i; v[i]=1; dist[i]=dist[x]+1;
            }
        }
    }
    if(dist[d]==0)printf("-1");
    else printf("%d",dist[d]);
}
int main(){
    int n,m,s,d; cin>>n>>m>>s>>d;
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(s,d,n);
}