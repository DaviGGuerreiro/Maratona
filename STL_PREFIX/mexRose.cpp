#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, k, aux;
    int resposta;
    cin>>t;
    while(t--){
        cin>>n>>k;
        resposta = 0;
        int num = k;
        map<int, int> mapa;
        while(n--){
            cin>>aux;
            mapa[aux]++;
            if(aux < k && mapa[aux] == 1){
                num--;
            }
        }
        if(num - mapa[k] > 0){
            resposta = num;
        }
        else{
            resposta = mapa[k];
        }
        cout<<resposta<<'\n';
    }
    return 0;
}