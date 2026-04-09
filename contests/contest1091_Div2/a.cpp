#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> vec (n);
    int soma = 0;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        soma += vec[i];
    }
    if(soma % 2 == 1 || (k * n) % 2 == 0){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}