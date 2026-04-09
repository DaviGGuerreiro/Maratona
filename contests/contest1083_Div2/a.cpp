#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    int ind_maior = -1;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        if(vec[i] == n) ind_maior = i;
    }
    if(ind_maior != 0){
        int aux = vec[0];
        vec[0] = n;
        vec[ind_maior] = aux;
    }
    for(int i = 0; i<n; i++){
        cout<<vec[i]<<' ';
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