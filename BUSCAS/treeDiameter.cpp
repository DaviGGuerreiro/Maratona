#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int num = 2e5 + 2;
int pai[num];
int sz[num];
int diametro = 1;

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void unite(int u, int v){
    int aux = sz[u] + sz[v] + 1;
    u = find(u);
    v = find(v);
    if(sz[u] < sz[v]) swap(u,v);
    sz[u] += sz[v];
    pai[v] = u;
    return;
}

void solve(){
    int n; cin>>n;
    for(int  i = 0; i <= n; i++){
        pai[i] = i;
        sz[i] = 0;
    }
    int a, b;
    for(int i = 0; i < n-1; i++){
        cin>>a>>b;
        unite(a,b);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}