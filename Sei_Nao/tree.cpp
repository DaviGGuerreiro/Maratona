#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q; cin>>n>>q;
    vector<int> vec (n+1,0);
    int f,s, val;
    for(int i = 0;i < n-1;i++){
        cin>>f>>s>>val;
        vec[f] ^= val; vec[s] ^= val;
    }
    int tipo, a ,b, c;
    for(int i = 0; i<q; i++){
        cin>>tipo;
        if(tipo == 1){
            cin>>a>>b>>c;
            vec[a] ^= c; vec[b] ^= c;
        }
        else{
            cin>>a;
            cout<<vec[a]<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}