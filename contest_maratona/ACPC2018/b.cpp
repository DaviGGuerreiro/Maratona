#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define MPI 3.14159265358979323846

void solve(){
    ll n;
    cin>>n; 
    ld teta = MPI * (n-2); teta /= n; ld k = ((ld)1.0 - (cos(teta)))/2.0;
    ld resposta = ((ld)10000.0)/((ld)1.0 - k);
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(5);
    freopen("baklava.in","r",stdin);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}