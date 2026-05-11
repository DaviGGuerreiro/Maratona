#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll inc = 0;
const int num = 1e5 + 2;
int pai[num];
int sz[num];

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);
    inc -= (ll)sz[u] * (ll)sz[v];
    pai[v] = u;
    sz[u] += sz[v];
}

void solve(){
    ll n, m;
    cin>>n>>m;
    inc = n * (n-1) / 2;
    stack<pair<int,int>> pilha;
    stack<ll> resposta;
    for(int i = 1 ; i <= n; i++){
        pai[i] = i;
        sz[i] = 1;
    }
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b; pilha.push({a,b});
    }
    pair<int,int> aux;
    while(!pilha.empty()){
        resposta.push(inc);
        aux = pilha.top(); pilha.pop();
        unite(aux.first,aux.second);
    }
    while(!resposta.empty()){
        cout<<resposta.top()<<'\n';
        resposta.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}