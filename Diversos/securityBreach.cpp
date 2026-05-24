#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
int n, m;
int a, b, c;
vector<vector<pair<ll,ll>>> vec;
vector<vector<pair<ll,ll>>> inv;

vector<ll> dks(vector<vector<pair<ll,ll>>>& vet){
    vector<ll> dist (n+1, LLONG_MAX);
    //preencher adj com as entradas das arestas e pesos.
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(d>=dist[v]){
            for(auto [u,w]: vet[v]){
                if(dist[u] > max(w,dist[v])){
                    dist[u] = max(w,dist[v]);
                    pq.push({dist[u], u});
                }
            }
        }
    }
    return dist;
}

void solve(){
    cin>>n>>m;
    vec = vector<vector<pair<ll,ll>>> (n+1);
    inv = vector<vector<pair<ll,ll>>> (n+1); 
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vec[a].push_back({b,c});
        inv[b].push_back({a,c});
    }
    auto v1 = dks(vec);
    auto v2 = dks(inv);
    bool b = true;
    for(int i = 1; i<=n; i++){
        if(v2[i] > v1[i]){
            b = false; break;
        }
    }
    if(b) cout<<"YES";
    else cout<<"NO";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}