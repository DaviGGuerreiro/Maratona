#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll sub(ll a, ll b){
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

ll fact(ll x){
    ll res = 1;
    for(int i = 2; i<= x; i++){
        res *= i;
        res = res % MOD;
    }
    return res;
}

void solve(){
    int n; cin>>n;
    ll den1 = 2; den1 = fexp(den1, MOD - 2);
    ll total = mod_mul(n-1,n-2); total = mod_mul(total,den1);
    ll aux =  n - ((n+1)/2) - 2;
    if(aux < 0){cout<<1<<'\n'; return;}
    ll parcial = mod_mul(aux + 2, aux + 1); parcial = mod_mul(parcial,den1); parcial = mod_mul(parcial,3);
    ll x = sub(total,parcial);  total = fexp(total, MOD - 2); x = mod_mul(x,total);
    cout<<x<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}