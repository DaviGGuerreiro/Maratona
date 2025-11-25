#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll func(int j){
    ll resp=1;
    while(j--){
        resp = resp*10;
    }
    return resp;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    ll x;
    ll k;
    while(t--){
        ll y=9;
        k=1;
        int j = 1;
        cin>>x;
        while(y<x){
            j++;
            k = k * 10;
            y = y + (9 * k * j);
        }
        ll aux = y - x;
        ll aux1 = aux/j;
        int sobra = aux%j;
        ll lim = func(j)-1;

        y = lim - aux1;
        
        vector<int> x;
        ll resp = 0;
        ll left = y/10;
        ll right = 0;
        k=1;
        int elemento = 1;
        while(y>0){
            elemento = y%10;
            x.push_back(elemento);
            y /= 10;
        }
        //reverse(x.begin(), x.end());
        //cout<<x[0]<<x[1];
        for(int i=0;i<j;i++){
            ll pe = left*45*k;
            ll pm = (x[i]-1)*x[i]*k;
            ll pd = x[i]*(right+1);
            //cout<<"pe :"<<pe<<'\n'<<"pm: "<<pm<<'\n'<<"pd: "<<pd<<'\n';
            resp = resp + pe + pm/2 + pd;
            right = right + k*x[i];
            k = k*10;
            left = left/10;
        }
        
        for(int i=0;i<sobra;i++){
            resp = resp - x[i];
        }

        cout<<resp<<'\n';
    }

    return 0;
}