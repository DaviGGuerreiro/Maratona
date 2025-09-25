#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    ll a,b;
    ll aux;
    while(t--){
        cin>>a>>b;
        aux = a*b;
        if(aux%2 == 1){
            cout<<aux+1<<'\n';
        }
        else{
            if(a%2 == 0){
                if(b%2 == 0){
                    aux = aux/2;
                    cout<<aux+2<<'\n';
                }
                else{
                    cout<<"-1\n";
                }
            }
            else if(a%2 == 1){
                aux = aux/2;
                if(aux%2 == 0){
                    cout<<aux+2<<'\n';
                }
                else{
                    cout<<"-1\n";
                }
            }
        }
    }

    return 0;
}