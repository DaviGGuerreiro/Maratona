#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll aux;
    int t;
    int n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<ll> vec (n);
        vector<int> bits (31,0);
        ll maximo = 0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            for(int j = 0; j<31; j++){
                aux = 1<<j;
                if(vec[i] & aux){
                    bits[j]++;
                }
            }
        }
        for(int i=30;i >=0 ;i--){
            if(k >= (n-bits[i])){
                k -= n-bits[i];
                maximo += 1<<i;
            }
        }
        cout<<maximo<<'\n';
    }

    return 0;
}
