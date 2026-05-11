#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const pair<int,int> mover[] = {{0,1},{1,2},{2,3},{4,5},{5,6},{6,7},{0,4},{1,5},{2,6},{3,7}};

void solve(){
    vector<int> inicio (8);
    vector<int> fim (8);
    vector<int> aux (8);
    for(int i = 0; i<8; i++) cin>>inicio[i];
    for(int i = 0; i<8; i++) cin>>fim[i];
    if(inicio == fim){cout<<0<<'\n'; return;}
    map<vector<int>, int> custo; custo[inicio] = 0;
    priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>> pq;
    pq.push({0, inicio}); int peso;
    while(!pq.empty()){
        auto [w, estado] = pq.top(); pq.pop();
        if(w > custo[estado]) continue;
        for(auto it : mover){
            aux = estado;
            peso = aux[it.first] + aux[it.second];
            aux[it.first] = estado[it.second]; aux[it.second] = estado[it.first];
            if(aux != inicio && (custo[aux] > custo[estado] + peso || custo[aux] == 0)){
                custo[aux] = custo[estado] + peso;
                pq.push({custo[aux], aux});
            }
        }
    }
    cout<<custo[fim]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}