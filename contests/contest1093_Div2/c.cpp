#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll p, q; cin>>p>>q;
    ll x = p + q*2;
    ll m, n = 0;
    ll x1, x2;
    bool b = false;
    for(ll i = 1; i * i <= x; i++){
        if(x % ((i * 2ll) + 1ll) == i){
            x1 = i;
            x2 = (x - i)/((i * 2ll) + 1ll);
            b = true;
            if(x1 > x2){
                break;
            }
            else{
                n = x1;
                m = x2;
            }
        }
    }
    if(!b){
        cout<<-1<<'\n';
    }
    else{
        if((m+1) * n < q){
            cout<<-1<<'\n';
            return;
        }
        cout<<n<<' '<<m<<'\n';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}