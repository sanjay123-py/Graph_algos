#include <iostream>
using namespace std;
const int n=5,m=5;
bool issafe(int i,int j,int arr[n][m])
{
    if(i<0 or i>=n or j<0 || j>=m ||arr[i][j]==0) return false;
    return true;
}
int path(int i,int j,int s[n][m],int arr[n][m])
{
    if(i==n-1 && j==m-1 && arr[i][j]==1)
    {
        s[i][j]=1;return 1;
    }
    if(issafe(i,j,arr))
    {
        s[i][j]=1;
        if(path(i,j+1,s,arr)) return 1;
        if(path(i+1,j,s,arr))return 1;
        s[i][j]=0;
        return 0;
    }
    return 0;
}
int main()
{
    // cin>>n>>m;
    int a[n][m]={0},s[n][m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>a[i][j];
    }
    if(path(0,0,s,a))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        }
    }
   
}
