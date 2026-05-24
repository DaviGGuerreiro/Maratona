#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p, q;
vector<ll> vec;

bool solve2(ll mid){
    ll sub = q*mid;
    ll dif = p - q;
    ll quantidade = 0;
    ll aux;
    for(int i = 0; i<n ; i++){
        if(vec[i] <= sub) continue;
        aux = (vec[i] - sub);
        if(dif == 0) return false;
        quantidade += (aux/dif) + (aux%dif==0 ? 0 : 1);
        if(quantidade > mid) return false;
    }
    return true;
}

void solve(){
    cin>>n>>p>>q;
    vec = vector<ll> (n);
    for(int i=0;i<n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end());
    ll l = 0; ll r = 1e9 + 1;
    ll mid;
    while(r>=l){
        mid = l + ((r-l)/2);
        if(solve2(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<l;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}