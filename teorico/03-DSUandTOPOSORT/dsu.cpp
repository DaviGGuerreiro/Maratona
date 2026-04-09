#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,n) for(int i=0; i<(int)(n); i++)
int const n = 1e5;
int pai[n];
int sz[n];

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(sz[u]<sz[v]) swap(u,v);

    pai[v] = u;
    sz[u] = sz[u] + sz[v];
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    FOR(i,n){
        pai[i] = i;
        sz[i] = 1;
    }
    return 0;
}