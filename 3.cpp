#include<bits/stdc++.h>
using namespace std;
const int N=505;
const long long int infinity = 1e18;
int n,m,q;
long long int adjacency_matrix[N][N];
void floyed_warshall();
int main()
{
    cin>>n>>m>>q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            adjacency_matrix[i][j] = infinity;
        }
    }
    for(int i = 1; i<=n; i++)  adjacency_matrix[i][i] = 0;
    for(int i =1; i<=m; i++)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        adjacency_matrix[u][v] = min(w, adjacency_matrix[u][v]);
        adjacency_matrix[v][u] = min(w,adjacency_matrix[v][u]);
    }
    floyed_warshall();
    for(int i=1; i<=q; i++)
    {
        int u,v;
        cin>>u>>v;
        if(adjacency_matrix[u][v]==infinity)
            cout<<-1<<endl;
        else
            cout<<adjacency_matrix[u][v]<<endl;
    }
    return 0;
}
void floyed_warshall()
{
    for(int k=1; k<=n; k++)
    {
        for( int u=1; u<=n; u++)
        {
            for( int v=1; v<=n; v++)
            {
                if(adjacency_matrix[u][v]>adjacency_matrix[u][k]+adjacency_matrix[k][v])
                    adjacency_matrix[u][v] = adjacency_matrix[u][k]+adjacency_matrix[k][v];
            }
        }
    }

}
