#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int num = 1e5 + 1;
int pai[num];
int sz[num];
ll modulo = 1e9 + 7;

int findd(int u){
    if(pai[u] == u) return u;
    return pai[u] = findd(pai[u]);
}

void join(int u, int v){
    u = findd(u);
    v = findd(v);
    if(u == v) return;
    if(sz[u]<sz[v]) swap(u,v);
    sz[u] += sz[v];
    pai[v] = u;
}

void solve(){
    int n, m; cin>>n>>m;
    for(int i=0;i<=n;i++){
        pai[i] = i;
        sz[i] = 1;
    }
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        join(a,b);
    }
    set<int> conjunto;
    ll resposta = 1;
    for(int i=1;i<=n;i++){
        int v = findd(i);
        if(conjunto.find(v) == conjunto.end()){
            conjunto.insert(v);
            resposta = resposta * sz[v];
            resposta = (resposta % modulo);
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}