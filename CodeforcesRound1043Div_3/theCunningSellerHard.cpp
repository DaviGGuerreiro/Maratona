#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    ios::sync_with_stdio(false);cin.tie(0);
    int t, x, y;
    cin>>t;
    while(t--){
        cin>>x;
        cin>>y;
        int e=1;
        ll aux = 1;
        int quantidade=x;
        ll moedas=0;
        vector<ll> tri;
        while(x!=0 && y>=0){
            if(x >= aux*3){
                aux = aux*3;
                e++;
            }
            else{
                quantidade = x/aux;
                tri.push_back(quantidade);
                e--;
                y = y - quantidade;
                x = x - quantidade*aux;
                aux = aux/3;
            }
        }
        if(y<0){
            cout<<-1<<'\n';
        }
        else{

            while(e--){
                tri.push_back(0);
            }

            int tamanho = tri.size();

            int i=0;
            while(y > 1 && i < tamanho-1){
                if(y>=2*tri[i]){
                    y = y - 2*tri[i];
                    tri[i+1] = tri[i+1] + 3*tri[i];
                    tri[i] = 0;
                }
                else{
                    tri[i] = tri[i] - y/2;
                    tri[i+1] = tri[i+1] + (y/2)*3;
                    y = 0;
                }
                i++;
            }

            int j=0;
            while(j < tamanho){
                moedas = moedas + tri[j]*(pow(3, tamanho-2-j)*(9 + tamanho-j-1));
                j++;
            }
            cout<<moedas<<'\n';
        }
    }

    return 0;
}