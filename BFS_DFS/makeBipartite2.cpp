#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll azul = 0;
ll vermelho = 0;
bool dfs(int lugar,vector<vector<int>>& g, vector<bool>& visitados, vector<bool>& cor, bool z){
    visitados[lugar] = true;
    cor [lugar] = z;
    if(cor[lugar]){
        azul++;
    }
    else{
        vermelho++;
    }
    for(auto x : g[lugar]){
        if(!visitados[x]){
            if(!dfs(x,g,visitados,cor,!z)){
                return false;
            }
        }
        else if(cor[x] == cor[lugar]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> vec (n+1);
    vector<bool> visitados (n+1,false);
    vector<bool> cor (n+1);
    bool r = true;
    ll a, b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);    
    }
    ll resposta = n*(n-1);
    resposta  = resposta/2;
    resposta  = resposta - m;
    for(int i=1;i<=n;i++){
        if(!visitados[i]){
            r = dfs(i,vec,visitados,cor,false);
            resposta = resposta - ((azul*(azul-1)/2) + (vermelho*(vermelho-1)/2));
            azul = 0; vermelho = 0;
        }
        if(!r){
            break;
        }
    }
    if(!r){
        cout<<0;
    }
    else{
        cout<<resposta;
    }

    return 0;
}