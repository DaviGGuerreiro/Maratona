#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    vector<int> v (n);
    vector<pair<int,int>> par (n);
    ll resposta = 0;
    ll x, y;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    for(int i = 0; i<n; i++){
        if(i == 0){
            x = gcd(vec[i],vec[i+1]);
            if(vec[i] > x) resposta++;
        }
        else if(i == n-1){
            y = gcd(vec[i],vec[i-1]);
            if(vec[i] > y) resposta++;
        }
        else{
            x = gcd(vec[i],vec[i+1]);
            y = gcd(vec[i],vec[i-1]);
            x = lcm(x, y);
            if(vec[i] > x) resposta++;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}