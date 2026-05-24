#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll p, MOD = 1;

ll mod_add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mod_sub(ll a, ll b){
    return((a % MOD - b % MOD) + MOD) % MOD;
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
    ll k; cin>>k>>p; MOD = p;
    vector<ll> fatorial (k + 1); fatorial[0] = 1;
    vector<ll> invfat (k + 1); invfat[0] = 1;
    for(ll i = 1; i <= k; i++){
        fatorial[i] = (fatorial[i-1] * i) % MOD;
    }
    invfat[k] = fexp(fatorial[k], MOD - 2);
    for(ll i = k-1; i >= 1; i--){
        invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
    }
    vector<ll> combina (k+1); combina[0] = 1;
    for(ll i = 2; i <=k; i += 2){
        combina[i] = mod_mul(fatorial[i], mod_mul(invfat[i/2], invfat[i/2]));
    }
    ll resposta = 0;
    ll local, c1, c2;
    for(ll i = 0; i<= k; i++){
        c1 = mod_mul(fatorial[k], mod_mul(invfat[k - i], invfat[i]));
        local = 0;
        for(ll j = 0; j <= k - i; j++){
            c2 = mod_mul(fatorial[k-i], mod_mul(invfat[k-i-j], invfat[j]));
            if(j % 2 == 0) local = mod_add(local, mod_mul(c2, combina[j]));
        }
        local = mod_mul(local, local);
        if(i % 2 == 0) resposta = mod_add(resposta, mod_mul(local, c1));
        else resposta = mod_sub(resposta, mod_mul(local, c1));
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}