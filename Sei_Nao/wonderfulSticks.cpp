#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n;

void solve(){
    cin>>n; string s; cin>>s;
    vector<int> resposta(n+1);
    int l = 1;
    int r = n;
    for(int i = n; i > 1; i--){
        if(s[i-2] == '<'){
            resposta[i] = l;
            l++;
        }
        else{
            resposta[i] = r;
            r--;
        }
    }
    resposta[1] = r;
    for(int i = 1; i <= n; i++){
        cout<<resposta[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>t;
    while(t--) solve();
    return 0;
}