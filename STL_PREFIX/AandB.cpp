#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n;
    int z, u;
    int resp1, resp2;
    int quantidade1, quantidade2;
    char aux;
    char verif;
    cin>>t;
    while(t--){
        cin>>n;
        queue<ll> fila;
        z = 0; u=0 ; resp1 = 0; resp2 = 0;
        quantidade1 = 0;
        quantidade2 = 0;
        for(int i=0;i<n;i++){
            cin>>aux;
            if(aux == 'a'){
                if(u != 0){
                    fila.push(u);
                    u = 0;
                }
                quantidade1++;
                z++;
            }
            else{
                if(z != 0){
                    fila.push(z);
                    z = 0;
                }
                quantidade2++;
                u++;
            }
            if(i == 0){
                verif = aux;
            }
        }
        if(verif != 'a'){
            swap(quantidade1,quantidade2);
        }

        if(z != 0){
            fila.push(z);
            z = 0;
        }
        else{
            fila.push(u);
            u = 0;
        }

        if(fila.size()<=3){
            cout<<0<<'\n';
        }
        else{
            ll a=0, b=0, c = 0, d=0;
            int aux2 = fila.size();
            for(int i=0;i<aux2;i++){
                if(i%2 == 0){
                    if(resp1 > quantidade1 - resp1){
                        a = a + fila.front() * c;
                        resp1 = resp1 + fila.front();
                        fila.pop();
                        if(!fila.empty()){
                            c = fila.front() + c;
                        }
                    }
                    else{
                        a = a + resp1 * c;
                        resp1 = resp1 + fila.front();
                        fila.pop();
                        if(!fila.empty()){
                            c = fila.front();
                        }
                    }
                }
                else{
                    if(resp2 > quantidade2 - resp2){
                        b = b + fila.front() * d;
                        resp2 = resp2 + fila.front();
                        fila.pop();
                        if(!fila.empty()){
                            d = fila.front() + d;
                        }
                    }
                    else{
                        b = b + resp2 * d;
                        resp2 = resp2 + fila.front();
                        fila.pop();
                        if(!fila.empty()){
                            d = fila.front();
                        }
                    }
                }
            }
            if(a > b){
                cout<<b<<'\n';
            }
            else{
                cout<<a<<'\n';
            }
        }
    }
    return 0;
}
