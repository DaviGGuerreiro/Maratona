#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        vec[i] = (vec[i] % m) + 1;
    }
    int maximo = 1;
    int local = 1;
    for(int i = 1; i<n; i++){
        if(vec[i] == vec[i-1]){
            local++;
            if(local > maximo){
                maximo = local;
            }
        }
        else{
            local = 1;
        }
    }
    
    if(maximo >= m){
        cout<<"NO"<<'\n';
    }
    else{
        cout<<"YES"<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}