#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;cin>>v>>e;
    int cost[v+1][v+1]={0};
    for(int i=1;i<=v;i++)
    for(int j=1;j<=v;j++) if(i!=j)cost[i][j]=1000000;
    for(int i=0;i<e;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        cost[x][y]=z;
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            for(int k=1;k<=v;k++)
            {
                cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
