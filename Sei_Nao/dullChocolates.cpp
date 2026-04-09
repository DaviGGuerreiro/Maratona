#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n, m, k; cin>>n>>m>>k;
    ll total = n * m;
    if(k == 0){ cout<<0<<' '<<total<<'\n'; return;}
    ll branco = 0;
    map<ll, vector<ll>> coord; ll x, y;
    for(int i = 0; i<k; i++){
        cin>>x>>y;
        coord[x].push_back(y);
    }

    ll x_atual = 1;
    coord[n+1] = {};
    ll colunas, linhas;
    vector<ll> vecy;
    ll s, e;
    for(auto const& [x, vy] : coord){
        linhas = x - x_atual; colunas = 0;
        for(size_t i = 0; i < vecy.size(); i += 2){
            s = vecy[i];
            if(i != vecy.size() - 1) e = vecy[i+1];
            else e = m + 1;
            colunas += e - s;
        }
        for(size_t i = 0; i < vy.size(); i++){
            vecy.push_back(vy[i]);
        }
        sort(vecy.begin(),vecy.end());
        x_atual = x; branco += (colunas * linhas);
    }
    cout<<branco<<' '<<(total - branco)<<'\n'; return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("dull.in","r",stdin);
    int t; cin>>t;
    while(t--){
       solve(); 
    }
    return 0;
}