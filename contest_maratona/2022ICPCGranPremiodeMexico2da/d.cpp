#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
ll n, m;
ll peso = 0;
vector<vector<pll>> adj;
vector<pll> distancia;

void bfs(){
    distancia[1] = {0,0};
    queue<ll> fila; fila.push(1);
    while(!fila.empty()){
        auto it = fila.front();
        fila.pop();
        for(auto x : adj[it]){
            if(distancia[x.first].first == -1){
                peso += ((distancia[it].first + 1) * x.second);
                distancia[x.first] = {distancia[it].first + 1, x.second};
                fila.push(x.first);
            }
            else if((distancia[x.first].first == distancia[it].first + 1) && distancia[x.first].second > x.second){
                peso -= ((distancia[x.first].second - x.second) * (distancia[x.first].first));
                distancia[x.first].second = x.second;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    ll a, b, c;
    adj = vector<vector<pll>> (n+1);
    distancia = vector<pll>  (n+1, {-1, -1});
    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    bfs();
    cout<<peso<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}