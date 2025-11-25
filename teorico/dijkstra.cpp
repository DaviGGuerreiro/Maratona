#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
//loops
#define FOR(i,n) for(int i=0; i<(int)(n); i++)
#define FOR1(i,n) for(int i=1; i<=(int)(n); i++)
#define FORA(x,a) for(auto &x : a)
//Sorts
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
//debug
#define dbg(x) cerr << #x << " = " << x << "\n" 

const int n = 1e5 + 10;

/* Para Grafos densos. (poucos vertices muitas arestas)
void dijkstra(){
    vector<ll> dist (n+1, LLONG_MAX);
    vector<vector<pll>> adj (n+1);
    //preencher adj com as entradas das arestas e pesos.
    vector<bool> vis (n+1,  false);
    int v;
    ll mn;
    FOR(i,n){
        v = -1;
        mn = LLONG_MAX;
        FOR1(j,n){
            if(!vis[j] && (dist[j] < mn){
                mn = dist[j];
                v = j;
            }
        }
        if(v == -1) break;
        vis[v] = true;
        for(auto [u,w]: adj[v]){
            if(dist[u] > dist[v] + w){
                dist[u] = dist[v] + w;
            }
        }
    }
}
*/

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

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        dijkstra();
    }
    return 0;
}