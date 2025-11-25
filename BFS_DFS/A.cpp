#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    int a;
    int r, aux;
    int menos;
    cin>>t;
    while(t--){
        cin>>a;
        r=0;
        menos = 0;
        for(int i=0;i<a;i++){
            cin>>aux;
            if(aux == 0){
                r++;
            }
            if(aux == -1){
                menos++;
            }
        }
        if(menos%2 == 1){
            r = r + 2;
        }
        cout<<r<<'\n';
    }
    
    return 0;
}