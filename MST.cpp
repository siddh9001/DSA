#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int costm[1005][1005];

// int minkey(int key[], int set[], int n)
// {
//     int min = INT_MAX, min_index;
//     for(int i=0;i<n;i++)
//     {
//         if(set[i] == 0 && key[i] < min)
//         {
//             min = key[i];
//             min_index = i;
//         }
//     }

//     return min_index;
// }
// void primsAlgorithm(int n)
// {
//     int p[n], key[n], set[n];

//     for(int i=0;i<n;i++)
//     {   key[i] = INT_MAX;
//         set[i]=0;
//     }

//     key[0]=0;
//     p[0]=-1;
//     for(int i=0;i<n-1;i++)
//     {
//         int u = minkey(key, set, n);
//         set[u] = 1;
//         for(int v=0;v<n;v++)
//         {
//             if(costm[u][v] == 1 && set[v] == 0 && costm[u][v] < key[v])
//             {
//                 p[v] = u;
//                 key[v] = costm[u][v];
//             }
//         }
//     }

//     for(int i=1;i<n;i++)
//     {
//         cout << p[i] << " - " << i << " : " << costm[i][p[i]] <<"\n";
//     }
// }

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
    void union(int x,int y){
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
}

int main()
{
    for(int i=0;i<1005;i++)
        for(int j=0;j<1005;j++)
            if(i!=j)costm[i][j] = 0;

    int n,e;
    cout << "Enter vertices & edges: ";
    cin >> n >> e;
    for(int i=0;i<e;i++)
    {
        int u,v, cost;
        cout << "Enter the u, v & cost: ";
        cin >> u >> v >> cost;
        costm[u][v] = cost;
        costm[v][u] = cost;
    }

    //showing matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << costm[i][j] << " ";
        }
        cout << endl;
    }

    primsAlgorithm(n);
}






/*
#include <stdio.h>//prim's algorithm
#define inf 999999
int n=5;
int minkey(int key[],int set[])
{
    int min=inf,min_ind;
    for(int i=0;i<n;i++)
    {
        if(set[i]==0&&key[i]<min)
        {min=key[i];min_ind=i;}
    }
    return min_ind;
}
int prim(int adj[n][n])
{
    int p[n],key[n],set[n];
    for(int i=0;i<n;i++){ key[i]=inf,set[i]=0;}
    key[0]=0;
    p[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int u=minkey(key,set);
        set[u]=1;
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]!=0 &&set[v]==0&&adj[u][v]<key[v])
            {
                p[v]=u;key[v]=adj[u][v];
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        printf("%d - %d :  %d\n",p[i],i,adj[i][p[i]]);
    }
}
int main()
{
   int adj[][5]={{0,2,0,6,0},{2,0,3,8,5},{0,3,0,0,7},{6,8,0,0,9},{0,5,7,9,0}};
   prim(adj);
}
*/