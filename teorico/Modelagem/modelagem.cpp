#include<bits/stdc++.h>
using namespace std;
//tipos
using ll = long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ti = tuple<int,int,int>;
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

//PROBELMAS DE MODELAGEM CORRESPONDEM A CRIAÇÃO DE NOVOS GRAFOS
//OS NOVOS GRAFOS SUPORTAM A UTILIZAÇÃO DE ALGORITMOS CLÁSSICOS PARA ENCONTRAR A RESPOSTA.
//RESOLVENDO A QUESTÃO DOS CUPONS:

int const n = 1e3; //quantidade de cidades
int cupons = 10; //quantidade de cupons disponiveis
int linhas; //quantidade de arestas
vector<tuple<int,int,int>> adj;

void modelagem(){
    vector<vector<ll>> dist (n+1, vector<ll> (n+1,0));
    vector<vector<pll>> adj (n+1);
    //preencher adj com as entradas das arestas e pesos, adicionando tambem a quantidade de cupons utilizada, (0 em todos).
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({0,1,0});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto [d, v, c] = pq.top();
        pq.pop();
        if(d<=dist[v][c]){
            for(auto [u,w]: adj[v]){
                if(dist[u][c] > dist[v][c] + w){
                    dist[u][c] = dist[v][c] + w;
                    pq.push({dist[u][c], u, c});
                }
                if(c<cupons){
                    if(dist[u][c+1] > dist[v][c] + (w/2)){
                        dist[u][c+1] = dist[v][c] + (w/2);
                        pq.push({dist[u][c+1],u,c+1});
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    modelagem();
    return 0;
}