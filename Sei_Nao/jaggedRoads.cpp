#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;

int n, m;
vector<vector<pair<ll,ll>>> vec;

long double log7(ll w){
    return log(w)/log(7.0);
}

void dijkstra(){
    vector<ld> dist (n+1, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0.0;
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d<=dist[v]){
            for(auto [u,w]: vec[v]){
                if(dist[u] > dist[v] + log7(w)){
                    dist[u] = dist[v] + log7(w);
                    pq.push({dist[u], u});
                }
            }
        }
    }
    cout<<fixed<<setprecision(15)<<dist[n]<<'\n';
}

void solve(){
    cin>>n>>m;
    int u, v, c;
    vec = vector<vector<pair<ll,ll>>> (n+1);
    for(int i = 0; i<m; i++){
        cin>>u>>v>>c;
        vec[u].push_back({v,c});
        vec[v].push_back({u,c});
    }
    dijkstra();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}