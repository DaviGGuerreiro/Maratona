#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 5;
vector<vector<int>> arvore;
vector<ll> valores;

// euler tour
vector<int> tin, tout;
int timer = 0;
//vector<int> flat_array;

// Os casos que euler tour pura funciona:
// Muitas queries e nenhuma atualizacao
// Muitas atualizacoes poucas queries


void euler_tour(int node, int prev){
    tin[node] = timer++;
    //flat_array[timer] = valores[node];
    for(int it : arvore[node]){
        if(it != prev) euler_tour(it, node);
    }
    tout[node] = timer;
}

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n; cin>>n;
    arvore = vector<vector<int>> (n+1); valores = vector<ll> (n+1);
    tin = vector<int> (n+1); tout = vector<int> (n+1);
    //flat_array = vector<int> (n+1);
    int a, b;
    for(int i = 0; i<n-1; i++){
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        cin>>valores[i];
    }
    euler_tour(1, 0);
    vector<ll> psum (n+1,0);
    for(int i = 1; i<=n; i++){
        psum[i] = psum[i-1] + valores[i];
    }
    int q; cin>>q;
    ll soma;
    for(int i = 0; i<q; i++){
        cin>>a;
        soma = psum[tout[a]] - psum[tin[a]];
        cout<<tout[a]<<' '<<tin[a]<<' ';
        cout<<soma<<'\n';
    }
    return 0;
}