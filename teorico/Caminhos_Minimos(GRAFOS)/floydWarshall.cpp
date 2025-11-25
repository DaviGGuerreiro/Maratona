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
const int n = 300 + 10;

void floyd_warshall(){
    vector<vector<ll>> dist (n+1, vector<ll> (n+1));
    //ao preencher multiplas arestas eu so pego o minimo
    //dist[i][j] com i == j deve ser 0;
    FOR1(k,n){
        FOR1(u,n){
            FOR1(v,n){
                if(dist[u][k] != LLONG_MAX && dist[k][v] != LLONG_MAX){
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    floyd_warshall();
    return 0;
}