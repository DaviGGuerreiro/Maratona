#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, j, k, aux;
    int max;
    int num = 0;
    cin>>t;
    while(t--){
        cin>>n>>j>>k;
        max = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(max<aux){
                max = aux;
            }
            if(i+1 == j){
                num = aux;
            }
        }
        if(k >= 2){
            cout<<"YES\n";
        }
        else{
            if(num == max){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}