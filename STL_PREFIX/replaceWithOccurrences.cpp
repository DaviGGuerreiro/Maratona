#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t, n, aux;
    int i;
    cin>>t;
    while(t--){
        cin>>n;
        int soma = 0;
        map<int,int> mapa;
        map<int, int> num;
        vector<int> pos;
        for(i=0;i<n;i++){
            cin>>aux;
            pos.push_back(aux);
            mapa[aux]++;
            if(mapa[aux]%aux == 0){
                soma = soma + aux;
            }
        }
        if(soma == n){
            int j = 0;
            for(i=0;i<n;i++){
                if(mapa[pos[i]]%pos[i] == 0){
                    j++;
                    num[pos[i]] = j;
                }
                mapa[pos[i]]--;
                cout<<num[pos[i]]<<' ';
            }
            cout<<'\n';
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}