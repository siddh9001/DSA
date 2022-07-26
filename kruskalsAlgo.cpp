#include<bits/stdc++.h>
using namespace std;
class dso{
    int *p;
    int *rank;
    public:
    dso(int n){
      p=new int[n];
      rank=new int[n];
      for(int i=0;i<n;i++)
      {
          p[i]=-1;
          rank[i]=1;
      }
    }
    int find(int i){
        if(p[i]==-1)return i;
        return p[i]=find(p[i]);
    }
    void union1(int x,int y){
        int s1=find(x),s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2])
            {
                p[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                p[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
class Graph
{
    int n;
    vector<vector<int>> adj;
    public:
    Graph(int n){
        this->n=n;
    }
    void addedge(int x,int y,int z){
          adj.push_back({z,y,x});    
    }
    void kruskals()
    {
        sort(adj.begin(),adj.end());
        dso s(n);
        int ans=0;
        for(auto e:adj)
        {
            int w=e[0],x=e[1],y=e[2];
            if(s.find(x)!=s.find(y))
            {
                s.union1(x,y);
                ans+=w;
                cout<<x<<"-"<<y<<" : "<<w<<endl;
            }
        }
        cout<<"minimum cost is "<<ans;
    }
};
int main()
{
    int n,m; cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g.addedge(u,v,w);
    }
    g.kruskals();
}