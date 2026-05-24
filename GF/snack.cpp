#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mod_add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return(a % MOD * b % MOD) % MOD;
}

ll fexp(ll a, ll b){ // num a, primo b - 2 (1e9 + 7 - 2)
    ll ret = 1;
    while(b){
        if(b%2 == 1) ret = mod_mul(ret,a);
        a = mod_mul(a,a);
        b >>= 1;
    }
    return ret % MOD;
}

void solve(){
    ll d, n; cin>>d>>n;
    vector<ll> precalc (d+1); precalc[0] = 1;
    ll aux = 1;
    ll p = d; ll q = 1;
    for(ll i = 1; i<=d; i++){
        aux = mod_mul(aux, p); p--;
        aux = mod_mul(aux, fexp(q, MOD - 2)); q++;
        precalc[i] = aux;
    }
    ll resposta = 0; ll x = n - d;
    for(ll i = 0; i <=d ; i++){
        if(2 * i > x) break;
        if((x - (2 * i)) % 3 == 0 && ((x - (2 * i))/3) <= d){
            resposta = mod_add(resposta, mod_mul(precalc[i], precalc[(x - (2 * i))/3]));
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}