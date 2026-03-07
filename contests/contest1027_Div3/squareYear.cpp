#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    int n;
    int aux;
    while(t--){
        cin>>n;
        aux = sqrt(n);
        if(aux*aux == n){
            cout<<0<<" "<<aux<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }


    return 0;
}