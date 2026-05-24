#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<int> edges (n+1, 0);
    vector<vector<int>> vec (n+1);
    int a, b;
    for(int i = 0; i<m; i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
        edges[a]++; edges[b]++;
    }
    vector<bool> vis (n+1, false);
    queue<int> fila;
    int impar, par = 0;
    ll resposta = 0;
    for(int i = 1; i<=n; i++){
        if(!vis[i] && edges[i] != 0){
            impar = 0;
            vis[i] = true;
            fila.push(i);
            while(!fila.empty()){
                int aux = fila.front(); fila.pop();
                if(edges[aux] % 2 == 1) impar++;
                for(auto it : vec[aux]){
                    if(!vis[it]){
                        fila.push(it);
                        vis[it] = true;
                    }
                }
            }
            if(impar == 0) par++;
            else resposta += impar/2;
        }
    }
    if(par == 1 && resposta == 0) cout<<0<<'\n';
    else cout<<(resposta + par)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}