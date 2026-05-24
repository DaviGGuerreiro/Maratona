#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
#define all(a) (a).begin(),(a).end()
#define printn(v,n) for(int i=0;i<n;i++) cout << v[i] << (i == n-1 ? "\n" : " ")

const int MOD = 998244353;

ll fexp(ll base, ll pot) {
    ll ans = 1ll;
    while(pot) {
        if(pot & 1) {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        pot >>= 1ll;
    }
    return ans;
}

ll mod_mul(ll a, ll b) { return (a % MOD * b % MOD) % MOD; }


vector<pli> getprimes(ll n) {
    vector<pli> primes;
    for( ll i=2;i*i<=n;i++) {
        int cnt = 0;

        while(n%i == 0) {
            n /= i;
            cnt++;
        }

        if(cnt > 0) { primes.push_back({i,cnt}); }
    }

    if(n > 1) { primes.push_back({n,1}); }
    return primes;
}


void solve() {
    int n; cin>>n;

    map<int,int> freq;
    ll ans = 1;

    bool usou=false;

    FORi(n) {
        int a,b; cin>>a>>b;
        if(a % b != 0) {
            usou=true;
            b /= gcd(a,b);
            vector<pli> primos = getprimes(b);

            for(auto [valor,qtd] : primos) {
                if(freq.find(valor) == freq.end()) {
                    freq[valor] = valor;
                    ans = mod_mul(ans, valor);
                }
            }
        }
    }
    if(!usou) { ans = 2; }
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);cin.tie(0);

    solve();
} 