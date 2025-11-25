#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, aux;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            aux = i+1;
            while(aux--){
                cout<<'(';
            }
            aux = i+1;
            while(aux--){
                cout<<')';
            }
            aux = n - (i+1);
            while(aux--){
                cout<<"()";
            }
            cout<<'\n';
        }
    }
    return 0;
}