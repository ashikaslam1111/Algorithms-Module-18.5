#include<bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u,v,w;
};
const int infinity = 1e9;
const int N =500;
int dist[N];
vector<edge>EdgE;
int n,m;
bool cycle_with_bell_man();
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        EdgE.push_back({u,v,w});
    }
    for(int i=0; i<N; i++)dist[i]=infinity;
    int src=1;
    dist[src]=0;
    if(cycle_with_bell_man())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
bool cycle_with_bell_man()
{
    for(int i=1; i<=n; i++)
    {
        for(auto j:EdgE)
        {
            if(dist[j.v]>dist[j.u]+j.w)
            {
                dist[j.v] = dist[j.u]+j.w;
                if(i==n)
                    return true;
            }
        }
    }
    return false;
}
