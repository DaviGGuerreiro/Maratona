#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(){
    int n, m, aux; cin>>n;
    vector<set<int>> vec(n);
    map<int,set<int>> mapa; 
    map<int,bool> visto;
    for(int i = 0; i<n; i++){
        cin>>m;
        for(int j = 0; j<m; j++){
            cin>>aux;
            mapa[aux].insert(i);
            vec[i].insert(aux);
        }
    }
    vector<bool> visitados (n,false);
    vector<tuple<int,int,int>> resposta;
    queue<int> fila;
    fila.push(0);
    visitados[0] = true;
    int num = 1;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(auto it : vec[aux]){
            if(visto[it] == false){
                for(auto x : mapa[it]){
                    if(visitados[x] == false){
                        resposta.push_back({aux+1,x+1,it});
                        num++;
                        visitados[x] = true;
                        fila.push(x);
                    }
                }
                visto[it] = true;
            }
        }
    }
    if(num != n){ cout<<"impossible"<<'\n'; return;}
    for(auto [u,v,w] : resposta){
        cout<<u<<' '<<v<<' '<<w<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}