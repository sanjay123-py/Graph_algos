#include<bits/stdc++.h>
using namespace std;
int inf=1000000;
int main()
{
    int v,e,s;cin>>v>>e>>s;
    int cost[v+1][v+1],dist[v+1]={0},vis[v+1]={0};
    memset(cost, 0, sizeof(cost));
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            if(i!=j)cost[i][j]=inf;
        }
    }
    for(int i=0;i<e;i++)
    {
        int adj1,adj2,cst;cin>>adj1>>adj2>>cst;
        cost[adj2][adj1]=cst,cost[adj1][adj2]=cst;
    }
    vis[s]=1;
    dist[0]=inf;
    for(int i=1;i<=v;i++)dist[i]=cost[s][i];
    for(int i=0;i<v-1;i++)
    {
        int mi=0;
        for(int j=1;j<=v;j++)
        {
            if(!vis[j]&&dist[j]<dist[mi])mi=j;
        }
        vis[mi]=1;
        for(int j=1;j<=v;j++)
        {
            if(!vis[j]&&dist[j]>dist[mi]+cost[mi][j]) dist[j]=dist[mi]+cost[mi][j];
        }
    }
    for(int i=1;i<=v;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
}
