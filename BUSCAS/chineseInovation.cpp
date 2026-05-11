#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#define FOR(i,n) for(int i=0; i<(int)(n); i++)
#define FOR1(i,n) for(int i=1; i<=(int)(n); i++)

vector<vector<pair<ll,ll>>> estradas;
int n,m,k;

void dijkstra(){
    vector<ll> dist (n+1+k, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d<=dist[v]){
            for(auto [u,w]: estradas[v]){
                if(dist[u] > dist[v] + w){
                    dist[u] = dist[v] + w;
                    pq.push({dist[u], u});
                }
            }
        }
    }
    cout<<dist[n]<<'\n';
}

void solve(){
    cin>>n>>m>>k;
    int u, v, c;
    int t;
    estradas = vector<vector<pair<ll,ll>>> (n+k+1);
    FOR(i,m){
        cin>>u>>v>>c;
        estradas[v].push_back({u,c});
        estradas[u].push_back({v,c});
    }
    FOR1(i,n){
        cin>>t;
        FOR(j,t){
            cin>>u>>c;
            estradas[i].push_back({n+u,c});
            estradas[n+u].push_back({i,0});
        }
    }
    dijkstra();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}