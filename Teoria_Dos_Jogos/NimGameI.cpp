#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    ll aux = 0;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        aux = aux xor vec[i];
    }
    if(aux == 0){
        cout<<"second"<<'\n';
    }
    else{
        cout<<"first"<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}