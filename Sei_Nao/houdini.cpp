#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> candy;
vector<vector<int>> vec;
vector<int> visitados;
vector<int> t;
int resposta = 0;

int dfs(int ind){
    visitados[ind] = 0;
    for(auto x : vec[ind]){
        if(visitados[x] == -1){
            t[ind] += dfs(x);
        }
    }
    if(t[ind]%2 == 0){
        resposta ++;
    }
    return t[ind];
}

void solve(){
    cin>>n;
    candy = vector<int> (n);
    vec = vector<vector<int>> (n); 
    visitados = vector<int> (n,-1);
    t = vector<int> (n);
    queue<int> fila;
    ll total = 0;
    for(int i=0;i<n;i++){ cin>>candy[i]; total += candy[i]; visitados[i] = -1; t[i] = candy[i];}
    int a, b;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }
    if(total%2 == 1){ cout<<-1; return;}
    dfs(0);
    cout<<resposta;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}