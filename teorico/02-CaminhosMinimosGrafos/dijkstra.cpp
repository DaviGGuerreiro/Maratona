#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int n = 1e5 + 10;
//não funciona com arestas negativas
//pode ser multisource
void dijkstra(){
    vector<ll> dist (n+1, LLONG_MAX);
    vector<vector<pll>> adj (n+1);
    //preencher adj com as entradas das arestas e pesos.
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d<=dist[v]){
            for(auto [u,w]: adj[v]){
                if(dist[u] > dist[v] + w){
                    dist[u] = dist[v] + w;
                    pq.push({dist[u], u});
                }
            }
        }
    }

}