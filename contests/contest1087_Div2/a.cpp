#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, c, k; cin>>n>>c>>k;
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    ll resposta = c;
    for(int i = 0; i<n; i++){
        if(resposta >= vec[i]){
            if(resposta >= vec[i] + k){
                resposta += vec[i] + k;
                k = 0;
            }
            else{
                k -= resposta - vec[i];
                resposta += resposta;
            }
        }
        else{
            break;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}