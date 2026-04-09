#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> vec;
int resposta;

void func(int a,int b){
    set<int> visitados;
    visitados.insert(a);
    queue<pair<int,int>> fila; fila.push({a,0});
    pair<int,int> aux;
    resposta = a;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        if(aux.second == b) continue;
        for(auto it : vec[aux.first]){
            if(visitados.find(it) == visitados.end()){
                fila.push({it,aux.second+1});
                visitados.insert(it);
                resposta += it;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    vec = vector<vector<int>> (n+1);
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int q; cin>>q;
    for(int i = 0; i<q; i++){
        cin>>a>>b;
        resposta = 0;
        if(b == 0) cout<<a<<'\n';
        else{
            func(a,b);
            cout<<resposta<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve(); 
    return 0;
}