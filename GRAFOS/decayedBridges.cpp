#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll total;
int const k = 1e5+1;
int pai[k];
int sz[k];

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(sz[u]<sz[v]) swap(u,v);
    total -= (1LL * sz[u] * sz[v]);
    pai[v] = u;
    sz[u] = sz[u] + sz[v];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> pontes (m);
    for(int i=0;i<n+1;i++){
        pai[i] = i;
        sz[i] = 1;
    }
    for(int i=0;i<m;i++){
        cin>>pontes[m-i-1].first>>pontes[m-1-i].second;
    }
    vector<ll> resposta (m);
    total = 1LL * n * (n-1);
    total = total/2;
    for(int i =0; i<m; i++){
        resposta[m-1-i] = total;
        join(pontes[i].first,pontes[i].second);
    }
    for(int i=0;i<m;i++){
        cout<<resposta[i]<<"\n";
    }

    return 0;
}