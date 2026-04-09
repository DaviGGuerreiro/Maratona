#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<ll> vec (n);
    ll resultado = 0;
    ll psum = 0;
    ll menor = 0;
    for(int i = 0; i<n ;i++){
        cin>>vec[i]; psum += vec[i];
        menor = min(psum, menor);
        if(vec[i] <= 0){
            cout<<resultado<<' ';
        }
        else{
            resultado = max(resultado, psum - menor);
            cout<<resultado<<' ';
        }
    }

    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--){
       solve(); 
    }
    return 0;
}