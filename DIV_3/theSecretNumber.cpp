#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        int k = 1, r=0;
        ll aux = 11;
        vector<ll> valores;
        while(n >= aux && k<19){
            if(n % aux == 0){
                valores.push_back(n/aux);
                r++;
            }
            k++;
            aux = 1;
            for(int i=0; i<k; i++) aux *= 10;
            aux += 1;
        }
        cout<<r<<'\n';
        if(r!=0){
            while(!valores.empty()){
                cout<<valores.back()<<' ';
                valores.pop_back();
            }
            cout<<'\n';
        }
    }


    return 0;
}