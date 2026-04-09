#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int t; 

static const ll P1 = 31;
static const ll P2 = 37;
static const ll M1 = 1e9 + 33;
static const ll M2 = 1e9 + 93;

const int MAXN = 81; //tamanho maximo da string;
ll powers1[MAXN], powers2[MAXN];
ll prefix_hash1[MAXN], prefix_hash2[MAXN];

void calc_powers(int n) { //chamar antes de qualquer coisa
    powers1[0] = 1;
    powers2[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers1[i] = (powers1[i - 1] * P1) % M1;
        powers2[i] = (powers2[i - 1] * P2) % M2;
    }
}

struct StringHash {
    vector<ll> prefix_hash1, prefix_hash2;
    StringHash(const string& s) {
        int n = s.size();
        prefix_hash1.assign(n + 1, 0);
        prefix_hash2.assign(n + 1, 0);

        for(int i = 0; i < n; i++){
            ll val = s[i] - 'a' + 1;
            prefix_hash1[i+1] = (prefix_hash1[i] * P1 + val) % M1;
            prefix_hash2[i+1] = (prefix_hash2[i] * P2 + val) % M2;
        }
    }
    pair<ll,ll> query(int i, int j) {
        int len = j - i + 1;
        ll h1 = (((prefix_hash1[j+1] - (prefix_hash1[i] * powers1[len]) % M1) % M1) + M1) % M1;
        ll h2 = (((prefix_hash2[j+1] - (prefix_hash2[i] * powers2[len]) % M2) % M2) + M2) % M2;
        return {h1, h2};
    }
};

void solve(){
    string s; cin>>s;
    int n = (int) s.size();
    int resposta = n;
    StringHash sh(s);
    int l; bool b;
    for(int i = 1; i<=n; i++){
        if(n%i != 0) continue;
        b = true;
        l = i;
        while(l + i - 1 < n){
            if(sh.query(0,i-1) != sh.query(l,l+i-1)){
                b = false; break;
            }
            l+=i;
        }
        if(b){ 
            resposta = i; break;
        }
    }
    cout<<resposta<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    calc_powers(80);
    while(t--){
       solve();
       if(t!=0) cout<<'\n';
    }
    return 0;
}