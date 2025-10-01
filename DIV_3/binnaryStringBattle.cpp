#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k;
    int uns;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>k;
        string aux;
        cin>>aux;
        uns = 0;
        for(int i=0;i<n;i++){
            if(aux[i] == '1'){
                uns++;
            }
        }
        if(k >= uns || 2*k > n){
            cout<<"Alice\n";
        } 
        else{
            cout<<"Bob\n";
        }
    }
    return 0;
}