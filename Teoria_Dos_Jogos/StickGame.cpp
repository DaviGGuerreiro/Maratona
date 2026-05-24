#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k; cin>>n>>k;
    vector<bool> resposta(n+1, false);
    vector<int> movimentos (k);
    for(int i =0; i<k; i++){
        cin>>movimentos[i];
    }
    for(int i = 1; i<=n; i++){
        for(auto it: movimentos){
            if(i - it == 0 || (i - it > 0 && !resposta[i - it])){
                resposta[i] = true;
                break;
            }
        }
        if(resposta[i]) cout<<'W';
        else cout<<'L';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}

