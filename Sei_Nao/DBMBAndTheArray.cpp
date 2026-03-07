#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n, s, x;
    while(t--){
        cin>>n>>s>>x;
        int aux;
        int resp = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            resp += aux;
        }
        int r = resp - s;
        if(r>0 || r%x != 0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}