#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    ll resposta;
    cin>>t;
    while(t--){
        cin>>n;
        resposta = 0;
        vector<ll> vec (n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i = i+2){
            if(vec[i+1] - vec[i] > resposta){
                resposta = vec[i+1] - vec[i];
            }
        }
        cout<<resposta;
        cout<<'\n';
    }
    
    return 0;
}