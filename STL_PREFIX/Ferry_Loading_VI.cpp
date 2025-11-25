#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int c;
    cin>>c;
    int l,m;
    for(int i=0;i<c;i++){
        cin>>l>>m;
        l=l*100;
        int size;
        string sentido;
        int aux_d=0 ,aux_e=0;
        int e=0,d=0;
        for(int j=0;j<m;j++){
            cin>>size>>sentido;
            if(sentido == "left"){
                if(aux_e+size > l){
                    e++;
                    aux_e = size;
                }
                else{
                    aux_e = aux_e + size;
                }
            }
            else{
                if(aux_d+size > l){
                    d++;
                    aux_d = size;
                }
                else{
                    aux_d = aux_d + size;
                }
            }
        }

        if(aux_e>0){
            e++;
        }
        if(aux_d>0){
            d++;
        }

        e = 2*e -1;
        d = 2*d;
        if(e>d){
            cout<<e<<'\n';
        }
        else{
            cout<<d<<'\n';
        }
    }

    return 0;
}
