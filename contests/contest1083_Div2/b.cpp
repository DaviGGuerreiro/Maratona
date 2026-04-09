#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int temporario = n;
    set<int> conjunto;
    for(int i = 2; i * i <= n; i++){
        if(i > temporario) break;
        if(temporario % i == 0) conjunto.insert(i);
        while(temporario % i == 0){
            temporario /= i;
        }
    }
    if(conjunto.empty()){
        cout<<n<<'\n';
    }
    else{
        int res = temporario;
        for(auto it : conjunto){
            res *= it;
        }
        cout<<res<<'\n';
    }
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