#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR1(i,n) for(int i=1; i<=(int)(n); i++)
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