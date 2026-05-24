#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec;
    int tamanho = 0;
    ll quantidade = n;
    while(quantidade != 0){
        tamanho++;
        vec.push_back((quantidade%(tamanho+1)));
        quantidade -= vec[tamanho-1];
    }
    cout<<tamanho<<'\n';
    for(auto it: vec){
        cout<<it<<' ';
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