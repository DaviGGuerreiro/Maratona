#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll n, k; cin>>n>>k;
    vector<pair<ll,ll>> vec (n);
    for(int i = 0; i < n; i++){
        cin>>vec[i].first;
    }
    for(int i = 0; i < n; i++){
        cin>>vec[i].second;
    }
    sort(vec.begin(), vec.end());
    ll x = vec[k-1].first; pair<ll,ll> search = {x, 1e9 + 1};
    int it = upper_bound(vec.begin(),vec.end(), search) - vec.begin() - 1;
    ll felicidade = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = it; i >= 0 ; i--){
        if((int)pq.size() < k){
            pq.push(vec[i].second);
            felicidade += vec[i].second;
        }
        else{
            if(pq.top() < vec[i].second){
                felicidade += (vec[i].second - pq.top());
                pq.pop();
                pq.push(vec[i].second);
            }
        }
    }
    cout<<x<<' '<<felicidade<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("icecream.in","r",stdin);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}