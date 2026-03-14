#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
vector<vector<int>> vec;
vector<int> visitados;
set<int> conjunto;

void dfs2(int x, int ind){
    visitados[x] = ind;
    for(auto it: vec[x]){
        if(visitados[it] == -2){
            dfs2(it, ind);
        }
    }
    return;
}

void dfs(int x, int ind){
    visitados[x] = ind;
    for(auto it: vec[x]){
        if(visitados[it] == -2){
            dfs(it, x);
        }
        else if(conjunto.empty() && visitados[x] != it){
            while(x != it){
                conjunto.insert(x);
                x = visitados[x];
            }
            conjunto.insert(x);
            return;
        }
    }
    return;
}

void solve(){
    cin>>n;
    vec = vector<vector<int>> (n);
    visitados = vector<int> (n,-2);
    int a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }
    dfs(0,-1);
    for(int i =0; i<n; i++){
        if(conjunto.find(i) == conjunto.end()){
            visitados[i] = -2;
        }
    }
    for(auto x : conjunto){
        dfs2(x, visitados[x]);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(conjunto.empty() || conjunto.size() <= 2){
            cout<<"YeS"<<'\n'; continue;
        }
        if(visitados[a-1] == visitados[b-1]){
            cout<<"Yes"<<'\n';
        }
        else{
            cout<<"No"<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}