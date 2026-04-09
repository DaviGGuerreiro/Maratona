#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; int aux; bool b = false;
    for(int i = 0; i<n; i++){
        cin>>aux; if(aux == 67) b = true;
    }
    if(b) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
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