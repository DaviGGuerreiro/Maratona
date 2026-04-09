#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> p (n), q (n); bool f = false;
    vector<int> quantidade(n,0);
    for(int i = 0; i<n; i++){
        cin>>p[i];
    }
    for(int i = 0; i<n; i++){
        cin>>q[i];
        quantidade[i] = n - p[i];
        if(quantidade[i] < q[i]) f = true;
    }
    if(f){cout<<-1<<'\n'; return;}
    vector<int> resposta (n,0);
    for(int i = n-1; i >=0 ; i++){

    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}