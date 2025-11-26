#include<bits/stdc++.h>
using namespace std;
//tipos
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

//  ll aux = LLONG_MAX;
//  int a = INT_MAX;
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