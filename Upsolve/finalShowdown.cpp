#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll x;

bool func(tuple<ll,ll,ll> a, tuple<ll,ll,ll> b){
    ll p1 = get<1>(a) + (get<0>(a) * (get<1>(b)));
    ll p2 = get<1>(b) + (get<0>(b) * (get<1>(a)));
    if(p1 > p2) return true;
    return false;
}

void solve(){
    int n, p; cin>>n>>p;
    vector<tuple<ll,ll,ll>> vec (n);
    ll a, b, c;
    tuple<ll,ll,ll> aux; 
    vector<ll> resposta (p + 1, -1); resposta[0] = 0;
    for(int i = 0; i<n; i++){
        cin>>a>>b>>c;
        aux = make_tuple(a, b, c);
        vec[i] = aux;
    }
    sort(vec.begin(),vec.end(), func);
    ll local;
    for(auto it : vec){
        a = get<0>(it);
        b = get<1>(it);
        c = get<2>(it);
        for(int i = p; i>=0; i--){
            if(resposta[i] == -1) continue;
            local = (i * a) + b;
            if(local <= p){
                resposta[local] = max(resposta[local], resposta[i] + c);
            }
        }
    }
    ll maximo = 0;
    for(int i = 0; i<=p; i++){
        maximo = max(maximo, resposta[i]);
    }
    cout<<maximo<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}