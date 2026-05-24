#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>> vec (n+1);
    vector<ll> distancias (n + 1, 1e15);
    int a, b, c;
    map<pair<int,int>, int> mapa;
    for(int i = 0; i<m; i++){
        cin>>a>>b>>c;
        if(mapa.find({a,b}) != mapa.end()){
            mapa[{a,b}] = min(mapa[{a,b}], c);
            mapa[{b,a}] = min(mapa[{b,a}], c);
        }
        else{
            mapa[{a,b}] = c;
            mapa[{b,a}] = c;
        }
    }

    for(const auto& [u, v] : mapa){
        vec[u.first].push_back({u.second, v});
        vec[u.second].push_back({u.first, v});
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; pq.push({0,1});
    distancias[1] = 0;
    vector<int> pai(n+1);
    for(int i = 1; i<=n; i++){
        pai[i] = i;
    }
    pai[1] = 0;
    while(!pq.empty()){
        auto [u, v] = pq.top(); pq.pop();
        if(u > distancias[v]) continue;
        for(const auto& [vertice, peso] : vec[v]){
            if(distancias[vertice] > distancias[v] + peso){
                distancias[vertice] = distancias[v] + peso;
                pai[vertice] = v;
                pq.push({distancias[vertice], vertice});
            }
        }
    }

    if(distancias[n] == 1e15){
        cout<<"-1"<<'\n';
        return;
    }
    else{
        stack<int> pilha;
        pilha.push(n);
        int x = pai[n];
        while(x != 0){
            pilha.push(x);
            x = pai[x];
        }
        while(!pilha.empty()){
            cout<<pilha.top()<<' '; pilha.pop();
        }
        cout<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}