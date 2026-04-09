#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n; bool b = true;
    vector<bool> vis (n+1,false);
    vector<int> vec (n+1);
    for(int i = 1; i<=n; i++){
        cin>>vec[i];
    }
    for(int i = 1; i<=n; i++){
        if(vis[i] == false){
            for(int j = i; j <= n; j = j * 2){
                vis[vec[j]] = true;
            }
            for(int j = i; j <= n; j = j * 2){
                if(vis[j] == false){ b = false; break;}
            }
        }
        if(!b) break;
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