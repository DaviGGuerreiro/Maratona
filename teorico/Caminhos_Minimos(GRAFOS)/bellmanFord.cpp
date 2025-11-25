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

const int n = 1e5;
vector<ll> dist (n, LLONG_MAX);

void bellman_Ford(){
    dist[1] = 0;
    vector<tuple<int,int,int>> edges;
    //ler as arestas e pesos respectivos.
    FOR(rep,n-1){
        for(auto [u,v,w]: edges){
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    //verificar se tem um ciclo negativo: (iterar depois de construir o vetor de dist anterior).
    bool ciclonegativo = false;
    for(auto [u,v,w]: edges){
        if(dist[v] > dist[u] + w){
            ciclonegativo = true;
            break;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    bellman_Ford();
    return 0;
}