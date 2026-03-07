#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int k, x;
    while(t--){
        cin>>k>>x;
        int resposta = k*x;
        resposta++;
        cout<<resposta<<'\n';
    }

    return 0;
}