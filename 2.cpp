#include<bits/stdc++.h>
using namespace std;
class edge
{
public:
    int u,v,w;
};
const int infinity = 1e9;
const int N =5001;
int dist[N];
vector<edge>EdgE;
int n,m;
bool cycle_with_bell_man();
int last_updated_node =-1;
int parent[N];
void path_printer();
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
    {
        cout<<"YES\n";
        path_printer();
    }
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
                parent[j.v] = j.u;
                if(i==n)
                {
                    last_updated_node = j.v ;
                    return true;
                }
            }
        }
    }
    return false;
}
void path_printer()
{
    for(int i= 1; i<n; i++)
    {
        last_updated_node=parent[last_updated_node];
    }
    stack<int>st;
    st.push(last_updated_node);
    while(1)
    {
        int now =parent[st.top()];
        st.push(now);
        if(st.top()==last_updated_node)
            break;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
