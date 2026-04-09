#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,n) for(int i=0; i<(int)(n); i++)
const int n = 1e5;
vector<ll> dist (n, LLONG_MAX);
void bellman_Ford(){
    dist[1] = 0;
    vector<tuple<int,int,int>> edges;
    //ler as arestas e pesos respectivos.
    //interessante botar um supervertice 0 que chega em todos com distancia 0.
    //pode - se usar um vetor de pais para salvar o caminho do feito, mas antes de printar o caminho se atualiza n vezes o pai de v para garantir que ele esta dentro do ciclo.
    //Tambem é plausivel uma segunda iteração para tentar repassar o status de relaxamento, com o intuito de propagar os vertices de ciclos negativos e ver se eles alcançam o vertice de saida.
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